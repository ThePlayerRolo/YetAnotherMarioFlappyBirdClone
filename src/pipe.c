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

Pipe* BottomPipes[PIPE_COUNT];
Pipe* TopPipes[PIPE_COUNT];

const f32 BottomPipeY[PIPE_COUNT] =  {
    140.0f,
    100.0f,
    160.0f,
    120.0f
};

const f32 BasePipeX[PIPE_COUNT] = {
    360.0f,
    460.0f,
    560.0f,
    660.0f
};

Pipe* pipeInit(Vector2 pPos, bool pIsTop, u8 pGroup) {
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
    this->mGroup = pGroup;
    this->startPosX = pPos.x;
    return this;    
}

void pipeReset(Pipe* this) {
    if (curGameState == STATE_TITLE) {
        this->mPos.x = BasePipeX[this->mGroup];
    } else {
        this->mPos.x = 360;
    }

     if (this->mIsTopPipe) {
        this->mPos.y = BottomPipes[this->mGroup]->mPos.y - 188;     
    } else {
        if (curGameState == STATE_TITLE) {
            this->mPos.y = BottomPipeY[this->mGroup];
        } else {
            this->mPos.y = (rand() % 90) + 100;
        }
    }
    this->mColBox.pos = this->mPos;
}

void pipeGameUpdate(Pipe* this) {
    this->mVel.x = -1.0f;
    this->mPos.x += this->mVel.x;
    this->mColBox.pos = this->mPos;
    if (this->mPos.x <  -64.0f) {
        pipeReset(this);
    }
}


void pipeUpdate(Pipe* this) {

    switch (curGameState) {
        case STATE_TITLE:
       pipeReset(this);
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
    if (this->mPos.x > -64.0f && this->mPos.x < 330.0f) {
        rdpq_sprite_blit(this->mSprite, this->mPos.x, this->mPos.y, &this->mBlitParams);
    }
   /*rdpq_set_mode_fill(SetColor(255,0,0,255));
    rdpq_fill_rectangle(this->mColBox.pos.x, this->mColBox.pos.y, (this->mColBox.pos.x + this->mColBox.width), (this->mColBox.pos.y + this->mColBox.height));
    rdpq_set_mode_standard();
    	rdpq_mode_alphacompare(1);*/
}

void pipeTopArrayInit() {
    for (u8 i = 0; i < PIPE_COUNT; i++) {
        Vector2 Pos;
        Pos.x = BasePipeX[i];
        Pos.y = BottomPipes[i]->mPos.y - 188;

        
        TopPipes[i] = pipeInit(Pos, true, i);
    }
}

void pipeBottomArrayInit() {
    for (u8 i = 0; i < PIPE_COUNT; i++) {
        Vector2 Pos;
        Pos.x = BasePipeX[i];
        Pos.y = BottomPipeY[i];
        
        BottomPipes[i] = pipeInit(Pos, false, i);
    }
}
void pipeArrayInit() {
    pipeBottomArrayInit();
    pipeTopArrayInit();
}
void pipeArrayUpdate() {
    for (u8 i = 0; i < PIPE_COUNT; i++) {
        if (BottomPipes[i] != 0) {
            pipeUpdate(BottomPipes[i]);
        }
    }
    for (u8 i = 0; i < PIPE_COUNT; i++) {
        if (TopPipes[i] != 0) {
            pipeUpdate(TopPipes[i]);
        }
    }
}

void pipeArrayDraw() {
     for (u8 i = 0; i < PIPE_COUNT; i++) {
        if (BottomPipes[i] != 0) {
            pipeDraw(BottomPipes[i]);
        }
    }
    for (u8 i = 0; i < PIPE_COUNT; i++) {
        if (TopPipes[i] != 0) {
            pipeDraw(TopPipes[i]);
        }
    }   
}

void pipeArrayFree() {
    for (u8 i = 0; i < PIPE_COUNT; i++) {
        if (BottomPipes[i] != 0) {
            free(BottomPipes[i]);
        }
    }
    for (u8 i = 0; i < PIPE_COUNT; i++) {
        if (TopPipes[i] != 0) {
            free(TopPipes[i]);
        }
    }   
}