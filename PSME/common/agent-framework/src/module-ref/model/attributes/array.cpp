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
 * @file command/collection.cpp
 *
 * @brief Arrays specific data
 * */

#include "agent-framework/module-ref/model/attributes/collection.hpp"
#include "agent-framework/module-ref/model/attributes/target_lun.hpp"
#include "agent-framework/module-ref/model/attributes/network_service.hpp"
#include "agent-framework/module-ref/model/attributes/ipv4_address.hpp"
#include "agent-framework/module-ref/model/attributes/ipv6_address.hpp"
#include "agent-framework/module-ref/model/attributes/pci_device.hpp"
#include "agent-framework/module-ref/model/attributes/usb_device.hpp"
#include "agent-framework/module-ref/model/attributes/subcomponent_entry.hpp"
#include "agent-framework/module-ref/model/attributes/manager_entry.hpp"
#include "agent-framework/module-ref/model/attributes/interleave_set.hpp"
#include "agent-framework/module-ref/model/attributes/region.hpp"
#include "agent-framework/module-ref/enum/compute.hpp"

#include "agent-framework/module-ref/utils/is_framework_enum.hpp"
#include "agent-framework/module-ref/utils/is_framework_object.hpp"
#include "agent-framework/module-ref/model/attributes/array.hpp"
#include "agent-framework/module-ref/constants/common.hpp"
#include <json/json.h>
#include <cassert>

using namespace agent_framework::model::attribute;
using namespace agent_framework::model;

namespace {

    template <typename T>
    using is_f_enum = utils::is_framework_enum<T>;

    template <typename T>
    using is_f_obj = utils::is_framework_object<T>;

    // empty template if neither framework enum or object
    template <typename T, typename std::enable_if<(!is_f_obj<T>::value) && (!is_f_enum<T>::value)>::type* = nullptr>
    void append_to_json(Json::Value&, const T&) {
        // this should not be used, provide proper specialization instead
        assert(false);
    }

    // append framework enum to json
    template <typename T, typename std::enable_if<is_f_enum<T>::value>::type* = nullptr>
    void append_to_json(Json::Value& json, const T& entry) {
        json.append(entry.to_string());
    }

    // append framework object to json
    template <typename T, typename std::enable_if<is_f_obj<T>::value>::type* = nullptr>
    void append_to_json(Json::Value& json, const T& entry) {
        json.append(entry.to_json());
    }

    // append string to json
    template <>
    void append_to_json<std::string>(Json::Value& json, const std::string& entry) {
        json.append(entry);
    }

    // append double to json
    template <>
    void append_to_json<double>(Json::Value& json, const double& entry) {
        json.append(entry);
    }

    // append uint32_t to json
    template <>
    void append_to_json<std::uint32_t>(Json::Value& json, const std::uint32_t& entry) {
        json.append(entry);
    }

    // empty template if neither framework enum or object
    template <typename T, typename std::enable_if<(!is_f_obj<T>::value) && (!is_f_enum<T>::value)>::type* = nullptr>
    void append_to_array(Array<T>&, const Json::Value&) {
        // this should not be used, provide proper specialization instead
        assert(false);
    }

    // append framework enum from json
    template <typename T, typename std::enable_if<is_f_enum<T>::value>::type* = nullptr>
    void append_to_array(Array<T>& array, const Json::Value& json) {
        array.add_entry(T::from_string(json.asString()));
    }

    // append framework object from json
    template <typename T, typename std::enable_if<is_f_obj<T>::value>::type* = nullptr>
    void append_to_array(Array<T>& array, const Json::Value& json) {
        array.add_entry(T::from_json(json));
    }

    // append string from json
    template <>
    void append_to_array<std::string>(Array<std::string>& array,
            const Json::Value& json) {
        array.add_entry(json.asString());
    }

    // append double from json
    template <>
    void append_to_array<double>(Array<double>& array,
            const Json::Value& json) {
        array.add_entry(json.asDouble());
    }

    // append uint32_t from json
    template <>
    void append_to_array<std::uint32_t>(Array<std::uint32_t>& array,
            const Json::Value& json) {
        array.add_entry(json.asUInt());
    }

}

template <typename T>
Array<T>::Array() { }

template <typename T>
Array<T>::~Array() { }

template <typename T>
Array<T> Array<T>::from_json(const Json::Value& json) {
    Array<T> array;
    for (const auto& val : json) {
        ::append_to_array(array, val);
    }
    return array;
}

template <typename T>
Json::Value Array<T>::to_json() const {
    Json::Value json{Json::arrayValue};
    for (const auto& entry : *this) {
        ::append_to_json(json, entry);
    }
    return json;
}

namespace agent_framework {
namespace model {
namespace attribute {

template class Array<std::string>;
template class Array<std::uint32_t>;
template class Array<double>;

template class Array<Collection>;
template class Array<TargetLun>;
template class Array<NetworkService>;
template class Array<Ipv4Address>;
template class Array<Ipv6Address>;
template class Array<PciDevice>;
template class Array<UsbDevice>;
template class Array<SubcomponentEntry>;
template class Array<ManagerEntry>;
template class Array<InterleaveSet>;
template class Array<Region>;

template class Array<enums::GraphicalConsoleSupprtedType>;
template class Array<enums::SerialConsoleSupprtedType>;
template class Array<enums::CommandShellSupprtedType>;

template class Array<enums::BootOverrideSupported>;
template class Array<enums::DimmType>;
template class Array<enums::DimmMedia>;
template class Array<enums::DimmModuleType>;
template class Array<enums::MemoryType>;
template class Array<enums::MemoryMode>;
template class Array<enums::MemoryClass>;

}
}
}
