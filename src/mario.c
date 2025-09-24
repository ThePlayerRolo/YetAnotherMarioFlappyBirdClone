#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "../include/types.h"
#include "../include/collison.h"
#include "../include/util.h"
#include "../include/mario.h"
#include "../include/input.h"
#include "../include/game.h"


#define MARIO_GRAVITY 1
//C++ terms? In my C?
Mario* marioInit(Vector2 pPos) {
    Mario* this = malloc(sizeof(Mario));
    this->mPos = pPos;
    this->mVel = this->mRot = ZeroVector2();
    this->mScale = SetVector2(1.0f, 1.0f);
    this->mColBox = initCollisionBox(this->mPos, 32,32);
    this->mSprite = sprite_load("rom://MarioBird.sprite");
    //this->mBlitParams = malloc(sizeof(rdpq_blitparms_t));
    this->mBlitParams = (rdpq_blitparms_t) {
        .s0 = 0, 
        .cx = 0,
        .cy = 0,
        .width = 0, 
        .flip_x = 0,
    };

    return this;
}

void marioUpdateGame(Mario* this) {
    if (buttons.a) {
        this->mVel.y = -8;
    }
    this->mVel.y += MARIO_GRAVITY;
    
    this->mPos.y += this->mVel.y;
    this->mColBox.pos = this->mPos;
    if (this->mVel.y > 1) {
        this->mVel.y = 1;
    }
}

void marioUpdate(Mario* this) { 
    switch (curGameState) {
        case STATE_TITLE:
        
        break;
        case STATE_GAME:
        marioUpdateGame(this);
        break;
        case STATE_ENDSCREEN:
        break;
    }
}


void marioDraw(Mario* this) {
    rdpq_sprite_blit(this->mSprite, this->mPos.x, this->mPos.y, &this->mBlitParams);
}
