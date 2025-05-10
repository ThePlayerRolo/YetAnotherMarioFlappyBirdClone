#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>

int max(int a, int b);
int min(int a, int b);
void loadGameSprite(int  SpriteINT, sprite_t  * Sprite,  char * File);
bool Collision_Check(struct CollisionBox * firstbox, struct CollisionBox * secondBox );