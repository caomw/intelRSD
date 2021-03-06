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
 *
 *
 * @file requests/common/set_component_attributes.hpp
 * @brief Implementation of SetComponentAttributes request
 * */

#include "agent-framework/module-ref/requests/common/set_component_attributes.hpp"
#include "agent-framework/module-ref/constants/common.hpp"
#include <json/json.h>

using namespace agent_framework::model::requests;
using namespace agent_framework::model::literals;

SetComponentAttributes::SetComponentAttributes(const std::string& component,
            agent_framework::model::attribute::Attributes attributes):
        m_component{component},
        m_attributes{attributes} {}

Json::Value SetComponentAttributes::to_json() const {
    Json::Value value;
    value[Component::COMPONENT] = m_component;
    value[Component::ATTRIBUTES] = m_attributes.to_json();
    return value;
}

SetComponentAttributes SetComponentAttributes::from_json(const Json::Value& json) {
    return SetComponentAttributes{
        json[Component::COMPONENT].asString(),
        agent_framework::model::attribute::Attributes::from_json(json[Component::ATTRIBUTES])
    };
}
