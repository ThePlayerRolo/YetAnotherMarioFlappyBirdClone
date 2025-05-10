#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>


extern float PipeTopX;
extern float PipeTopY; 
extern float PipeBottomX;
extern float PipeBottomY;
extern struct Vector2 PipeBottomPos;
extern struct Vector2 PipeTopPos;
extern struct CollisionBox PipeTopColl;
extern struct CollisionBox PipeBottomColl;
void pipe_top_init(void);
void pipe_top_update(void);
void pipe_bottom_init(void);
void pipe_bottom_update(void);