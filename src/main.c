
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>
#include "../include/main.h"

int MarioHeadSprite;
int GroundTexture;
sprite_t *MarioHeadRender;
sprite_t *GroundRender;


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
	//loadGameSprite(MarioHeadSprite, MarioHeadRender, "./MarioHead.sprite");
	//loadGameSprite(GroundTexture, GroundRender, "./GroundTexture.sprite");
}
void DrawMarioCollisionBody(display_context_t disp) {
	graphics_draw_line(disp, MarioColl.vec1.x, MarioColl.vec1.y, MarioColl.vec2.x, MarioColl.vec2.y,graphics_make_color(235, 64, 52, 255) );
	graphics_draw_line(disp, MarioColl.vec1.x, MarioColl.vec1.y, MarioColl.vec4.x, MarioColl.vec4.y,graphics_make_color(235, 64, 52, 255) );
	graphics_draw_line(disp, MarioColl.vec2.x, MarioColl.vec2.y, MarioColl.vec3.x, MarioColl.vec3.y,graphics_make_color(235, 64, 52, 255) );
	graphics_draw_line(disp, MarioColl.vec4.x, MarioColl.vec4.y, MarioColl.vec3.x, MarioColl.vec3.y,graphics_make_color(235, 64, 52, 255) );
}
void DrawGroundCollisionBody(display_context_t disp) {
	graphics_draw_line(disp, 0, 210, 320, 210,graphics_make_color(235, 64, 52, 255) );
	graphics_draw_line(disp, 0, 235, 320, 235,graphics_make_color(235, 64, 52, 255) );
	//graphics_draw_line(disp, MarioColl.vec1.x, MarioColl.vec1.y, MarioColl.vec4.x, MarioColl.vec4.y,graphics_make_color(235, 64, 52, 255) );
	//graphics_draw_line(disp, MarioColl.vec2.x, MarioColl.vec2.y, MarioColl.vec3.x, MarioColl.vec3.y,graphics_make_color(235, 64, 52, 255) );
	//graphics_draw_line(disp, MarioColl.vec4.x, MarioColl.vec4.y, MarioColl.vec3.x, MarioColl.vec3.y,graphics_make_color(235, 64, 52, 255) );
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
	GroundInit();
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
		graphics_draw_box(disp, 0, 0, 320, 240, graphics_make_color(61, 205, 227, 255));
		// Draw the sprite onto the frame buffer
		for (int i = 0; i < 400; i += 40) {
			graphics_draw_sprite(disp, i + 3, 210, GroundRender);

		}
		int vec3diffy = MarioColl.vec3.y - GroundColl.vec3.y;
    	int vec3diffy2 = GroundColl.vec3.y - MarioColl.vec3.y;
		char vec31[3];
		char vec32[3];
		sprintf(vec31, "%d", vec3diffy);
		sprintf(vec32, "%d", vec3diffy2);
		graphics_draw_text(disp, 230,30, vec31);
		graphics_draw_text(disp, 230,60, vec32);
		graphics_draw_sprite_trans(disp, MarioPos.x, MarioPos.y, MarioHeadRender);
		//DrawMarioCollisionBody(disp);

		DrawGroundCollisionBody(disp);
		display_show(disp);
	}
}