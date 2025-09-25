#pragma once 
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "../include/types.h"
#include "../include/util.h"


typedef enum GAME_STATES {
    STATE_TITLE = 0,
    STATE_GAME = 1,
    STATE_GAME_PAUSED = 2,
    STATE_ENDSCREEN = 3,
} GAME_STATES;

extern GAME_STATES curGameState;

void switchGameState(GAME_STATES);

void manageStates();