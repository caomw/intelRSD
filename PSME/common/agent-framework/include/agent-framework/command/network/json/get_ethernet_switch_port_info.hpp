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
 *
 *
 * @file command/network/json/get_ethernet_switch_port_info.hpp
 * @brief Declaration of JSON GetEthernetSwitchPortInfo command interface.
 * */

#ifndef AGENT_FRAMEWORK_COMMAND_NETWORK_JSON_GET_ETHERNET_SWITCH_PORT_INFO_HPP
#define AGENT_FRAMEWORK_COMMAND_NETWORK_JSON_GET_ETHERNET_SWITCH_PORT_INFO_HPP

#include "agent-framework/command/command_json.hpp"
#include "agent-framework/command/network/get_ethernet_switch_port_info.hpp"

namespace agent_framework {
namespace command {
namespace network {
namespace json {

using agent_framework::command::CommandJson;

/*! @brief JSON GetEthernetSwitchPortInfo command class */
class GetEthernetSwitchPortInfo : public CommandJson {
public:
    /*! @brief Agent name tag */
    static constexpr const char* AGENT =
        network::GetEthernetSwitchPortInfo::AGENT;

    /*! @brief Command name tag */
    static constexpr const char* TAG = network::GetEthernetSwitchPortInfo::TAG;

    /*!
     * @brief Create JSON command
     * */
    GetEthernetSwitchPortInfo();

    /*!
     * @brief JSON RPC method
     *
     * @param[in] params JSON RPC params request
     * @param[out] result JSON RPC result response
     * */
    void method(const Json::Value& params, Json::Value& result) final override;

    /*!
     * @brief JSON RPC notification
     *
     * @param[in] params JSON RPC params request
     * */
    void notification(const Json::Value& params) final override;
};

} /* namespace json */
} /* namespace network */
} /* namespace command */
} /* namespace agent_framework */

#endif
/* AGENT_FRAMEWORK_COMMAND_NETWORK_JSON_GET_ETHERNET_SWITCH_PORT_INFO_HPP */
