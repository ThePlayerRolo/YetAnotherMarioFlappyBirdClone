#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "../include/types.h"
#include "../include/collison.h"


CollisionBox initCollisionBox(Vector2 Pos, f32 width, f32 height) {
    CollisionBox Box;
    Box.pos = Pos;
    Box.width = width;
    Box.height = height;
    return Box;
}

//Uses raylibs implementation as reference: https://github.com/raysan5/raylib/blob/ca33d495b334232c073a5778869c68400c2022fa/src/rshapes.c#L2271
bool checkIfCollide(CollisionBox *firstbox, CollisionBox *secondBox) {
    bool isCollide = false;
    if (firstbox->pos.x < (secondBox->pos.x + secondBox->width) && (firstbox->pos.x + firstbox->width)  > secondBox->pos.x &&
        firstbox->pos.y < (secondBox->pos.y + secondBox->height) && (firstbox->pos.y + firstbox->height)  > secondBox->pos.y) {
            isCollide = true;
    }
    return isCollide;
}
