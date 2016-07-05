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
 * @file iscsi_error.hpp
 *
 * @brief Declaration of ISCSI error interface
 * */

#ifndef AGENT_FRAMEWORK_EXCEPTIONS_ISCSI_ERROR_HPP
#define AGENT_FRAMEWORK_EXCEPTIONS_ISCSI_ERROR_HPP

#include "agent-framework/exceptions/exception_base.hpp"

namespace agent_framework {
namespace exceptions {

/*! @brief iSCSI exception class */
class IscsiError final : public ExceptionBase {
public:
    /*!
     * @brief Constructor
     *
     * @param[in] msg Error message
     */
    explicit IscsiError(const std::string& msg) :
                ExceptionBase{ErrorCode::ISCSI, msg} {}

    IscsiError(const IscsiError&) = default;
    IscsiError& operator=(const IscsiError&) = default;

    IscsiError(IscsiError&&) = default;
    IscsiError& operator=(IscsiError&&) = default;

    /*! @brief Destructor */
    ~IscsiError();
};

} // namespace exceptions
} // namespace agent_framework

#endif	/* AGENT_FRAMEWORK_EXCEPTIONS_ISCSI_ERROR_HPP */
