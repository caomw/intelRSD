/*
 * Copyright (c) 2015 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.intel.podm.discovery.external;

import com.intel.podm.business.entities.redfish.ExternalService;
import com.intel.podm.business.entities.redfish.base.StatusPossessor;
import com.intel.podm.common.types.Status;

import javax.enterprise.context.Dependent;
import javax.transaction.Transactional;

import static com.intel.podm.common.types.State.IN_TEST;
import static javax.transaction.Transactional.TxType.REQUIRES_NEW;

@Dependent
public class ExternalServiceDiscoverablesDelegalizer {
    @Transactional(REQUIRES_NEW)
    public void delegalizeDiscoverables(ExternalService service) {
        service.getDiscoverables().stream()
                .filter(discoverable -> discoverable instanceof StatusPossessor)
                .forEach(discoverable -> {
                    StatusPossessor statusPossessor = (StatusPossessor) discoverable;
                    statusPossessor.setStatus(new Status(IN_TEST, null, null));
                });
    }
}
