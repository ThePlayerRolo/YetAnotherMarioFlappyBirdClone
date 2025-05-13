#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>

extern int score;
extern int highscore;
extern int ScoreDebounce;
extern float ScoreBoxX;
extern float ScoreBoxY; 
extern struct Vector2 ScoreBoxPos;
extern struct CollisionBox ScoreBoxColl;
extern int ActiveScoreFlag;

enum ScoreFlags {
    SCORE_FLAG_PAUSED = 0,
    SCORE_FLAG_ACTIVE = 1,
    SCORE_FLAG_DEAD = 2
};
void score_init(void);
void score_box_init(void);
void score_box_update(void);
