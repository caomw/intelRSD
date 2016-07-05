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
 * @file lag_port_message.hpp
 *
 * @brief Switch Lag Port configuration
 * */

#ifndef AGENT_NETWORK_NETLINK_LAG_PORT_MESSAGE_HPP
#define AGENT_NETWORK_NETLINK_LAG_PORT_MESSAGE_HPP

#include "lag_message.hpp"

namespace agent {
namespace network {
namespace api {
namespace netlink {

/*! Add Lag Port Message */
class LagPortMessage: public LagMessage {
public:

    /*!
     * @brief Default constructor.
     * @param[in] lag Lag interface name.
     * @param[in] port Port interface name.
     */
    LagPortMessage(const IfName& lag, const IfName& port);

    /*!
     * @brief Default destructor.
     */
    virtual ~LagPortMessage();

    /*!
     * @brief Prepare Lag port netlink message.
     * @return Netlink message ready to be sent.
     */
    Pointer prepare_netlink_msg() const;
};

}
}
}
}

#endif /* AGENT_NETWORK_NETLINK_LAG_PORT_MESSAGE_HPP */
