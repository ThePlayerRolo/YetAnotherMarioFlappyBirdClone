#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>
#include "../include/main.h"

int MarioHeadINT;
int GroundINT;
int PipeINT;
sprite_t *MarioHeadSprite;
sprite_t *GroundSprite;
sprite_t * PipeSprite;

//Loads Mario Head Sprite Into Memory
void loadMarioHead(void) {
	    MarioHeadINT = dfs_open("MarioHead.sprite");
	    MarioHeadSprite = malloc(dfs_size(MarioHeadINT));
	    dfs_read(MarioHeadSprite, 1, dfs_size(MarioHeadINT), MarioHeadINT);
	    dfs_close(MarioHeadINT);
}
//Loads Bottom Sprite Into Memory
void loadBottom(void) {
		GroundINT = dfs_open("GroundTexture.sprite");
	    GroundSprite = malloc(dfs_size(GroundINT));
	    dfs_read(GroundSprite, 1, dfs_size(GroundINT), GroundINT);
	    dfs_close(GroundINT);
}
//Loads Pipe Sprite Into Memory
void loadPipe(void) {
		PipeINT = dfs_open("Pipe.sprite");
	    PipeSprite = malloc(dfs_size(PipeINT));
	    dfs_read(PipeSprite, 1, dfs_size(PipeINT), PipeINT);
	    dfs_close(PipeINT);
}

//Loads all Textures into Memory
void loadAllTextures(void) {
	loadMarioHead();
	loadBottom();
	loadPipe();
	//loadGameSprite(MarioHeadINT, MarioHeadSprite, "./MarioHead.sprite");
	//loadGameSprite(GroundINT, GroundSprite, "./GroundINT.sprite");
}
void DrawMarioCollisionBody(display_context_t disp) {
	graphics_draw_line(disp, MarioColl.vec1.x, MarioColl.vec1.y, MarioColl.vec2.x, MarioColl.vec2.y,graphics_make_color(235, 64, 52, 255) );
	graphics_draw_line(disp, MarioColl.vec1.x, MarioColl.vec1.y, MarioColl.vec4.x, MarioColl.vec4.y,graphics_make_color(235, 64, 52, 255) );
	graphics_draw_line(disp, MarioColl.vec2.x, MarioColl.vec2.y, MarioColl.vec3.x, MarioColl.vec3.y,graphics_make_color(235, 64, 52, 255) );
	graphics_draw_line(disp, MarioColl.vec4.x, MarioColl.vec4.y, MarioColl.vec3.x, MarioColl.vec3.y,graphics_make_color(235, 64, 52, 255) );
}

void DrawPipeCollisionBody1(display_context_t disp) {
	//Vec1: 235,90 Vec2: 265,90 Vec3: 265,155 Vec4: 235,155
	graphics_draw_line(disp, PipeTopColl.vec1.x, PipeTopColl.vec1.y, PipeTopColl.vec2.x, PipeTopColl.vec2.y,graphics_make_color(235, 64, 52, 255) );
	graphics_draw_line(disp, PipeTopColl.vec4.x, PipeTopColl.vec4.y, PipeTopColl.vec3.x, PipeTopColl.vec3.y,graphics_make_color(235, 64, 52, 255) );
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
	pipe_top_init();
	// Main loop
	while (1) {
        joypad_poll();
        loadAllTextures();
        joypad_port_t port = 0;
        if (joypad_is_connected(port)) {
            buttons = joypad_get_buttons_pressed(port);
			pipe_top_update();
            mario_update(&buttons);
        }
		while(!(disp = display_get()));
		graphics_draw_box(disp, 0, 0, 320, 240, graphics_make_color(61, 205, 227, 255));
		// Draw the sprite onto the frame buffer
		for (int i = 0; i < 400; i += 40) {
			graphics_draw_sprite(disp, i + 3, 210, GroundSprite);

		}
		int vec3diffy = MarioColl.vec2.x;
    	int vec3diffy2 = PipeTopPos.x;
		char vec31[3];
		char vec32[3];
		sprintf(vec31, "%d", vec3diffy);
		sprintf(vec32, "%d", vec3diffy2);
		graphics_draw_text(disp, 230,30, vec31);
		graphics_draw_text(disp, 230,60, vec32);
		graphics_draw_sprite_trans(disp, PipeTopPos.x, PipeTopPos.y, PipeSprite);
		graphics_draw_sprite_trans(disp, MarioPos.x, MarioPos.y, MarioHeadSprite);
		DrawPipeCollisionBody1(disp);
		//DrawMarioCollisionBody(disp);

		display_show(disp);
	}
}