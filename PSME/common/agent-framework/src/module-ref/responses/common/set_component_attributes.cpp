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
 * @file responses/common/set_component_attributes.hpp
 * @brief SetComponentAttributes response
 * */

#include "agent-framework/module-ref/responses/common/set_component_attributes.hpp"
#include <json/json.h>

using namespace agent_framework::model::responses;

Json::Value SetComponentAttributes::to_json() const {
    return Json::Value();
}

SetComponentAttributes SetComponentAttributes::from_json(const Json::Value&) {
    return SetComponentAttributes{};
}
