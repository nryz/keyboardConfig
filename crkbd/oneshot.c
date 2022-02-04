#include "oneshot.h"
#include "print.h"

uint16_t oneshot_delay = 200;

bool update_cosm(
    cosm_state *state,
    uint16_t *key_pressed_timer,
    uint16_t mod,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
  if(keycode == trigger) {
    if (record->event.pressed) {
      if(*state == cosm_up) {
        *key_pressed_timer = timer_read();
        *state = cosm_down;
        dprintf("cosm_down\n");
      }
    }
    else {
      dprintf("cosm_up\n");
      *state = cosm_up;
      if(timer_elapsed(*key_pressed_timer) < oneshot_delay) {
        reset_oneshots();
        set_oneshot_mods(MOD_MASK_SHIFT);
        dprintf("set oneshots\n");
      }
      *key_pressed_timer = 0;
    }
  }
  return true;
}


bool update_oneshot(
    oneshot_state *state,
    cosm_state *cosm_state,
    uint16_t mod,
    uint16_t trigger,
    uint16_t key,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger && *cosm_state == cosm_down) {
      if (record->event.pressed) {
          // Trigger keydown
          if (*state == os_up_unqueued) {
              register_code(mod);
          }
          // dprintf("set os_down_unused: %d\n", mod);
          *state = os_down_unused;
      } else {
          // Trigger keyup
          // dprintf("trigger keyup: %d\n", mod);
          switch (*state) {
          case os_down_unused:
              // If we didn't use the mod while trigger was held, queue it.
              *state = os_up_queued;
              dprintf("set os_up_queued: %d\n", mod);
              break;
          case os_down_used:
              // If we did use the mod while trigger was held, unregister it.
              *state = os_up_unqueued;
              dprintf("set os_up_unqueued: %d\n", mod);
              unregister_code(mod);
              break;
          default:
              break;
          }
      }
    } else {
        if (record->event.pressed) {
          if (keycode == trigger) {
            register_code(key);
          }

          dprintf("register_code\n", mod);
          if (is_oneshot_cancel_key(keycode) && *state != os_up_unqueued) {
              // Cancel oneshot on designated cancel keydown.
              // dprintf("set os_up_unqueued: %d\n", mod);
              *state = os_up_unqueued;
              unregister_code(mod);
          }
        } else {
          if (keycode == trigger) {
            unregister_code(key);
          }
          if (!is_oneshot_ignored_key(keycode,cosm_state)) {
              // On non-ignored keyup, consider the oneshot used.
              switch (*state) {
              case os_down_unused:
                  *state = os_down_used;
                   dprintf("set os_down_used: %d\n", mod);
                  break;
              case os_up_queued:
                  *state = os_up_unqueued;
                  dprintf("set os_up_unqueued: %d\n", mod);
                  unregister_code(mod);
                  break;
              default:
                   dprintf("default\n", mod);
                  break;
              }
          }
        }
    }
  return true;
}
