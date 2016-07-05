/*!
 * @copyright
 * Copyright (c) 2016 Intel Corporation
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
 * @file requests/network/delete_acl_port.hpp
 * @brief network DeleteAclPort request
 * */

#pragma once

#include "agent-framework/module-ref/model/attributes/oem.hpp"
#include "agent-framework/module-ref/model/attributes/array.hpp"
#include "agent-framework/module-ref/enum/network.hpp"
#include "agent-framework/module-ref/constants/command.hpp"
#include "agent-framework/module-ref/constants/network.hpp"
#include "agent-framework/module-ref/utils/optional_field.hpp"
#include "agent-framework/validators/procedure_validator.hpp"

#include <string>

namespace Json {
    class Value;
}

namespace agent_framework {
namespace model {
namespace requests {

/*! network DeleteAclPort request */
class DeleteAclPort {
public:
    using Ports = agent_framework::model::attribute::Array<std::string>;
    using Oem = agent_framework::model::attribute::Oem;

    /*!
     * @brief explicit DeleteAclPort request constructor
     *
     * @param[in] acl ACL identifier
     * @param[in] ports Ports
     * @param[in] oem OEM specific data
     * */
    explicit DeleteAclPort(const std::string& acl,
                           const Ports& ports,
                           const Oem& oem = Oem{});

    /*!
     * @brief Get command name
     *
     * @return Command name
     * */
    static std::string get_command() {
        return literals::Command::DELETE_ACL_PORT;
    }

    /*!
     * @brief Get acl UUID
     *
     * @return UUID as std::string
     * */
    const OptionalField<std::string>& get_acl() const {
        return m_acl;
    }

    /*!
     * @brief Get ports
     *
     * @return vector of ports UUIDs as std::string
     * */
    const Ports& get_ports() const {
        return m_ports;
    }

    /*!
     * @brief Get OEM data
     *
     * @return OEM data
     */
    const Oem& get_oem() const {
        return m_oem;
    }

    /*!
     * @brief Transform request to Json
     *
     * @return created Json value
     */
    Json::Value to_json() const;

    /*!
     * @brief create DeleteAclPort from Json
     *
     * @param[in] json the input argument
     *
     * @return new DeleteAclPort
     */
    static DeleteAclPort from_json(const Json::Value& json);

    /*!
     * @brief Return procedure schema
     *
     * @return procedure schema
     */
    static const jsonrpc::ProcedureValidator& get_procedure() {
        static const jsonrpc::ProcedureValidator procedure{
            get_command(), jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT,
            literals::Acl::ACL, jsonrpc::JSON_STRING,
            literals::Acl::PORTS, jsonrpc::JSON_ARRAY,
            literals::Acl::OEM, jsonrpc::JSON_OBJECT,
            nullptr
        };
        return procedure;
    }

private:
    OptionalField<std::string> m_acl{};
    Ports m_ports{};
    Oem m_oem{};
};

}
}
}

