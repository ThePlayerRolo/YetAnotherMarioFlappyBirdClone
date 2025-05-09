#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>


struct Vector2 {
    float x;
    float y;
};


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