#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>
#include "../include/main.h"


float MarioX;
float MarioY; 
struct Vector2 MarioPos;
struct CollisionBox MarioColl;
int ActiveMarioFlag;

//Initalize Mario
void mario_init() {
    ActiveMarioFlag = FLAG_ACTIVE;
    MarioX = 40;
    MarioY = 50;
    MarioColl.vec1.x = MarioPos.x; 
    MarioColl.vec1.y = MarioPos.y; 
    MarioColl.vec2.x = MarioPos.x + 16; 
    MarioColl.vec2.y = MarioPos.y; 
    MarioColl.vec3.x = MarioPos.x + 16; 
    MarioColl.vec3.y = MarioPos.y + 16; 
    MarioColl.vec4.x = MarioPos.x; 
    MarioColl.vec4.y = MarioPos.y + 16; 

}

//FLAG_ACTIVE code
void mario_flag_active(joypad_buttons_t * buttons) {
    if (buttons->a && MarioY >= 20) {
        MarioY -= 30;
    }
    //if (MarioY <= 193) {
        MarioY++;
    //}
}


void mario_collison(struct CollisionBox * secondBox ) {
    //Vector 1 (Top Left) Y
    int vec1diffy = MarioColl.vec1.y - secondBox->vec1.y;
    int vec1diffy2 =  secondBox->vec1.y - MarioColl.vec1.y;
    //Vector 1 (Top Left) X
    int vec1diffx = MarioColl.vec1.x -  secondBox->vec1.x;
    int vec1diffx2 = secondBox->vec1.x - MarioColl.vec1.x;
    //Vector 2 (Top Right) Y
    int vec2diffy = MarioColl.vec2.y - secondBox->vec2.y;
    int vec2diffy2 =  secondBox->vec2.y - MarioColl.vec2.y;
    //Vector 2 (Top Right) X
    int vec2diffx = MarioColl.vec2.x - secondBox->vec2.x;
    int vec2diffx2 = secondBox->vec2.x - MarioColl.vec2.x;
    //Vector 3 (Bottom Right) Y
    int vec3diffy = MarioColl.vec3.y - secondBox->vec3.y;
    int vec3diffy2 = secondBox->vec3.y - MarioColl.vec3.y;
    //Vector 3 (Bottom Right) X
    int vec3diffx = MarioColl.vec3.x - secondBox->vec3.x;
    int vec3diffx2 = secondBox->vec3.x - MarioColl.vec3.x;
    //Vector 4 (Bottom Left) Y
    int vec4diffy = MarioColl.vec4.y -  secondBox->vec4.y;
    int vec4diffy2 = secondBox->vec4.y - MarioColl.vec4.y;
    //Vector 4 (Bottom Left) X
    int vec4diffx = MarioColl.vec4.x - secondBox->vec4.x;
    int vec4diffx2 = secondBox->vec4.x - MarioColl.vec4.x;
    //vec1diffy > vec1diffy2 || vec2diffy > vec2diffy2 || vec3diffy2 < vec3diffy || vec4diffy2 < vec4diffy
    if (vec1diffy > vec1diffy2 || vec2diffy > vec2diffy2 || vec3diffy2 < vec3diffy || vec4diffy2 < vec4diffy) {
        ActiveMarioFlag = FLAG_DEAD;
    }

};

//Overall Mario_Update Function
void mario_update(joypad_buttons_t * buttons) {
    mario_collison(&GroundColl);
    //TODO: Switch to a switch case for optimization
    if (ActiveMarioFlag == FLAG_ACTIVE) {
        mario_flag_active(buttons);
    }
    MarioPos.x = MarioX;
    MarioPos.y = MarioY;
    MarioColl.vec1.x = MarioPos.x; 
    MarioColl.vec1.y = MarioPos.y; 
    MarioColl.vec2.x = MarioPos.x + 16; 
    MarioColl.vec2.y = MarioPos.y; 
    MarioColl.vec3.x = MarioPos.x + 16; 
    MarioColl.vec3.y = MarioPos.y + 16; 
    MarioColl.vec4.x = MarioPos.x; 
    MarioColl.vec4.y = MarioPos.y + 16; 
}

