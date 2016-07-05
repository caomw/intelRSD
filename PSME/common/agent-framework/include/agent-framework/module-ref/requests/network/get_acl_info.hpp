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
 * @file requests/network/get_acl_info.hpp
 * @brief network GetAclInfo request
 * */

#pragma once

#include "agent-framework/module-ref/constants/network.hpp"
#include "agent-framework/module-ref/constants/command.hpp"
#include "agent-framework/validators/procedure_validator.hpp"

#include <string>

namespace Json {
    class Value;
}

namespace agent_framework {
namespace model {
namespace requests {

/*! network GetAclInfo request */
class GetAclInfo{
public:
    /*!
     * @brief explicit GetAclInfo request constructor
     *
     * @param[in] acl ACL identifier
     * */
    explicit GetAclInfo(const std::string& acl);

    /*!
     * @brief Get command name
     *
     * @return Command name
     * */
    static std::string get_command() {
        return literals::Command::GET_ACL_INFO;
    }

    /*!
     * @brief Get ACL UUID
     *
     * @return UUID as std::string
     * */
    const std::string& get_uuid() const {
        return m_acl;
    }

    /*!
     * @brief Transform request to Json
     *
     * @return created Json value
     */
    Json::Value to_json() const;

    /*!
     * @brief create GetAclInfo from Json
     *
     * @param[in] json the input argument
     *
     * @return new GetAclInfo
     */
    static GetAclInfo from_json(const Json::Value& json);

    /*!
     * @brief Return procedure schema
     *
     * @return procedure schema
     */
    static const jsonrpc::ProcedureValidator& get_procedure() {
        static const jsonrpc::ProcedureValidator procedure{
            get_command(), jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT,
            literals::Acl::ACL, jsonrpc::JSON_STRING,
            nullptr
        };
        return procedure;
    }

private:
    std::string m_acl{};
};

}
}
}
