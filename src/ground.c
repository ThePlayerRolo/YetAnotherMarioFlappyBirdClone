#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "../include/main.h"


struct CollisionBox GroundColl;

void GroundInit() {
    GroundColl.vec1.x = 0;
    GroundColl.vec1.y = 195;
    GroundColl.vec2.x = 320;
    GroundColl.vec2.y = 195;
    GroundColl.vec3.x = 0;
    GroundColl.vec3.y = 235;
    GroundColl.vec4.x = 320;
    GroundColl.vec4.y = 235;
}