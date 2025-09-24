#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "../include/util.h"
#include "../include/types.h"

//Returns the buttons
joypad_buttons_t handleButtons() {
	joypad_buttons_t buttons;
	joypad_poll();
    joypad_port_t port = 0;
    if (joypad_is_connected(port)) {
        buttons = joypad_get_buttons_pressed(port);
    }
	return buttons;
}

void render() {
	surface_t * disp;
	disp = display_get();
	rdpq_attach_clear(disp, NULL);
	color_t Sky = SetColor(61,205,227,255);
	rdpq_set_mode_fill(Sky);
	rdpq_fill_rectangle(0,0, 320,240);
	rdpq_set_mode_standard();
	rdpq_mode_alphacompare(1);
	rdpq_detach_show();
}
/* main code entry point */
int main(void)
{
	display_init(RESOLUTION_320x240, DEPTH_16_BPP, 3, GAMMA_NONE, FILTERS_RESAMPLE);
	dfs_init(DFS_DEFAULT_LOCATION);
	audio_init(44100,4);
    mixer_init(4);
	rdpq_init();
	joypad_init();

	while(1) {
		joypad_buttons_t buttons = handleButtons();
		render();
	}

	return 0;
}