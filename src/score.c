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
#include "../include/mario.h"
#include "../include/score.h"

u8 gameScore = 0;
u8 highScore = 0;

ScoreBox* scoreBoxInit(Vector2 pPos) {
    ScoreBox* newScoreBox = malloc(sizeof(ScoreBox));
    newScoreBox->mPos = pPos;
    newScoreBox->mColBox = initCollisionBox(pPos, 16, 80);
    newScoreBox->curPipe = 0;
    newScoreBox->mDebounce = false;
    return newScoreBox;
}

void scoreBoxGameUpdate(ScoreBox* this) {
    this->mPos.x = BottomPipes[this->curPipe]->mPos.x + 32;
    this->mPos.y = (BottomPipes[this->curPipe]->mPos.y -  80);
    
    if (checkIfCollide(&this->mColBox, &mario->mColBox) && !this->mDebounce) {
        this->mDebounce = true;
        if (gameScore != 255) {
            gameScore++;
        }
        this->curPipe++;
        if (this->curPipe > PIPE_COUNT - 1) {
            this->curPipe = 0;
        }
    } else {
        this->mDebounce = false;
    }
    this->mColBox.pos = this->mPos;
}


void scoreBoxUpdate(ScoreBox* this) {
    switch (curGameState) {
        case STATE_TITLE:
        this->curPipe = 0;
        break;
        case STATE_GAME:
        scoreBoxGameUpdate(this);
        case STATE_ENDSCREEN:
        break;
        case STATE_GAME_PAUSED:
        break;
    }
}

void scoreBoxDraw(ScoreBox* this) {
    rdpq_set_mode_fill(SetColor(255,0,0,255));
    rdpq_fill_rectangle(this->mColBox.pos.x, this->mColBox.pos.y, (this->mColBox.pos.x + this->mColBox.width), (this->mColBox.pos.y + this->mColBox.height));
    rdpq_set_mode_standard();
    rdpq_mode_alphacompare(1); 
}


//Everything below here is bad. Like really bad.
//I wish I could make score's type u32 but I can't figure out a way to convert that to a u8 array
void scoreAddHighScore() {
    u8* buffer = malloc(sizeof(u8));
    eeprom_read(0,buffer);
    highScore = buffer[0];
    free(buffer);
}


void scoreSaveHighScore() {
    u8* buffer = malloc(sizeof(u8));
    buffer[0] = highScore;
    eeprom_write(0,buffer);
    free(buffer);
}


void scoreUpdate() {
    if (curGameState == STATE_TITLE) {
        gameScore = 0;
    } else if (curGameState == STATE_ENDSCREEN) {
        if (gameScore > highScore) {
            highScore = gameScore;
            scoreSaveHighScore();
        }
    }
}

void scoreInit() {
    gameScore = 0;
    bool isFirst = false;
    u8* bufferCheck = malloc( 2 * sizeof(u8));
    eeprom_read(1, bufferCheck);
    if (bufferCheck[0] == 0xFF) {
        bufferCheck[0] = 0;
        eeprom_write(1,bufferCheck);
        isFirst = true;
    }
    free(bufferCheck);

    if (isFirst) {
        highScore = 0;
        scoreSaveHighScore();
    } else {
        scoreAddHighScore();
    }
}