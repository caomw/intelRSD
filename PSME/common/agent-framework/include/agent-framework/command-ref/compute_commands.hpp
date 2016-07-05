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
 *
 * @file compute_commands.cpp
 *
 * @brief Declarations of all compute commands
 * */

#pragma once
#include "agent-framework/command-ref/command.hpp"
#include "agent-framework/module/model/model_compute.hpp"
#include "agent-framework/module/requests/common.hpp"
#include "agent-framework/module/requests/compute.hpp"
#include "agent-framework/module/responses/common.hpp"

namespace agent_framework {
namespace command_ref {

// declarations of get collection methods
using GetCollection = Command<model::requests::GetCollection, model::attribute::Array<model::attribute::SubcomponentEntry>>;
using GetManagerCollection = Command<model::requests::GetManagerCollection, model::attribute::Array<model::attribute::ManagerEntry>>;

// declarations of all get info methods
using GetChassisInfo = Command<model::requests::GetChassisInfo, model::Chassis>;
using GetDimmInfo = Command<model::requests::GetDimmInfo, model::Dimm>;
using GetDriveInfo = Command<model::requests::GetDriveInfo, model::Drive>;
using GetManagerInfo = Command<model::requests::GetManagerInfo, model::Manager>;
using GetMemoryChunkInfo = Command<model::requests::GetMemoryChunkInfo, model::MemoryChunk>;
using GetNetworkInterfaceInfo = Command<model::requests::GetNetworkInterfaceInfo, model::NetworkInterface>;
using GetProcessorInfo = Command<model::requests::GetProcessorInfo, model::Processor>;
using GetStorageControllerInfo = Command<model::requests::GetStorageControllerInfo, model::StorageController>;
using GetSystemInfo = Command<model::requests::GetSystemInfo, model::System>;

// declarations of all set methods
using SetComponentAttributes = Command<model::requests::SetComponentAttributes, model::responses::SetComponentAttributes>;

}
}

