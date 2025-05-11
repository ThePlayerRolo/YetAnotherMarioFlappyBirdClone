
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>
#include "../include/main.h"


float PipeTopX;
float PipeTopY; 
float PipeBottomX;
float PipeBottomY;
int ActivePipeFlag;
struct Vector2 PipeBottomPos;
struct Vector2 PipeTopPos;
struct CollisionBox PipeTopColl;
struct CollisionBox PipeBottomColl;






void pipe_top_init() {
    ActivePipeFlag = PIPE_FLAG_ACTIVE;
    PipeTopX = 330;
    PipeTopY = -20;
    PipeTopPos.x = PipeTopX;
    PipeTopPos.y = PipeTopY;
    PipeTopColl.vec1.x = PipeTopPos.x + 5;
    PipeTopColl.vec1.y = PipeTopPos.y;
    PipeTopColl.vec2.x = PipeTopPos.x + 35;
    PipeTopColl.vec2.y = PipeTopPos.y;
    PipeTopColl.vec3.x = PipeTopPos.x + 35;
    PipeTopColl.vec3.y = PipeTopPos.y + 80;
    PipeTopColl.vec4.x = PipeTopPos.x + 5;
    PipeTopColl.vec4.y = PipeTopPos.y + 80;

};


void pipe_top_update() {
    if (ActivePipeFlag == PIPE_FLAG_ACTIVE) {
        if (BoolStart == 0) {
            ActivePipeFlag = PIPE_FLAG_PAUSED;
        }
        if (PipeTopPos.x <= -50) {
            PipeTopX = 330;
            PipeTopY = 20;
        }
        PipeTopX--;
    } else {
        if (BoolStart == 1) {
            ActivePipeFlag = PIPE_FLAG_ACTIVE;
        }
    }
    PipeTopPos.x = PipeTopX;
    PipeTopPos.y = PipeTopY;
    PipeTopColl.vec1.x = PipeTopPos.x + 5;
    PipeTopColl.vec1.y = PipeTopPos.y;
    PipeTopColl.vec2.x = PipeTopPos.x + 35;
    PipeTopColl.vec2.y = PipeTopPos.y;
    PipeTopColl.vec3.x = PipeTopPos.x + 35;
    PipeTopColl.vec3.y = PipeTopPos.y + 80;
    PipeTopColl.vec4.x = PipeTopPos.x + 5;
    PipeTopColl.vec4.y = PipeTopPos.y + 80;
}

void pipe_bottom_init() {
    PipeBottomX = 330;
    PipeBottomY = 130;
    PipeBottomPos.x = PipeBottomX;
    PipeBottomPos.y = PipeBottomY;
    PipeBottomColl.vec1.x = PipeBottomPos.x + 5;
    PipeBottomColl.vec1.y = PipeBottomPos.y;
    PipeBottomColl.vec2.x = PipeBottomPos.x + 35;
    PipeBottomColl.vec2.y = PipeBottomPos.y;
    PipeBottomColl.vec3.x = PipeBottomPos.x + 35;
    PipeBottomColl.vec3.y = PipeBottomPos.y + 80;
    PipeBottomColl.vec4.x = PipeBottomPos.x + 5;
    PipeBottomColl.vec4.y = PipeBottomPos.y + 80;

};
void pipe_bottom_update() {
    if (ActivePipeFlag == PIPE_FLAG_ACTIVE) {
       if (PipeBottomPos.x <= -50) {
            PipeBottomX = 330;
            PipeBottomY = 130;
        }
        PipeBottomX--;
    }
    PipeBottomPos.x = PipeBottomX;
    PipeBottomPos.y = PipeBottomY;
    PipeBottomColl.vec1.x = PipeBottomPos.x + 5;
    PipeBottomColl.vec1.y = PipeBottomPos.y;
    PipeBottomColl.vec2.x = PipeBottomPos.x + 35;
    PipeBottomColl.vec2.y = PipeBottomPos.y;
    PipeBottomColl.vec3.x = PipeBottomPos.x + 35;
    PipeBottomColl.vec3.y = PipeBottomPos.y + 80;
    PipeBottomColl.vec4.x = PipeBottomPos.x + 5;
    PipeBottomColl.vec4.y = PipeBottomPos.y + 80;
}