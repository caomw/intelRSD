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

package com.intel.podm.business.entities.base.converters;

import java.util.List;

import static java.util.Collections.emptyList;
import static java.util.Optional.ofNullable;

public class ListConverter<T extends List> implements PropertyTypeConverter<List, T> {
    @Override
    public List convertFromMappedType(T list) {
        return list;
    }

    @Override
    public T convertToMappedType(List list) {
        return (T) ofNullable(list).orElse(emptyList());
    }
}
