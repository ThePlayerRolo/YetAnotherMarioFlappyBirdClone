#pragma once

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "types.h"
#include "collison.h"

#define PIPE_START 330.0f
#define PIPE_COUNT 4

typedef struct {
    Vector2 mPos;
    Vector2 mVel;
    CollisionBox mColBox;
    sprite_t* mSprite;
    rdpq_blitparms_t mBlitParams; 
    bool mIsTopPipe;
    bool mIsFirst;
    u8 mGroup;
    f32 startPosX;
} Pipe;

void pipeArrayInit();
void pipeArrayUpdate();
void pipeArrayDraw();
void pipeArrayFree();

extern Pipe* BottomPipes[PIPE_COUNT];
extern Pipe* TopPipes[PIPE_COUNT];