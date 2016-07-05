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

package com.intel.podm.client.events;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.intel.podm.common.types.events.EventType;

import java.net.URI;
import java.util.EnumSet;

import static java.util.EnumSet.noneOf;

public final class EventSubscribeRequest {
    @JsonProperty("Name")
    private final String name = "Event Subscription";

    @JsonProperty("Description")
    private String description;

    @JsonProperty("Destination")
    private String destination;

    @JsonProperty("EventTypes")
    private EnumSet<EventType> eventTypes = noneOf(EventType.class);

    @JsonProperty("Context")
    private String context;

    @JsonProperty("Protocol")
    private final String protocol = "Redfish";

    private EventSubscribeRequest(Builder builder) {
        this.description = builder.description;
        this.destination = builder.destination;
        this.eventTypes = builder.eventTypes;
        this.context = builder.context;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setDestination(String destination) {
        this.destination = destination;
    }

    public void setEventTypes(EnumSet<EventType> eventTypes) {
        this.eventTypes = eventTypes;
    }

    public static Builder newBuilder() {
        return new Builder();
    }

    public static final class Builder {
        private String description;
        private String destination;
        private EnumSet<EventType> eventTypes;
        private String context;

        private Builder() {
        }

        public Builder description(String description) {
            this.description = description;
            return this;
        }

        public Builder destination(URI destination) {
            this.destination = destination.toString();
            return this;
        }

        public Builder eventTypes(EnumSet<EventType> eventTypes) {
            this.eventTypes = eventTypes;
            return this;
        }

        public Builder context(String context) {
            this.context = context;
            return this;
        }

        public EventSubscribeRequest build() {
            return new EventSubscribeRequest(this);
        }
    }
}
