/*!
 * @copyright
 * Copyright (c) 2016 Intel Corporation
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
 * @file client.hpp
 * @brief Client I2C request MUX handler interface
 *
 */

#pragma once
#include "ipmb/mux.hpp"

namespace agent {
namespace chassis {
namespace ipmb {

/*! General class for multiplex connectivity with I2C device */
class Client : public Mux {
public:
    /*!
     * @brief Default constructor
     */
    Client();

    /*!
     * @brief Copy constructor
     * */
    Client(const Client&) = delete;

    /*!
     * @brief Assignment operator
     * */
    Client& operator=(const Client&) = delete;

    /*!
     * @brief Get MUX connection mode
     */
    byte_vec_t mode() const;
};

}
}
}


