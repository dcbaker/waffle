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

#include "wegl_surface.h"

struct wcore_platform;
struct gbm_surface;

struct wgbm_window {
    struct gbm_surface *gbm_surface;
    struct wegl_surface wegl;
};

static inline struct wgbm_window*
wgbm_window(struct wcore_window *wc_self)
{
    if (wc_self) {
        struct wegl_surface *wegl_self = container_of(wc_self, struct wegl_surface, wcore);
        return container_of(wegl_self, struct wgbm_window, wegl);
    }
    else {
        return NULL;
    }
}

struct wcore_window*
wgbm_window_create(struct wcore_platform *wc_plat,
                   struct wcore_config *wc_config,
                   int32_t width,
                   int32_t height,
                   const intptr_t attrib_list[]);

bool
wgbm_window_destroy(struct wcore_window *wc_self);

bool
wgbm_window_show(struct wcore_window *wc_self);

bool
wgbm_window_swap_buffers(struct wcore_window *wc_self);

union waffle_native_window*
wgbm_window_get_native(struct wcore_window *wc_self);
