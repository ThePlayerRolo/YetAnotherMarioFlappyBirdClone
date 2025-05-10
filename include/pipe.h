#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>


extern float PipeTopX;
extern float PipeTopY; 
extern struct Vector2 PipeTopPos;
extern struct CollisionBox PipeTopColl;
extern struct CollisionBox PipeTopColl2;
void pipe_top_init(void);
void pipe_top_update(void);