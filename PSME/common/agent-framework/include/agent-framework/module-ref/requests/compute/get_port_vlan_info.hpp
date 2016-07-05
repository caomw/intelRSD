/*!
 * Copyright (c) 2015-2016 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file requests/compute/get_port_vlan_info.hpp
 * @brief Compute GetPortVlanInfo request
 * */

#ifndef AGENT_FRAMEWORK_MODEL_REQUESTS_COMPUTE_GET_PORT_VLAN_INFO_HPP
#define AGENT_FRAMEWORK_MODEL_REQUESTS_COMPUTE_GET_PORT_VLAN_INFO_HPP

#include <string>

namespace Json {
    class Value;
}

namespace agent_framework {
namespace model {
namespace requests {

/*! Generic compute command GetPortVlanInfo */
class GetPortVlanInfo {
public:
    explicit GetPortVlanInfo(const std::string& port_vlan);

    static std::string get_command() {
        return "getPortVlanInfo";
    }

    /*!
     * @brief Get port vlan uuid
     * @return Port vlan uuid
     * */
    const std::string& get_port_vlan() const {
        return m_port_vlan;
    }

    /*!
     * @brief Transform request to Json
     *
     * @return created Json value
     */
    Json::Value to_json() const;

    /*!
     * @brief create GetPortVlanInfo from Json
     *
     * @param[in] json the input argument
     *
     * @return new GetPortVlanInfo
     */
    static GetPortVlanInfo from_json(const Json::Value& json);

private:
    std::string m_port_vlan{};
};

}
}
}

#endif /* AGENT_FRAMEWORK_MODEL_REQUESTS_COMPUTE_GET_PORT_VLAN_INFO_HPP */
