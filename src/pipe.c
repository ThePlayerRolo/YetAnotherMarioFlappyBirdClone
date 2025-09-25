#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "../include/types.h"
#include "../include/collison.h"
#include "../include/util.h"
#include "../include/pipe.h"
#include "../include/game.h"

Pipe* pipeBottom;
Pipe* pipeTop;


//Uses Vector2 Because I said so
const Vector2 PipeYValues[3] = {
    {160.0f, -17.0f}, //Middle
    {160.0f, -17.0f}, //Top
    {160.0f, -17.0f}, //Bottom
};


Pipe* pipeInit(Vector2 pPos, bool pIsTop) {
    Pipe* this = malloc(sizeof(Pipe));
    this->mPos = pPos;
    this->mVel  = ZeroVector2();
    this->mColBox = initCollisionBox(this->mPos, 50, 112);
    this->mSprite = sprite_load("rom://Pipe.sprite");
    this->mIsTopPipe = pIsTop;
    this->mBlitParams = (rdpq_blitparms_t) {
        .s0 = 0, 
        .cx = 0,
        .cy = 0,
        .width = 0, 
        .flip_y = pIsTop,
    };

    return this;    
}

void pipeReset(Pipe* this, int index) {
    this->mPos.x = PIPE_START;
     if (this->mIsTopPipe) {
        this->mPos.y = PipeYValues[index].y;     
    } else {
        this->mPos.y = PipeYValues[index].x;
    }
    this->mColBox.pos = this->mPos;
}
void pipeGameUpdate(Pipe* this) {
    this->mVel.x = -1.0f;
    this->mPos.x += this->mVel.x;
    this->mColBox.pos = this->mPos;
    if (this->mPos.x <  -64.0f) {
        pipeReset(this, 0);
    }

}


void pipeUpdate(Pipe* this) {

    switch (curGameState) {
        case STATE_TITLE:
        //pipeReset(this, 0);
        break;
        case STATE_GAME:
        pipeGameUpdate(this);
        break;
        case STATE_ENDSCREEN:
        case STATE_GAME_PAUSED:
        break;
    }
}

void pipeDraw(Pipe* this) {
    rdpq_sprite_blit(this->mSprite, this->mPos.x, this->mPos.y, &this->mBlitParams);
    rdpq_set_mode_fill(SetColor(255,0,0,255));
    rdpq_fill_rectangle(this->mColBox.pos.x, this->mColBox.pos.y, (this->mColBox.pos.x + this->mColBox.width), (this->mColBox.pos.y + this->mColBox.height));
    rdpq_set_mode_standard();
}