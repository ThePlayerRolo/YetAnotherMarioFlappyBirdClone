#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>

//Vector 2
struct Vector2 {
    float x;
    float y;
};

//Collison Box Object.
struct CollisionBox {
    //Top Left
    struct Vector2 vec1;
    //Top Right
    struct Vector2 vec2;
    //Bottom Right
    struct Vector2 vec3;
    //Bottom Left
    struct Vector2 vec4;
};