#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>
#include "../include/main.h"

sprite_t *MarioHeadSprite;
sprite_t *GroundSprite;
sprite_t * PipeSprite;
sprite_t * BottomPipeSprite;
sprite_t * ScoreBOxSprite;
sprite_t * PixelTestSprite;
int BoolStart;

//Loads all Textures into Memory
void loadAllTextures(void) {
	PipeSprite = sprite_load("rom://Pipe.sprite");
	BottomPipeSprite = sprite_load("rom://PipeBottom.sprite");
	GroundSprite = sprite_load("rom://GroundTexture.sprite");
	MarioHeadSprite = sprite_load("rom://MarioHead.sprite");
	ScoreBOxSprite = sprite_load("rom://TestBox.sprite");
	PixelTestSprite = sprite_load("rom://PixelTest.sprite");


}

void render() {
	color_t Sky;
	Sky.a = 255;
	Sky.r = 61;
	Sky.g = 205;
	Sky.b = 227;
	color_t Test;
	Test.a = 255;
	Test.r = 255;
	Test.g = 0;
	Test.b = 0;
	surface_t * disp;
	disp = display_get();
	rdpq_attach_clear(disp, NULL);
	rdpq_set_mode_fill(Sky);
	rdpq_fill_rectangle(0,0, 320,240);
	rdpq_set_mode_standard();
	rdpq_mode_alphacompare(1);
	rdpq_sprite_blit(PipeSprite,PipeTopPos.x, PipeTopPos.y, &(rdpq_blitparms_t){
        .s0 = 0, 
        .cx = 0,
        .cy = 0,
        .width = 0, 
        .flip_x = 0
    });
		rdpq_sprite_blit(BottomPipeSprite,PipeBottomPos.x, PipeBottomPos.y, &(rdpq_blitparms_t){
        .s0 = 0, 
        .cx = 0,
        .cy = 0,
        .width = 0, 
        .flip_x = 0
    });
	for (int i = 0; i < 400; i += 40) {
		rdpq_sprite_blit(GroundSprite,i + 3, 210, &(rdpq_blitparms_t){
    	.s0 = 0, 
    	.cx = 0,
		.cy = 0,
    	.width = 0, 
    	.flip_x = 0
    	});
	}
	rdpq_sprite_blit(MarioHeadSprite,MarioPos.x, MarioPos.y, &(rdpq_blitparms_t){
         .s0 = 0, 
         .cx = 0,
        .cy = 0,
        .width = 0, 
        .flip_x = 0
    });
		/*rdpq_sprite_blit(ScoreBOxSprite, PipeTopPos.x, 60, &(rdpq_blitparms_t){
         .s0 = 0, 
         .cx = 0,
        .cy = 0,
        .width = 0, 
        .flip_x = 0
    });
	//First is PipeTopPos.x, 60 
rdpq_sprite_blit(PixelTestSprite, PipeTopPos.x, 60, &(rdpq_blitparms_t){
         .s0 = 0, 
         .cx = 0,
        .cy = 0,
        .width = 0, 
        .flip_x = 0
    }); */
		rdpq_detach_show();
}
void ButtonStartCheck(joypad_buttons_t buttons) {
	if (buttons.start == 1) {
		BoolStart = !BoolStart;
	}

}

/* main code entry point */
int main(void)
{
    display_init(RESOLUTION_320x240, DEPTH_16_BPP, 3, GAMMA_NONE, FILTERS_RESAMPLE);
	dfs_init(DFS_DEFAULT_LOCATION);
	rdpq_init();
    joypad_init();
    joypad_buttons_t buttons;
    mario_init();
	GroundInit();
	pipe_top_init();
	pipe_bottom_init();
	loadAllTextures();
	BoolStart = 0;
	// Main loop
	while (1) {
        joypad_poll();
        joypad_port_t port = 0;
        if (joypad_is_connected(port)) {
            buttons = joypad_get_buttons_pressed(port);
			ButtonStartCheck(buttons);
			pipe_top_update();
			pipe_bottom_update();
            mario_update(&buttons);

        }
		render();
	}
}