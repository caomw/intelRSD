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

#include "agent-framework/command/compute/get_manager_info.hpp"
#include "agent-framework/module-ref/compute_manager.hpp"
#include "agent-framework/exceptions/exception.hpp"

using namespace agent_framework::module;
using namespace agent_framework::command;

namespace agent {
/*! Simulator GetManagerInfo implementation */
class GetManagerInfo : public compute::GetManagerInfo {
public:
    GetManagerInfo() { }

    using compute::GetManagerInfo::execute;
    using ComputeComponents = agent_framework::module::ComputeManager;

    void execute(const Request& request, Response& response) {
        log_debug(GET_LOGGER("agent"), "Getting manager info.");
        auto manager = ComputeComponents::get_instance()->
                                    get_module_manager().get_entry(
                                            request.get_component());
        process_collections(manager);
        response.set_manager(manager);
    }
    ~GetManagerInfo();
private:
    void process_collections(Manager& manager) {
        if (ComputeComponents::get_instance()->
                get_system_manager().get_entry_count(manager.get_uuid())) {
            manager.add_collection(attribute::Collection(enums::CollectionName::Systems,
                    enums::CollectionType::Systems, ""));
        }
        if (ComputeComponents::get_instance()->
                get_module_manager().get_entry_count(manager.get_uuid())) {
            manager.add_collection(attribute::Collection(enums::CollectionName::Managers,
                    enums::CollectionType::Managers,""));
        }
        if (ComputeComponents::get_instance()->
                get_chassis_manager().get_entry_count(manager.get_uuid())) {
            manager.add_collection(attribute::Collection(enums::CollectionName::Chassis,
                        enums::CollectionType::Chassis,""));
        }
    }
};

GetManagerInfo::~GetManagerInfo() { }
}
static Command::Register<agent::GetManagerInfo> g("Simulator");
