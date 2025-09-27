#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "../include/types.h"
#include "../include/util.h"
#include "../include/input.h"
#include "../include/game.h"
#include "../include/score.h"


GAME_STATES curGameState;


void switchGameState(GAME_STATES pState) {
    curGameState = pState;
}

void managePausedState() {
    if (buttons.start) {
        if (curGameState == STATE_GAME) {
            switchGameState(STATE_GAME_PAUSED);
        } else {
            switchGameState(STATE_GAME);
        }
    }
}

void renderTextPaused() {
    rdpq_text_printf(NULL, 1, 140, 120, "PAUSED");
}

void manageRenderStates() {
    switch (curGameState) {
        case STATE_GAME_PAUSED:
        rdpq_text_printf(NULL, 1, 90, 120, "PAUSED");
        break;
        case STATE_GAME:
        break;
        default:
        break;
    }
}

void manageStates() {
    switch (curGameState) {
        case STATE_GAME:
        managePausedState(); 
        break;
        case STATE_GAME_PAUSED:
        managePausedState();
        break;
        case STATE_TITLE:
        if (buttons.start) switchGameState(STATE_GAME);
        break;
        case STATE_ENDSCREEN:
        if (buttons.start) switchGameState(STATE_TITLE);
        break;
    }
}