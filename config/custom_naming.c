#include <zmk/event_manager.h>
#include <zmk/events/bt_profile_changed.h>
#include <zmk/ble.h>
#include <stdio.h>

static void update_ble_name(uint8_t profile_index) {
    char new_name[16];
    snprintf(new_name, sizeof(new_name), "The Paintbrush-%d", profile_index);
    zmk_ble_set_device_name(new_name);
}

static int bt_profile_changed_listener(const struct zmk_event_header *eh) {
    const struct bt_profile_changed_event *ev = cast_bt_profile_changed_event(eh);
    update_ble_name(ev->index);
    return 0;
}

ZMK_LISTENER(name_updater, bt_profile_changed_listener);
ZMK_SUBSCRIPTION(name_updater, bt_profile_changed_event);