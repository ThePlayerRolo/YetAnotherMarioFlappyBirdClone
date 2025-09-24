#pragma once

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "types.h"

typedef struct {
    Vector2  pos;
    f32 width;
    f32 height;
} CollisionBox;

CollisionBox initCollisionBox(Vector2 Pos, f32 width, f32 height);
bool checkIfCollide(CollisionBox*, CollisionBox*);
