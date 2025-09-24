#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "../include/types.h"
#include "../include/util.h"
#include "../include/game.h"


GAME_STATES curGameState;


void switchGameState(GAME_STATES pState) {
    curGameState = pState;
}