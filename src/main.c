#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "../include/main.h"

sprite_t *MarioHeadSprite;
sprite_t *GroundSprite;
sprite_t * PipeSprite;
sprite_t * ScoreBOxSprite;
sprite_t * PixelTestSprite;
int BoolStart;
int BoolTitle;

//Loads all Textures into Memory
void loadAllFiles(void) {
	PipeSprite = sprite_load("rom://Pipe.sprite");
	GroundSprite = sprite_load("rom://GroundTexture.sprite");
	MarioHeadSprite = sprite_load("rom://MarioHead.sprite");
	ScoreBOxSprite = sprite_load("rom://TestBox.sprite");
	PixelTestSprite = sprite_load("rom://PixelTest.sprite");
    rdpq_font_t *fnt1 = rdpq_font_load("rom://Mario64.font64");
    rdpq_text_register_font(1, fnt1);
    rdpq_font_style(fnt1, 0, &(rdpq_fontstyle_t){
	.color = RGBA32(255, 255, 255, 255),
	.outline_color = RGBA32(0, 0, 0, 255),
	});

}
void render() {
	color_t Sky;
	Sky.a = 255;
	Sky.r = 61;
	Sky.g = 205;
	Sky.b = 227;
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
		rdpq_sprite_blit(PipeSprite,PipeBottomPos.x, PipeBottomPos.y, &(rdpq_blitparms_t){
        .s0 = 0, 
        .cx = 0,
        .cy = 0,
        .width = 0, 
        .flip_x = 0,
        .flip_y = 1
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
    if (BoolTitle == 0) {
        rdpq_text_printf(NULL, 1, 150, 40, "%d", score);
    }

		rdpq_detach_show();
}
void ButtonStartCheck(joypad_buttons_t buttons) {
	if (buttons.start == 1) {
		BoolStart = !BoolStart;
	}

}
void audio() {
    if (audio_can_write()) {
		// Select an audio buffer that we can write to
		short *buf = audio_write_begin();
		// Write to the audio buffer from the mixer
		mixer_poll(buf, audio_get_buffer_length());
		// Tell the audio system that the buffer has
		// been filled and is ready for playback
		audio_write_end();
	}
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
    joypad_buttons_t buttons;
    mario_init();
	GroundInit();
	pipe_top_init();
	pipe_bottom_init();
    score_box_init();
	loadAllFiles();
	BoolStart = 0;
    BoolTitle = 0;
	// Main loop
	while (1) {
        joypad_poll();
        joypad_port_t port = 0;
        if (joypad_is_connected(port)) {
            buttons = joypad_get_buttons_pressed(port);
			ButtonStartCheck(buttons);
			pipe_top_update();
			pipe_bottom_update();
            score_box_update();
            mario_update(&buttons);
        }
		render();
        audio();
	}
}