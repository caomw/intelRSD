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

package com.intel.podm.business.redfish.services;

import com.intel.podm.business.EntityNotFoundException;
import com.intel.podm.business.dto.redfish.CollectionDto;
import com.intel.podm.business.dto.redfish.EthernetSwitchPortVlanDto;
import com.intel.podm.business.entities.redfish.EthernetSwitchPort;
import com.intel.podm.business.entities.redfish.EthernetSwitchPortVlan;
import com.intel.podm.business.redfish.Contexts;
import com.intel.podm.business.redfish.DomainObjectTreeTraverser;
import com.intel.podm.business.services.context.Context;
import com.intel.podm.business.services.redfish.EthernetSwitchPortVlanService;

import javax.inject.Inject;
import javax.transaction.Transactional;

import static com.intel.podm.business.dto.redfish.CollectionDto.Type.ETHERNET_SWITCH_PORT_VLANS;
import static javax.transaction.Transactional.TxType.REQUIRED;

@Transactional(REQUIRED)
public class EthernetSwitchPortVlanServiceImpl implements EthernetSwitchPortVlanService {

    @Inject
    private DomainObjectTreeTraverser traverser;

    @Override
    public CollectionDto getEthernetSwitchPortVlanCollection(Context ethernetSwitchPort) throws EntityNotFoundException {
        EthernetSwitchPort port = (EthernetSwitchPort) traverser.traverse(ethernetSwitchPort);
        return new CollectionDto(ETHERNET_SWITCH_PORT_VLANS, Contexts.getAsIdList(port.getVlans()));
    }

    @Override
    public EthernetSwitchPortVlanDto getEthernetSwitchPortVlan(Context ethernetSwitchPortVlan) throws EntityNotFoundException {
        EthernetSwitchPortVlan portVlan = (EthernetSwitchPortVlan) traverser.traverse(ethernetSwitchPortVlan);
        return EthernetSwitchPortVlanDto.newBuilder()
            .id(portVlan.getId())
            .name(portVlan.getName())
            .description(portVlan.getDescription())
            .status(portVlan.getStatus())
            .vlanEnable(portVlan.getVlanEnable())
            .tagged(portVlan.getTagged())
            .vlanId(portVlan.getVlanId())
            .build();
    }
}
