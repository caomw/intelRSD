/*!
 * @section LICENSE
 *
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
 * @section DESCRIPTION
 *
 * @file network_commands.cpp
 *
 * @brief Declarations of all network commands
 * */

#pragma once
#include "agent-framework/module-ref/requests/common.hpp"
#include "agent-framework/module-ref/requests/network.hpp"
#include "agent-framework/module-ref/responses/common.hpp"
#include "agent-framework/module-ref/responses/network.hpp"

namespace agent_framework {
namespace command_ref {

// declarations of get collection methods
using GetCollection = Command<model::requests::GetCollection, model::attribute::Array<model::attribute::SubcomponentEntry>>;
using GetManagerCollection = Command<model::requests::GetManagerCollection, model::attribute::Array<model::attribute::ManagerEntry>>;

// declarations of all get info methods
using GetChassisInfo = Command<model::requests::GetChassisInfo, model::Chassis>;
using GetEthernetSwitchInfo = Command<model::requests::GetEthernetSwitchInfo, model::Switch>;
using GetEthernetSwitchPortInfo = Command<model::requests::GetEthernetSwitchPortInfo, model::SwitchPort>;
using GetManagerInfo = Command<model::requests::GetManagerInfo, model::Manager>;
using GetPortVlanInfo = Command<model::requests::GetPortVlanInfo, model::PortVlan>;
using GetPortStaticMacInfo = Command<model::requests::GetPortStaticMacInfo, model::StaticMac>;
using GetRemoteEthernetSwitchInfo = Command<model::requests::GetRemoteEthernetSwitchInfo, model::RemoteSwitch>;
using GetAclInfo = Command<model::requests::GetAclInfo, model::Acl>;
using GetAclRuleInfo = Command<model::requests::GetAclRuleInfo, model::AclRule>;
using GetVlanInfo = Command<model::requests::GetVlanInfo, model::Vlan>;

// declarations of all set methods
using SetComponentAttributes = Command<model::requests::SetComponentAttributes, model::responses::SetComponentAttributes>;

// declarations of all add methods
using AddPortVlan = Command<model::requests::AddPortVlan, model::responses::AddPortVlan>;
using AddAcl = Command<model::requests::AddAcl, model::responses::AddAcl>;
using AddEthernetSwitchPort = Command<model::requests::AddEthernetSwitchPort, model::responses::AddEthernetSwitchPort>;
using AddEthernetSwitchPortMembers = Command<model::requests::AddEthernetSwitchPortMembers, model::responses::AddEthernetSwitchPortMembers>;
using AddAclRule = Command<model::requests::AddAclRule, model::responses::AddAclRule>;
using AddAclPort = Command<model::requests::AddAclPort, model::responses::AddAclPort>;
using AddPortStaticMac = Command<model::requests::AddPortStaticMac, model::responses::AddPortStaticMac>;

// declarations of all delete methods
using DeleteAcl = Command<model::requests::DeleteAcl, model::responses::DeleteAcl>;
using DeleteEthernetSwitchPort = Command<model::requests::DeleteEthernetSwitchPort, model::responses::DeleteEthernetSwitchPort>;
using DeleteEthernetSwitchPortMembers = Command<model::requests::DeleteEthernetSwitchPortMembers, model::responses::DeleteEthernetSwitchPortMembers>;
using DeletePortVlan = Command<model::requests::DeletePortVlan, model::responses::DeletePortVlan>;
using DeleteAclRule = Command<model::requests::DeleteAclRule, model::responses::DeleteAclRule>;
using DeleteAclPort = Command<model::requests::DeleteAclPort, model::responses::DeleteAclPort>;
using DeletePortStaticMac = Command<model::requests::DeletePortStaticMac, model::responses::DeletePortStaticMac>;

}
}

