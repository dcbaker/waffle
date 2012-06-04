// Copyright 2012 Intel Corporation
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// - Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// - Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#include <waffle/api/api_object.h>

#include "wcore_util.h"

struct wcore_display;
struct wcore_platform;
union waffle_native_display;

struct wcore_display_vtbl {
    bool
    (*destroy)(struct wcore_display *self);

    bool
    (*supports_context_api)(
            struct wcore_display *self,
            int32_t context_api);

    union waffle_native_display*
    (*get_native)(struct wcore_display *self);
};

struct wcore_display {
    const struct wcore_display_vtbl *vtbl;

    struct waffle_display {} wfl;
    struct api_object api;

    struct wcore_platform *platform;
};

DEFINE_CONTAINER_CAST_FUNC(wcore_display,
                           struct wcore_display,
                           struct waffle_display,
                           wfl)

bool
wcore_display_init(struct wcore_display *self,
                   struct wcore_platform *platform);


bool
wcore_display_teardown(struct wcore_display *self);
