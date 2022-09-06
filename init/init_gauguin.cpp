/*
 * Copyright (c) 2021, The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <android-base/properties.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"
#include "property_service.h"

void property_override(char const prop[], char const value[]) {
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);

    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void load_gauguin() {
    property_override("ro.product.mod_device", "gauguin_global");
    property_override("ro.build.fingerprint", "Xiaomi/gauguin_global/gauguin:12/SKQ1.211006.001/V13.0.4.0.SJSMIXM:user/release-keys");
    property_override("ro.product.brand", "Xiaomi");
    property_override("ro.product.device", "gauguin");
    property_override("ro.product.model", "M2007J17G");
    property_override("ro.product.marketname", "Mi 10T Lite");
    property_override("ro.boot.product.hardware.sku", "nfc");
    property_override("bluetooth.device.default_name", "Mi 10T Lite");
}

void load_gauguinpro() {
    property_override("ro.product.mod_device", "gauguin_global");
    property_override("ro.build.fingerprint", "Redmi/gauguinpro/gauguinpro:12/SKQ1.211006.001/V13.0.6.0.SJSCNXM:user/release-keys");
    property_override("ro.product.brand", "Redmi");
    property_override("ro.product.device", "gauguinpro");
    property_override("ro.product.model", "M2007J17C");
    property_override("ro.product.marketname", "Redmi Note 9 Pro");
    property_override("ro.boot.product.hardware.sku", "nfc");
    property_override("bluetooth.device.default_name", "Redmi Note 9 Pro");
}

void load_gauguininpro() {
    property_override("ro.product.mod_device", "gauguin_in_global");
    property_override("ro.build.fingerprint", "Xiaomi/gauguininpro/gauguininpro:12/SKQ1.211006.001/V13.0.6.0.SJSINXM:user/release-keys");
    property_override("ro.product.brand", "Xiaomi");
    property_override("ro.product.device", "gauguininpro");
    property_override("ro.product.model", "M2007J17I");
    property_override("ro.product.marketname", "Mi 10i");
    property_override("bluetooth.device.default_name", "Mi 10i");
}

void load_miuicamera_properties() {
    property_override("vendor.camera.aux.packagelist", "com.android.camera,org.codeaurora.snapcam");
    property_override("persist.vendor.camera.privapp.list", "com.android.camera");
    property_override("ro.com.google.lens.oem_camera_package", "com.android.camera");
    property_override("ro.miui.notch", "1");
}

void vendor_load_properties() {
    std::string region = android::base::GetProperty("ro.boot.hwc", "");

    if (region.find("CN") != std::string::npos)
        load_gauguinpro();
    else if (region.find("INDIA") != std::string::npos)
        load_gauguininpro();
    else if (region.find("GLOBAL") != std::string::npos)
        load_gauguin();
    load_miuicamera_properties();
}
