#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>

extern float MarioX; 
extern float MarioY; 
extern struct Vector2 MarioPos;
extern struct CollisionBox MarioColl;
extern int ActiveMarioFlag;
void mario_init(void);
void mario_flag_active(joypad_buttons_t * buttons);
void mario_update(joypad_buttons_t * buttons);
enum  MarioFlags {
    FLAG_PAUSED = 0,
    FLAG_ACTIVE = 1,
    FLAG_DEAD = 2
};
