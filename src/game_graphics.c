#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>


void loadGameSprite(int  SpriteINT, sprite_t * Sprite,  char *  File) {
    	SpriteINT = dfs_open(File);
	    Sprite = malloc(dfs_size(SpriteINT));
	    dfs_read(Sprite, 1, dfs_size(SpriteINT), SpriteINT);
	    dfs_close(SpriteINT);

}