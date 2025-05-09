#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>
#include "../include/main.h"


float MarioX;
float MarioY; 
struct Vector2 MarioPos;
int ActiveMarioFlag;

//Initalize Mario
void mario_init() {
    ActiveMarioFlag = FLAG_ACTIVE;
    MarioX = 40;
    MarioY = 50;
}

//FLAG_ACTIVE code
void mario_flag_active(joypad_buttons_t * buttons) {
    if (buttons->a && MarioY >= 20) {
        MarioY -= 30;
    }
    if (MarioY <= 193) {
        MarioY++;
    } else {
        ActiveMarioFlag = FLAG_DEAD;
    }
}

//Overall Mario_Update Function
void mario_update(joypad_buttons_t * buttons) {
    //TODO: Switch to a switch case for optimization
    if (ActiveMarioFlag == FLAG_ACTIVE) {
        mario_flag_active(buttons);
    }
    MarioPos.x = MarioX;
    MarioPos.y = MarioY;
}

