#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "../include/main.h"


/*LIBRARY FOR FUNCTIONS FOR THIS GAME */

int max(int a, int b) {
    return (a > b) ? a : b;
}
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Collision Code
bool Collision_Check(struct CollisionBox *firstbox, struct CollisionBox *secondBox)
{
    // Right is +, Left is - Up is - and Down is +
    //TODO: Make this not need the extra addition/subtraction
    if (firstbox->vec1.y >= secondBox->vec1.y && firstbox->vec3.y <= secondBox->vec3.y){
        if (secondBox->vec2.x >= firstbox->vec2.x  &&  secondBox->vec1.x <= firstbox->vec1.x) {
            return 1;

        }
    }
    return 0;
}

