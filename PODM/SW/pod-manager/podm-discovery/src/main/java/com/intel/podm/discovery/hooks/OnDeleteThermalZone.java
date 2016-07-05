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

package com.intel.podm.discovery.hooks;

import com.intel.podm.business.entities.base.DomainObject;
import com.intel.podm.business.entities.dao.GenericDao;
import com.intel.podm.business.entities.hooks.OnDeleteHook;
import com.intel.podm.business.entities.redfish.ThermalZone;

import javax.enterprise.context.Dependent;
import javax.inject.Inject;
import javax.transaction.Transactional;

import static java.util.Optional.ofNullable;
import static javax.transaction.Transactional.TxType.MANDATORY;

@Dependent
@Transactional(MANDATORY)
public class OnDeleteThermalZone implements OnDeleteHook {

    @Inject
    private GenericDao genericDao;

    @Override
    public void execute(DomainObject domainObject) {
        ThermalZone thermalZone = (ThermalZone) domainObject;

        ofNullable(thermalZone.getRackLocation()).ifPresent(genericDao::remove);
        thermalZone.getFans().forEach(genericDao::remove);
        thermalZone.getTemperatures().forEach(genericDao::remove);
    }

    @Override
    public boolean canExecute(DomainObject domainObject) {
        return domainObject instanceof ThermalZone;
    }
}
