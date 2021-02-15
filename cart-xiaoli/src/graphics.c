#include <stdio.h>
#include <stdlib.h>

#include "graphics.h"

struct palette {
	int red, green, blue,
}

struct background {
	int type;
	int width, height;
	struct palette pal;
}

struct image { // sprites
	int width, height;
	struct palette pal;
	int left, top; // position
};

void generate_palette(struct palette *pal){
	// 256 * 256 * 256
}

void destroy_palette(struct palette *pal){
	free(pal);
}

int load_background(char *filename, struct background *bg){
	return 0;
}

int update_backgroud(char *filename, struct background *bg){
	return 0;
}

int generate_image(struct image *img){
	return 0;
}

int refresh_images(struct image *img){
	return 0;
}

void destroy_images(struct image *img){
	free(img);
}

void graphics2text(){

}