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
    void delete_acl_rule(const DeleteAclRule::Request& request,
                      DeleteAclRule::Response&) {
        using NetworkManager = agent_framework::module::NetworkManager;

        if (NetworkManager::get_instance()->
            get_acl_rule_manager().entry_exists(request.get_rule())) {
            log_info(GET_LOGGER("network-agent"), "Deleting ACL Rule: " << request.get_rule());
            NetworkManager::get_instance()->get_acl_rule_manager().remove_entry(request.get_rule());
        }
        else {
            THROW(::agent_framework::exceptions::InvalidUuid,
                    "network-agent", "No ACL Rule with uuid: " + request.get_rule());
        }
    }
}

REGISTER_COMMAND(DeleteAclRule, ::delete_acl_rule);
