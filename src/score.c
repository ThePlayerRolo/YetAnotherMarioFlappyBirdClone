#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "../include/main.h"

int score;
int highscore;
int ScoreDebounce;
float ScoreBoxX;
float ScoreBoxY; 
struct Vector2 ScoreBoxPos;
struct CollisionBox ScoreBoxColl;
int ActiveScoreFlag;

void score_init() {
    score = 0;
    /* TODO: Set this to saved memory using low level*/
    highscore = 0;
    
}

void score_box_init() {
    //First is PipeTopPos.x, 60  Second is PipeTop.x + 19,60   3RD is  PipeTop.x + 19,129  4th is PipeTop.x,129 
    ActiveScoreFlag = SCORE_FLAG_PAUSED;
    ScoreDebounce = 0;
    ScoreBoxX = 350;
    ScoreBoxY = 50;
    ScoreBoxPos.x = ScoreBoxX;
    ScoreBoxPos.y = ScoreBoxY;
    ScoreBoxColl.vec1.x = ScoreBoxPos.x - 20;
    ScoreBoxColl.vec1.y = ScoreBoxPos.y;
    ScoreBoxColl.vec2.x = ScoreBoxPos.x + 19;
    ScoreBoxColl.vec2.y = ScoreBoxPos.y;
    ScoreBoxColl.vec3.x = ScoreBoxPos.x + 19;
    ScoreBoxColl.vec3.y = ScoreBoxPos.y + 69;
    ScoreBoxColl.vec4.x = ScoreBoxPos.x - 20;
    ScoreBoxColl.vec4.y = ScoreBoxPos.y + 69;
}


void score_box_update() {
        switch (ActiveScoreFlag) {
        case SCORE_FLAG_ACTIVE:
            if (BoolStart == 0) {
                ActiveScoreFlag = SCORE_FLAG_PAUSED;
            }
            if (ScoreBoxPos.x <= -50) {
                //Middle: 60 Top:30 Bottom: 90
                ScoreBoxX = 350;
                ScoreBoxY = 90;
                ScoreDebounce = 0;
                
            }
            ScoreBoxX--;
            break;
        case SCORE_FLAG_PAUSED:
            if (BoolStart == 1) {
                ActiveScoreFlag = SCORE_FLAG_ACTIVE;
            }
            break;

    }
    ScoreBoxPos.x = ScoreBoxX;
    ScoreBoxPos.y = ScoreBoxY;
    ScoreBoxColl.vec1.x = ScoreBoxPos.x;
    ScoreBoxColl.vec1.y = ScoreBoxPos.y;
    ScoreBoxColl.vec2.x = ScoreBoxPos.x + 19;
    ScoreBoxColl.vec2.y = ScoreBoxPos.y;
    ScoreBoxColl.vec3.x = ScoreBoxPos.x + 19;
    ScoreBoxColl.vec3.y = ScoreBoxPos.y + 69;
    ScoreBoxColl.vec4.x = ScoreBoxPos.x;
    ScoreBoxColl.vec4.y = ScoreBoxPos.y + 69;
}