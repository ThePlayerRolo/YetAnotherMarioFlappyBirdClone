#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>
#include "../include/main.h"

int score;
int highscore;
float ScoreBoxX;
float ScoreBoxY; 
struct Vector2 ScoreBoxPos;
struct CollisionBox ScoreBoxColl;
int ActiveScoreFlag;

void score_init() {
    score = 0;
    /* TODO: Set this to saved memory*/
    highscore = 0;
    
}