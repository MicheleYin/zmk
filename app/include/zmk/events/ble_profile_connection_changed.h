/*
 * Copyright (c) 2026 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>

#include <zmk/event_manager.h>

struct zmk_ble_profile_connection_changed {
    uint8_t index;
    bool connected;
};

ZMK_EVENT_DECLARE(zmk_ble_profile_connection_changed);