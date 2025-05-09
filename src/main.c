
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>
#include "../include/mario.h"
#include "../include/types.h"
    int MarioHeadSprite;
    sprite_t *MarioHeadRender;
    sprite_t *GroundRender;
    int GroundTexture;

//Loads Mario Head Sprite Into Memory
void loadMarioHead(void) {
	    MarioHeadSprite = dfs_open("MarioHead.sprite");
	    MarioHeadRender = malloc(dfs_size(MarioHeadSprite));
	    dfs_read(MarioHeadRender, 1, dfs_size(MarioHeadSprite), MarioHeadSprite);
	    dfs_close(MarioHeadSprite);
}
//Loads Bottom Sprite Into Memory
void loadBottom(void) {
	    GroundTexture = dfs_open("GroundTexture.sprite");
	    GroundRender = malloc(dfs_size(GroundTexture));
	    dfs_read(GroundRender, 1, dfs_size(GroundTexture), GroundTexture);
	    dfs_close(GroundTexture);
}

//Loads all Textures into Memory
void loadAllTextures(void) {
    loadMarioHead();
    loadBottom();
}

/* main code entry point */
int main(void)
{
	display_context_t disp;
	display_init(RESOLUTION_320x240, DEPTH_16_BPP, 2, GAMMA_NONE, FILTERS_RESAMPLE);
	dfs_init(DFS_DEFAULT_LOCATION);
    joypad_init();
    joypad_buttons_t buttons;
    mario_init();
	// Main loop
	while (1) {
        joypad_poll();
        loadAllTextures();
        joypad_port_t port = 0;
        if (joypad_is_connected(port)) {
            buttons = joypad_get_buttons_pressed(port);
            mario_update(&buttons);
        }
		while(!(disp = display_get()));
		graphics_draw_box(disp, 0, 0, 320, 240, graphics_make_color(255, 255, 255, 255));
		// Draw the sprite onto the frame buffer
		for (int i = 0; i < 400; i += 40) {
			graphics_draw_sprite(disp, i + 3, 210, GroundRender);

		}
		graphics_draw_sprite_trans(disp, MarioPos.x, MarioPos.y, MarioHeadRender);


		display_show(disp);
	}
}