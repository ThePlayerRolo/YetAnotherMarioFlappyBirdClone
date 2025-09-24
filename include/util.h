#pragma once

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "types.h"


color_t SetColor(u8, u8, u8, u8);
Vector2 SetVector2(f32, f32);
Vector2 ZeroVector2();

int max(int a, int b);
int min(int a, int b);
f32 moveToward(f32, f32, f32);