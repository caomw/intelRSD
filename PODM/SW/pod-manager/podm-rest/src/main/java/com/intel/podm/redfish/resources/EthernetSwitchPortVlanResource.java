/*
 * Copyright (c) 2016 Intel Corporation
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

package com.intel.podm.redfish.resources;

import com.intel.podm.business.dto.redfish.EthernetSwitchPortVlanDto;
import com.intel.podm.business.services.redfish.EthernetSwitchPortVlanService;

import javax.inject.Inject;
import javax.ws.rs.GET;
import javax.ws.rs.Produces;

import static javax.ws.rs.core.MediaType.APPLICATION_JSON;

@Produces(APPLICATION_JSON)
public class EthernetSwitchPortVlanResource extends BaseResource {

    @Inject
    private EthernetSwitchPortVlanService service;

    @GET
    @Override
    public EthernetSwitchPortVlanDto get() {
        return getOrThrow(() -> service.getEthernetSwitchPortVlan(getCurrentContext()));
    }
}
