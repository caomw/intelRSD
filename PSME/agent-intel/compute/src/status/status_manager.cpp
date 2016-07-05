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
 * */

#include "status/module_hardware_status.hpp"
#include "status/module_software_status.hpp"
#include "status/status_manager.hpp"

using namespace agent::compute::status;

StatusManager::StatusManager(const std::uint32_t slot, const std::string& ip) :
    m_slot{slot},
    m_ip_address{ip}
{}

StatusManager::~StatusManager(){}

ModuleStatus::Status StatusManager::get_hw_status() {
    ModuleHardwareStatus hw_status {m_slot};
    try {
        return hw_status.read_status();
    }
    catch (...) {
        return ModuleStatus::Status::UNKNOWN;
    }
}

ModuleStatus::Status StatusManager::get_sw_status() {
    ModuleSoftwareStatus sw_status {m_ip_address};
    try {
        return sw_status.read_status();
    }
    catch (...) {
        return ModuleStatus::Status::UNKNOWN;
    }
}

