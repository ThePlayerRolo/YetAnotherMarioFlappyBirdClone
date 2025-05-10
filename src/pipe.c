
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>
#include "../include/main.h"


float PipeTopX;
float PipeTopY; 
struct Vector2 PipeTopPos;
struct CollisionBox PipeTopColl;
struct CollisionBox PipeTopColl2;

//Vec1: 235,90 Vec2: 265,90 Vec3: 265,155 Vec4: 235,155

void pipe_top_init() {
    PipeTopX = 230;
    PipeTopY = 20;
    PipeTopPos.x = PipeTopX;
    PipeTopPos.y = PipeTopY;
    PipeTopColl.vec1.x = PipeTopPos.x + 5;
    PipeTopColl.vec1.y = PipeTopPos.y;
    PipeTopColl.vec2.x = PipeTopPos.x + 35;
    PipeTopColl.vec2.y = PipeTopPos.y;
    PipeTopColl.vec3.x = PipeTopPos.x + 35;
    PipeTopColl.vec3.y = PipeTopPos.y + 65;
    PipeTopColl.vec4.x = PipeTopPos.x + 5;
    PipeTopColl.vec4.y = PipeTopPos.y + 65;

};

void pipe_top_update() {
    if (PipeTopPos.x <= -20) {
        PipeTopX = 230;
        PipeTopY = 20;
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
    PipeTopColl.vec3.y = PipeTopPos.y + 65;
    PipeTopColl.vec4.x = PipeTopPos.x + 5;
    PipeTopColl.vec4.y = PipeTopPos.y + 65;
}