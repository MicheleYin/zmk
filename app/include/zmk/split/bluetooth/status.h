/*
 * Copyright (c) 2026 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <stdint.h>

#define ZMK_SPLIT_BLE_STATUS_VERSION 3
#define ZMK_SPLIT_BLE_STATUS_NO_PROFILE UINT8_MAX

enum zmk_split_ble_status_output {
    ZMK_SPLIT_BLE_STATUS_OUTPUT_NONE,
    ZMK_SPLIT_BLE_STATUS_OUTPUT_USB,
    ZMK_SPLIT_BLE_STATUS_OUTPUT_BLE,
};

struct zmk_split_ble_status {
    uint8_t version;
    uint8_t active_layer;
    uint8_t words_per_minute;
    uint8_t central_battery_level;
    uint8_t central_charge_state;
    uint8_t output;
    uint8_t active_ble_profile;
    uint8_t connected_ble_profiles;
    uint8_t bonded_ble_profiles;
    uint8_t ble_profile_count;
} __packed;

typedef void (*zmk_split_ble_status_changed_cb_t)(const struct zmk_split_ble_status *status);

int zmk_split_ble_register_central_status_callback(zmk_split_ble_status_changed_cb_t callback);
int zmk_split_ble_get_central_status(struct zmk_split_ble_status *status);