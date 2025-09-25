#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "../include/util.h"
#include "../include/types.h"
#include "../include/input.h"
#include "../include/mario.h"
#include "../include/game.h"
#include "../include/pipe.h"

Mario* mario;


void render() {
	surface_t * disp = display_get();
	rdpq_attach_clear(disp, NULL);
	rdpq_set_mode_fill(SetColor(61,205,227,255)); //Sky
	rdpq_fill_rectangle(0,0, 320,240);
	rdpq_set_mode_standard();
	rdpq_mode_alphacompare(1);
	marioDraw(mario);
	pipeDraw(pipeBottom);
	pipeDraw(pipeTop);
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
	switchGameState(STATE_TITLE);
	mario = marioInit(SetVector2(50.0f,120.0f));
	pipeBottom = pipeInit(SetVector2(PIPE_START, PipeYValues[0].x), false);
	pipeTop = pipeInit(SetVector2(PIPE_START, PipeYValues[0].y), true);
	while(1) {
		handleButtons();
		manageStates();
		marioUpdate(mario);
		pipeUpdate(pipeBottom);
		pipeUpdate(pipeTop);
		render();
	}
	free(mario);
	return 0;
}