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
