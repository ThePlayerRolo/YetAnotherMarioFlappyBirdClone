#pragma once

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "types.h"
#include "input.h"
#include "game.h"
#include "collison.h"
#include "util.h"


typedef struct {
    Vector2 mPos;
    CollisionBox mColBox;
    u8 curPipe;
    bool mDebounce;
} ScoreBox;

extern u8 gameScore;
extern u8 highScore;
ScoreBox* scoreBoxInit(Vector2);
void scoreBoxUpdate(ScoreBox* this);
void scoreBoxDraw(ScoreBox* this);
void scoreUpdate();
void scoreInit();