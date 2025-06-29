#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();
void dimension (const char *source_path);
void tenth_pixel(const char *source_path);
void second_line(const char *source_path);
void first_pixel(char *source_path);
void print_pixel(const char *filename, int x, int y );
void max_pixel (const char *source_path);
void min_pixel (const char *source_path);
void max_component (const char *source_path, char *choice);
void min_component (const char *source_path, char *choice);
void color_red(const char *source_path);
void color_green(const char *source_path);
void color_blue(const char *source_path);
void rotate_cw(char *filename);
void rotate_acw(char *filename);
void mirror_horizontal(char *filename);
void mirror_vertical(char *filename);
void mirror_total(char *filename);



void color_desaturate (const char *filenames);
void scale_crop (const char *filenames, int x, int y, int width, int height);
void scale_nearest (const char *filenames,float scale);
void scale_bilinear(const char *filenames,float scale);
void color_gray(const char *source_path);
void color_gray_luminance(const char *source_path);
void color_invert(const char *source_path);














#endif

