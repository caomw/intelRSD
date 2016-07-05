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
 * */

#ifndef AGENT_COMPUTE_TEST_LOADER_HPP
#define AGENT_COMPUTE_TEST_LOADER_HPP

static constexpr const char COMPUTE_FULL_CONFIGURATION[] = R"({
    "agent": {
        "vendor" : "Intel Corporation",
        "capabilities" : [ "Compute" ]
    },
    "server": {
        "ipv4":"100.100.100.100",
        "port": 7777
    },
    "registration": {
        "ipv4": "200.200.200.200",
        "port": 8383,
        "interval": 3
    },
    "managers": [
        {
            "ipv4" : "1.1.2.1",
            "username" : "user1",
            "password" : "password1",
            "port" : 623,
            "slot" : 1,
            "switchPortIdentifier" : "sw0p37",
            "serialConsoleEnabled": true
        }
    ]
})";



#endif //AGENT_COMPUTE_TEST_LOADER_HPP
