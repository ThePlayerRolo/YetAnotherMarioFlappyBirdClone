#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <libdragon.h>
#include "../include/types.h"
#include "../include/font.h"

rdpq_font_t* delfinoFont;


void FontInit() {
    delfinoFont = rdpq_font_load("rom://Delfino.font64");
    rdpq_text_register_font(1, delfinoFont);
    rdpq_font_style(delfinoFont, 0, &(rdpq_fontstyle_t){
	.color = RGBA32(255, 255, 255, 255),
	.outline_color = RGBA32(0, 0, 0, 255),
	});
}