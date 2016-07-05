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

package com.intel.podm.mappers.lui;

import com.intel.podm.business.entities.redfish.Device;
import com.intel.podm.client.api.resources.redfish.DeviceResource;

import javax.enterprise.context.Dependent;

@Dependent
public class LuiDeviceMapper extends LuiMapper<DeviceResource, Device> {
    public LuiDeviceMapper() {
        super(DeviceResource.class, Device.class);
    }

    @Override
    protected void performNotAutomatedMapping(DeviceResource source, Device target) {
        target.setName(source.getName());
        target.setDescription(source.getDescription());
    }
}
