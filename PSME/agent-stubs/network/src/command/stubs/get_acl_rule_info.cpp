/*!
 * @section LICENSE
 *
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
 * @section DESCRIPTION
 * */

#include "agent-framework/module-ref/network_manager.hpp"
#include "agent-framework/command-ref/registry.hpp"
#include "agent-framework/command-ref/network_commands.hpp"

using namespace agent_framework::model;
using namespace agent_framework::command_ref;

namespace {
    void get_acl_rule_info(const GetAclRuleInfo::Request& request,
                      GetAclRuleInfo::Response& response) {
        response = agent_framework::module::NetworkManager::get_instance()->
            get_acl_rule_manager().get_entry(request.get_uuid());
    }
}

REGISTER_COMMAND(GetAclRuleInfo, ::get_acl_rule_info);
