
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>
#include "../include/mario.h"
#include "../include/types.h"
//Controller Lesson  Code
void Lesson2_Functions(void) {
    bool joypad_is_connected(joypad_port_t port);
    //joypad_style_t joypad_get_style(joypad_port_t port);
    joybus_identifier_t joypad_get_identifier(joypad_port_t port);
    joypad_accessory_type_t joypad_get_accessory_type(joypad_port_t port);
    joypad_inputs_t joypad_get_inputs(joypad_port_t port);
    joypad_buttons_t joypad_get_buttons(joypad_port_t port);
    joypad_8way_t joypad_get_direction(joypad_port_t port, joypad_2d_t axes);
    int joypad_get_axis_pressed(joypad_port_t port, joypad_axis_t axis);
    int joypad_get_axis_released(joypad_port_t port, joypad_axis_t axis);
    int joypad_get_axis_held(joypad_port_t port, joypad_axis_t axis);
    // Button pressed on this frame
    joypad_buttons_t joypad_get_buttons_pressed(joypad_port_t port);
    int joypad_get_axis_pressed(joypad_port_t port, joypad_axis_t axis);

    // Button held since the previous frame
    joypad_buttons_t joypad_get_buttons_held(joypad_port_t port);
    int joypad_get_axis_released(joypad_port_t port, joypad_axis_t axis);

    // Button released on this frame
    joypad_buttons_t joypad_get_buttons_released(joypad_port_t port);
    int joypad_get_axis_held(joypad_port_t port, joypad_axis_t axis);

    // Returns the counter-clockwise direction in a 2-way axis
    joypad_8way_t joypad_get_direction(joypad_port_t port, joypad_2d_t axes);
}





/* main code entry point */
int main(void)
{
	display_context_t disp;
	display_init(RESOLUTION_320x240, DEPTH_16_BPP, 2, GAMMA_NONE, FILTERS_RESAMPLE);
	dfs_init(DFS_DEFAULT_LOCATION);
    joypad_init();
    joypad_inputs_t inputs;
    joypad_buttons_t buttons;
    mario_init();
	// Main loop
	while (1) {
        joypad_poll();
	    int f = dfs_open("MarioHead.sprite");
	    sprite_t *squid = malloc(dfs_size(f));
	    dfs_read(squid, 1, dfs_size(f), f);
	    dfs_close(f);
        JOYPAD_PORT_FOREACH(port) {
            if (port == 0) {
            inputs = joypad_get_inputs(port);
            buttons = joypad_get_buttons_pressed(port);
            mario_update(&buttons);

            }
        }
		while(!(disp = display_get()));
		graphics_draw_box(disp, 20, 20, 280, 200, graphics_make_color(255, 255, 255, 255));
		// Draw the sprite onto the frame buffer
		graphics_draw_sprite_trans(disp, MarioPos.x, MarioPos.y, squid);

		display_show(disp);
	}
}