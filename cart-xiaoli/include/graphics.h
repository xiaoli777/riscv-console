#ifndef _GRAPHICS_H
#define _GRAPHICS_H

void generate_palette(struct palette *pal);
void destroy_palette(struct palette *pal);
int load_background(char *filename, struct background *bg);
int update_backgroud(char *filename, struct background *bg);
int generate_image(struct image *img);
int refresh_images(struct image *img);
void destroy_images(struct image *img);
void graphics2text();

#endif