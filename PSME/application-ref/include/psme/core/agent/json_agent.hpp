/*!
 * @copyright
 * Copyright (c) 2015-2016 Intel Corporation
 *
 * @copyright
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * @copyright
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * @copyright
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * */

#ifndef PSME_CORE_AGENT_JSON_AGENT_HPP
#define PSME_CORE_AGENT_JSON_AGENT_HPP

#include "agent.hpp"
#include "agent_unreachable.hpp"
#include "rpc_client.hpp"
#include "agent-framework/module-ref/utils/optional/optional-lib/optional.hpp"
#include "logger/logger_factory.hpp"
#include <jsonrpccpp/client.h>
#include <memory>
#include <mutex>

/*! Forward declaration */
class RegisterAgent;

namespace psme {
namespace core {
namespace agent {

class JsonAgent : public Agent {
public:
    static const unsigned REMOVE_AGENT_AFTER_SECONDS = 60;
    JsonAgent(const std::string& gami_id,
              const std::string& ipv4address,
              const int port);

    template <typename Response, typename Request>
    Response execute(const Request& req) {
        std::lock_guard<std::mutex> lock(m_mutex);
        try {
            auto res = m_client.CallMethod(Request::get_command(),
                                           req.to_json());
            m_connection_error_observed_at = std::experimental::nullopt;

            return Response::from_json(res);
        } catch (const jsonrpc::JsonRpcException& e) {
            if (jsonrpc::Errors::ERROR_CLIENT_CONNECTOR == e.GetCode()) {
                auto now = std::chrono::high_resolution_clock::now();
                if (m_connection_error_observed_at) {
                    auto broken_seconds = std::chrono::duration_cast<std::chrono::seconds>(now - m_connection_error_observed_at.value()).count();
                    log_error(GET_LOGGER("rest"), "Agent " << get_gami_id() << " has not responded for " << broken_seconds << " seconds.");
                    if (broken_seconds >= JsonAgent::REMOVE_AGENT_AFTER_SECONDS) {
                        clean_resource_for_agent();
                        unregister_agent();
                    }
                }
                else {
                    m_connection_error_observed_at = now;
                }

                throw AgentUnreachable(get_gami_id());
            }
            m_connection_error_observed_at = std::experimental::nullopt;
            throw;
        }
    }

    /*!
     * @brief  Method unregisters agent from agent manager
     */
    void unregister_agent();

    ~JsonAgent();

private:
    /*!
     * @brief Method clears all resources that came from this agent.
     */
    void clean_resource_for_agent();

    /*!
     * @brief sends events to clients that managers from unresponsive agent ware removed
     */
    void notify_clients_about_removals();

    friend class ::RegisterAgent;
    /*!
     * @brief Create connection URL from IPv4 address and port
     *
     * @param ipv4address agent IPv4 address
     * @param port agent port
     *
     * @return  Connection URL
     */
    std::string make_connection_url(const std::string& ipv4address,
                                                        const int port) const;
    std::experimental::optional<std::chrono::time_point<std::chrono::system_clock>> m_connection_error_observed_at {};
    std::unique_ptr<jsonrpc::IClientConnector> m_client_connector;
    RpcClient m_client;
    std::mutex m_mutex {};
};

using JsonAgentSPtr = std::shared_ptr<JsonAgent>;

}
}
}
#endif /* PSME_CORE_AGENT_JSON_AGENT_HPP */
