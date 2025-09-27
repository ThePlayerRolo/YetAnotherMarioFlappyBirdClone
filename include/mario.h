#pragma once

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "types.h"
#include "collison.h"

#define MARIO_GRAVITY 1

typedef struct {
    Vector2 mPos;
    Vector2 mRot;
    Vector2 mScale;
    Vector2 mVel;
    CollisionBox mColBox;
    sprite_t* mSprite;
    rdpq_blitparms_t mBlitParams;
} Mario;

Mario* marioInit(Vector2);
void marioUpdate(Mario*);
void marioDraw(Mario*);

extern Mario* mario;

