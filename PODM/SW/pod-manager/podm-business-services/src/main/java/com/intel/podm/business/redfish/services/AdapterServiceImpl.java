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
import com.intel.podm.business.dto.redfish.AdapterDto;
import com.intel.podm.business.dto.redfish.CollectionDto;
import com.intel.podm.business.entities.redfish.Adapter;
import com.intel.podm.business.entities.redfish.ComputerSystem;
import com.intel.podm.business.redfish.Contexts;
import com.intel.podm.business.redfish.DomainObjectTreeTraverser;
import com.intel.podm.business.services.context.Context;
import com.intel.podm.business.services.redfish.AdapterService;

import javax.inject.Inject;
import javax.transaction.Transactional;

import static com.intel.podm.business.dto.redfish.CollectionDto.Type.ADAPTERS;
import static javax.transaction.Transactional.TxType.REQUIRED;

@Transactional(REQUIRED)
public class AdapterServiceImpl implements AdapterService {

    @Inject
    private DomainObjectTreeTraverser traverser;

    @Override
    public CollectionDto getAdapters(Context context) throws EntityNotFoundException {
        ComputerSystem computerSystem = (ComputerSystem) traverser.traverse(context);
        return new CollectionDto(ADAPTERS, Contexts.getAsIdList(computerSystem.getAdapters()));
    }

    @Override
    public AdapterDto getAdapter(Context context) throws EntityNotFoundException {
        return toAdapterDto((Adapter) traverser.traverse(context));
    }

    private static AdapterDto toAdapterDto(Adapter adapter) {
        return AdapterDto.newBuilder()
                .id(adapter.getId().toString())
                .name(adapter.getName())
                .description(adapter.getDescription())
                .storageControllerInterface(adapter.getInterface())
                .manufacturer(adapter.getManufacturer())
                .model(adapter.getModel())
                .status(adapter.getStatus())
                .busInfo(adapter.getBusInfo())
                .containedBy(Contexts.toContext(adapter.getComputerSystem()))
                .build();
    }
}
