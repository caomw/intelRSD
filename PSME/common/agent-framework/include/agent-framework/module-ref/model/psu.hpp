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
 * @brief PSU
 * */

#ifndef AGENT_FRAMEWORK_MODULE_MODEL_PSU_HPP
#define AGENT_FRAMEWORK_MODULE_MODEL_PSU_HPP

#include "agent-framework/module-ref/model/attributes/model_attributes.hpp"
#include "agent-framework/module-ref/model/resource.hpp"
#include "agent-framework/module-ref/enum/common.hpp"

/*! Psme namespace */
namespace agent_framework {
/*! Generic namespace */
namespace model {

/*! Thermal zone class */
class Psu : public Resource {
public:

    explicit Psu(const std::string& parent_uuid = {});
    ~Psu();

    Psu(const Psu&) = default;
    Psu& operator=(const Psu&) = default;
    Psu(Psu&&) = default;
    Psu& operator=(Psu&&) = default;

    /*!
     * @brief construct an object of class Psu from JSON
     *
     * @param json the Json::Value deserialized to object
     *
     * @return the newly constructed Psu object
     */
    static Psu from_json(const Json::Value& json);

    /*!
     * @brief transform the object to JSon
     *
     * @return the object serialized to Json::Value
     */
    Json::Value to_json() const;

    static enums::CollectionName get_collection_name() {
        return Psu::collection_name;
    }

    static enums::Component get_component() {
        return Psu::component;
    }

    /*!
     * @brief return slot of type uint32_t
     *
     * @return the slot value
     */
    OptionalField<uint32_t> get_slot() const {
        return m_slot;
    }

    /*!
     * @brief setter for slot attribute
     *
     * @param slot of type uint32_t
     */
    void set_slot(const OptionalField<uint32_t> slot) {
        m_slot = slot;
    }

    /*!
     * @brief return power_capacity of type double
     *
     * @return the power_capacity value
     */
    OptionalField<double> get_power_capacity() const {
        return m_power_capacity;
    }

    /*!
     * @brief setter for power_capacity attribute
     *
     * @param power_capacity of type double
     */
    void set_power_capacity(const OptionalField<double> power_capacity) {
        m_power_capacity = power_capacity;
    }

    /*!
     * @brief return power_input of type double
     *
     * @return the power_input value
     */
    OptionalField<double> get_power_input() const {
        return m_power_input;
    }

    /*!
     * @brief setter for power_input attribute
     *
     * @param power_input of type double
     */
    void set_power_input(const OptionalField<double> power_input) {
        m_power_input = power_input;
    }

    /*!
     * @brief return power_output of type double
     *
     * @return the power_output value
     */
    OptionalField<double> get_power_output() const {
        return m_power_output;
    }

    /*!
     * @brief setter for power_output attribute
     *
     * @param power_output of type double
     */
    void set_power_output(const OptionalField<double> power_output) {
        m_power_output = power_output;
    }

    /*!
	 * @brief return an object fru_info of class attribute::FruInfo
	 *
	 * @return the fru_info value
	 */
	const attribute::FruInfo& get_fru_info() const {
        return m_fru_info;
    }

    /*!
     * @brief setter for fru_info attribute
     *
     * @param fru_info of type attribute::FruInfo
     */
    void set_fru_info(const attribute::FruInfo& fru_info) {
        m_fru_info = fru_info;
    }

private:

    OptionalField<uint32_t> m_slot{0u};
    OptionalField<double> m_power_input{0.0};
    OptionalField<double> m_power_output{0.0};
    OptionalField<double> m_power_capacity{0.0};
    attribute::FruInfo m_fru_info{};

    static const enums::CollectionName collection_name;
    static const enums::Component component;

};

}
}
#endif /* AGENT_FRAMEWORK_MODULE_MODEL_PSU_HPP */
