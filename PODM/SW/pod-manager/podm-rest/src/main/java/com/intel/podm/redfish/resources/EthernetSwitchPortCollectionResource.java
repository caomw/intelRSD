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

package com.intel.podm.redfish.resources;

import com.intel.podm.actions.ActionException;
import com.intel.podm.business.EntityNotFoundException;
import com.intel.podm.business.dto.redfish.CollectionDto;
import com.intel.podm.business.redfish.services.EthernetSwitchPortActionsService;
import com.intel.podm.business.services.redfish.EthernetSwitchPortService;
import com.intel.podm.redfish.json.templates.actions.CreateEthernetSwitchPortActionJson;
import com.intel.podm.rest.odataid.ODataId;
import com.intel.podm.rest.odataid.ODataIds;
import com.intel.podm.rest.resources.PathParamConstants;

import javax.inject.Inject;
import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.core.Response;

import static com.intel.podm.redfish.OptionsResponseBuilder.newDefaultOptionsResponseBuilder;
import static com.intel.podm.rest.error.PodmExceptions.invalidPayload;
import static com.intel.podm.rest.error.PodmExceptions.notFound;
import static java.net.URI.create;
import static javax.ws.rs.core.MediaType.APPLICATION_JSON;
import static javax.ws.rs.core.Response.created;

@Produces(APPLICATION_JSON)
public class EthernetSwitchPortCollectionResource extends BaseResource {

    @Inject
    private EthernetSwitchPortService service;

    @Inject
    private EthernetSwitchPortActionsService actionService;

    @GET
    @Override
    public CollectionDto get() {
        return getOrThrow(() -> service.getEthernetSwitchPortCollection(getCurrentContext()));
    }

    @POST
    @Consumes(APPLICATION_JSON)
    public Response createSwitchPort(CreateEthernetSwitchPortActionJson createSwitchPortActionJson) {
        try {
            ODataId oDataId = ODataIds.oDataIdFromContext(actionService.createSwitchPort(getCurrentContext(), createSwitchPortActionJson));
            return created(create(oDataId.toString())).build();
        } catch (EntityNotFoundException e) {
            throw notFound();
        } catch (ActionException e) {
            throw invalidPayload("Switch Port creation action could not be completed! " + e.getMessage(), e.getErrorResponse());
        }
    }

    @Override
    protected Response createOptionsResponse() {
        return newDefaultOptionsResponseBuilder()
                .addPostMethod()
                .buildResponse();
    }

    @Path(PathParamConstants.ETHERNET_SWITCH_PORT_ID)
    public EthernetSwitchPortResource getEthernetSwitchPort() {
        return getResource(EthernetSwitchPortResource.class);
    }
}
