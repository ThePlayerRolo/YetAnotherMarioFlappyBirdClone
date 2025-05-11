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
    ActiveMarioFlag = FLAG_PAUSED;
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
        MarioY++;
}
void mario_collison() {
    int PipeTopCheck = Collision_Check(&MarioColl, &PipeTopColl);
    int PipeBottomCheck = Collision_Check(&MarioColl, &PipeBottomColl);
    if (PipeTopCheck == 1 || PipeBottomCheck == 1) {
        ActiveMarioFlag = FLAG_DEAD;
    }


}
//Overall Mario_Update Function
void mario_update(joypad_buttons_t * buttons) {
    //Collision_Check(&MarioColl, &GroundColl);
    //TODO: Switch to a switch case for optimization
    switch (ActiveMarioFlag)
    {
    case FLAG_ACTIVE:
        if (BoolStart == 0) {
            ActiveMarioFlag = FLAG_PAUSED;
        }
        mario_collison();
        mario_flag_active(buttons);
        break;
    
    case FLAG_PAUSED:
        if (BoolStart == 1) {
            ActiveMarioFlag = FLAG_ACTIVE;
        }
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

