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
 * @file command/network/json/get_port_vlan_info.cpp
 * @brief JSON command get port vlan information implementation
 * */

#include "agent-framework/command/network/json/get_port_vlan_info.hpp"
#include "agent-framework/module-ref/constants/network.hpp"

using namespace agent_framework::command;
using namespace agent_framework::command::network::json;
using namespace agent_framework::model::literals;

GetPortVlanInfo::GetPortVlanInfo() :
    CommandJson(Procedure(TAG,
                jsonrpc::PARAMS_BY_NAME,
                jsonrpc::JSON_OBJECT,
                PortVlan::PORT_VLAN, jsonrpc::JSON_STRING,
                nullptr)) { }

void GetPortVlanInfo::method(const Json::Value& params, Json::Value& result) {
    Command* command = get_command();

    network::GetPortVlanInfo::Request request{};
    network::GetPortVlanInfo::Response response{};

    request.m_port_vlan = params[PortVlan::PORT_VLAN].asString();

    command->execute(request, response);

    result = response.m_port_vlan.to_json();
}

void GetPortVlanInfo::notification(const Json::Value&) { }

static CommandJson::Register<GetPortVlanInfo> g;
