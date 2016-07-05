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
 * @file requests/common/get_collection.hpp
 * @brief common GetCollection request
 * */

#ifndef AGENT_FRAMEWORK_MODEL_REQUESTS_COMMON_GET_COLLECTION_HPP
#define AGENT_FRAMEWORK_MODEL_REQUESTS_COMMON_GET_COLLECTION_HPP

#include <string>

namespace Json {
    class Value;
}

namespace agent_framework {
namespace model {
namespace requests {

/*! GetCollection request*/
class GetCollection {
public:
    explicit GetCollection(const std::string& component,
            const std::string& name);

    static std::string get_command() {
        return "getCollection";
    }
    /*!
     * @brief Get component UUID
     * @return Component UUID
     * */
    const std::string& get_uuid() const {
        return m_component;
    }

    /*!
     * @brief Get collection name
     * @return Collection name
     * */
    const std::string& get_name() const {
        return m_name;
    }

    /*!
     * @brief Transform request to Json
     *
     * @return created Json value
     */
    Json::Value to_json() const;

    /*!
     * @brief create GetCollection form Json
     *
     * @param[in] json the input argument
     *
     * @return new GetCollection
     */
    static GetCollection from_json(const Json::Value& json);

private:
        std::string m_component{};
        std::string m_name{};
};

}
}
}

#endif /* AGENT_FRAMEWORK_MODEL_REQUESTS_COMMON_GET_COLLECTION_HPP */
