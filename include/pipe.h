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

typedef struct {
    Vector2 mPos;
    Vector2 mVel;
    CollisionBox mColBox;
    sprite_t* mSprite;
    rdpq_blitparms_t mBlitParams; 
    bool mIsTopPipe;
} Pipe;

Pipe* pipeInit(Vector2, bool);
void  pipeUpdate(Pipe*);
void pipeDraw(Pipe*);

extern const Vector2 PipeYValues[3];
extern Pipe* pipeBottom;
extern Pipe* pipeTop;