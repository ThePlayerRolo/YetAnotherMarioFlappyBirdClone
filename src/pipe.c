
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
struct Vector2 PipeBottomPos;
struct Vector2 PipeTopPos;
struct CollisionBox PipeTopColl;
struct CollisionBox PipeBottomColl;



void pipe_top_init() {
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
    if (PipeTopPos.x <= -50) {
        PipeTopX = 330;
        PipeTopY = -20;
    }
    if (ActiveMarioFlag != FLAG_DEAD) {
        PipeTopX--;
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
    if (PipeBottomPos.x <= -50) {
        PipeBottomX = 330;
        PipeBottomY = 130;
    }
    if (ActiveMarioFlag != FLAG_DEAD) {
        PipeBottomX--;
    }

    PipeBottomPos.x = PipeBottomX;
    PipeBottomPos.y = PipeBottomY;
    PipeTopColl.vec1.x = PipeBottomPos.x + 5;
    PipeTopColl.vec1.y = PipeBottomPos.y;
    PipeTopColl.vec2.x = PipeBottomPos.x + 35;
    PipeTopColl.vec2.y = PipeBottomPos.y;
    PipeTopColl.vec3.x = PipeBottomPos.x + 35;
    PipeTopColl.vec3.y = PipeBottomPos.y + 80;
    PipeTopColl.vec4.x = PipeBottomPos.x + 5;
    PipeTopColl.vec4.y = PipeBottomPos.y + 80;
}