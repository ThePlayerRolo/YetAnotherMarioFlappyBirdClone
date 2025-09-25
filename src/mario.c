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
#include "../include/pipe.h"


#define MARIO_GRAVITY 1
//C++ terms? In my C?
Mario* marioInit(Vector2 pPos) {
    Mario* this = malloc(sizeof(Mario));
    this->mPos = pPos;
    this->mVel = this->mRot = ZeroVector2();
    this->mScale = SetVector2(1.0f, 1.0f);
    this->mColBox = initCollisionBox(this->mPos, 32.0f,32.0f);
    this->mSprite = sprite_load("rom://MarioBird.sprite");
    this->mBlitParams = (rdpq_blitparms_t) {
        .s0 = 0, 
        .cx = 0,
        .cy = 0,
        .width = 0, 
        .flip_x = 0,
    };
    return this;
}

void marioUpdateVel(Mario* this, f32 max) {
    this->mPos.y += this->mVel.y;
    this->mColBox.pos = this->mPos;
    if (this->mVel.y > max) {
        this->mVel.y = max;
    }
}

bool marioCheckPipeCollision(Mario* this) {
    if (checkIfCollide(&this->mColBox, &pipeTop->mColBox) || checkIfCollide(&this->mColBox, &pipeBottom->mColBox)) {
        return true;
    }
    return false;
}
bool marioCheckScreenCollision(Mario* this) {
    if ((this->mColBox.pos.y + this->mColBox.height) > 208 || this->mColBox.pos.y < 0) {
        return true;
    }
    return false;
}

void marioUpdateGame(Mario* this) {
    if (marioCheckPipeCollision(this) || marioCheckScreenCollision(this)) {
        switchGameState(STATE_ENDSCREEN);
    }
    if (buttons.a) {
        this->mVel.y = -8.0f;
    }
    this->mVel.y += MARIO_GRAVITY;
    
    marioUpdateVel(this, 1.0f);
}
void marioUpdateEndScreen(Mario* this) {
    if (!((this->mColBox.pos.y + this->mColBox.height) > 208)) {
            this->mVel.y = 1.0f;
            marioUpdateVel(this, 1.0f);
    } else {
            this->mVel.y = 0.0f;
    }
}
void marioUpdateTitle(Mario* this) {
    this->mPos = SetVector2(50.0f,120.0f);
    this->mVel  = this->mRot = ZeroVector2();
    
}
void marioUpdate(Mario* this) { 
    switch (curGameState) {
        case STATE_TITLE:
        marioUpdateTitle(this);
        break;
        case STATE_GAME:
        marioUpdateGame(this);
        break;
        case STATE_ENDSCREEN:
        marioUpdateEndScreen(this);
        break;
        case STATE_GAME_PAUSED:
        break;
    }

}


void marioDraw(Mario* this) {
    rdpq_sprite_blit(this->mSprite, this->mPos.x, this->mPos.y, &this->mBlitParams);
    rdpq_set_mode_fill(SetColor(255,0,0,255));
    rdpq_fill_rectangle(this->mColBox.pos.x, this->mColBox.pos.y, (this->mColBox.pos.x + this->mColBox.width), (this->mColBox.pos.y + this->mColBox.height));
    rdpq_set_mode_standard();
}
