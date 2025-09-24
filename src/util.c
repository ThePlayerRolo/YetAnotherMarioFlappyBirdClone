#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "../include/util.h"
#include "../include/types.h"


color_t SetColor(u8 r, u8 g , u8 b, u8 a) {
    color_t newColor;
    newColor.r = r;
    newColor.g = g;
    newColor.b  = b;
    newColor.a = a;
    return newColor;
}

Vector2 SetVector2(f32 x, f32 y) {
    Vector2 vec;
    vec.x = x;
    vec.y = y;
    return vec;
}

Vector2 ZeroVector2() {
    Vector2 vec = SetVector2(0.0f, 0.0f);
    return vec;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}
int min(int a, int b) {
    return (a < b) ? a : b;
}
