#pragma once

#include QMK_KEYBOARD_H

// Represents the four states a oneshot key can be in
typedef enum {
    os_up_unqueued,
    os_up_queued,
    os_down_unused,
    os_down_used,
} oneshot_state;

typedef enum {
  cosm_up,
  cosm_down,
} cosm_state;

bool update_cosm(
    cosm_state *state,
    uint16_t *key_pressed_timer,
    uint16_t mod,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
);

// Custom oneshot mod implementation that doesn't rely on timers. If a mod is
// used while it is held it will be unregistered on keyup as normal, otherwise
// it will be queued and only released after the next non-mod keyup.
bool update_oneshot(
    oneshot_state *state,
    cosm_state *cosm_state,
    uint16_t mod,
    uint16_t trigger,
    uint16_t key,
    uint16_t keycode,
    keyrecord_t *record
);

void reset_oneshots(void);

// To be implemented by the consumer. Defines keys to cancel oneshot mods.
bool is_oneshot_cancel_key(uint16_t keycode);

// To be implemented by the consumer. Defines keys to ignore when determining
// whether a oneshot mod has been used. Setting this to modifiers and layer
// change keys allows stacking multiple oneshot modifiers, and carrying them
// between layers.
bool is_oneshot_ignored_key(uint16_t keycode, cosm_state *cosm_state);
