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

package com.intel.podm.client.resources.redfish.properties;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.intel.podm.client.api.resources.redfish.TemperatureResource;
import com.intel.podm.common.types.PhysicalContext;
import com.intel.podm.common.types.Status;

@JsonIgnoreProperties(ignoreUnknown = true)
public class TemperatureResourceImpl implements TemperatureResource {
    @JsonProperty("Name")
    private String name;
    @JsonProperty("Status")
    private Status status;
    @JsonProperty("ReadingCelsius")
    private Integer readingCelsius;
    @JsonProperty("PhysicalContext")
    private PhysicalContext physicalContext;

    @Override
    public String getName() {
        return name;
    }

    @Override
    public Status getStatus() {
        return status;
    }

    @Override
    public Integer getReadingCelsius() {
        return readingCelsius;
    }

    @Override
    public PhysicalContext getPhysicalContext() {
        return physicalContext;
    }
}
