#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "../include/types.h"
#include "../include/util.h"
#include "../include/input.h"

//Overall game inputs
joypad_buttons_t buttons;

void handleButtons() {
	joypad_poll();
    joypad_port_t port = 0;
    if (joypad_is_connected(port)) {
        buttons = joypad_get_buttons_pressed(port);
    }
}
