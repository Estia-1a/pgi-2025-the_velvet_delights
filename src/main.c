#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include "utils.h"
#include "argsparse.h"

int main(int argc, char **argv) {
  /*To use debug mode: 
   - add --debug: freud.exe --debug -f images/input/image.jpeg
   or
   - Simply run your compiled project with start button on the blue menu bar at the bottom of the VS Code window.
   */

  /*DO NOT EDIT THIS PART*/
  Config configuration ;
  parse_arguments( argc, argv, &configuration ) ;
  check_debug_mode(configuration);
  check_file();
  /* END */

  /* Use "if ( strncmp( command, <commandname>, 9 ) == 0 )" to check if your <commandname> is called by program.*/
  /* Example with helloworld command
   * If helloworld is a called command: freud.exe -f images/input/image.jpeg -c helloworld 
   */
  if ( strncmp( configuration.command, "helloworld", 10 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    helloWorld();
  }
  /*
   * TO COMPLETE
   */
  if ( strncmp( configuration.command, "dimension", 9 ) == 0 ) {
    /* dimension (char *source_path) function is defined in feature.h and implemented in feature.c */
    dimension (configuration.filenames[0]);
  
  }

  if ( strncmp( configuration.command, "tenth_pixel", 11 ) == 0 ) {
    /* ten_pixel (char *source_path) function is defined in feature.h and implemented in feature.c */
    tenth_pixel (configuration.filenames[0]);
  
  }

  if ( strncmp( configuration.command, "color_red", 9 ) == 0 ) {
    /* color_red(const char *source_path) function is defined in feature.h and implemented in feature.c */
    color_red(configuration.filenames[0]);
  
  }
  if ( strncmp( configuration.command, "color_green", 11 ) == 0 ) {
    /* color_green(const char *source_path) function is defined in feature.h and implemented in feature.c */
    color_green(configuration.filenames[0]);
  }
  if ( strncmp( configuration.command, "color_blue", 10 ) == 0 ) {
    /* color_blue(const char *source_path) function is defined in feature.h and implemented in feature.c */
    color_blue(configuration.filenames[0]);
  
  }

  if ( strncmp( configuration.command, "couleur_gris", 12 ) == 0 ) {
    /* couleur_gris(const char *source_path) function is defined in feature.h and implemented in feature.c */
    couleur_gris(configuration.filenames[0]);
  
  }

  if ( strncmp( configuration.command, "couleur_gris_luminance", 22 ) == 0 ) {
    /* couleur_gris_luminance(const char *source_path) function is defined in feature.h and implemented in feature.c */
    couleur_gris_luminance(configuration.filenames[0]);
  
  }


  if (strncmp(configuration.command, "first_pixel", 11) == 0) {
    /*Ajout de la commande first_pixel*/
    first_pixel(configuration.filenames[0]);
  }
  if ( strncmp( configuration.command, "print_pixel", 11 ) == 0 ) {
    /* second_line(char *source_path); function is defined in feature.h and implemented in feature.c */
    int x,y;
    x=atoi(configuration.arguments[0]);
    y=atoi(configuration.arguments[1]);

    print_pixel(configuration.filenames[0],x,y);
  }

  if ( strncmp( configuration.command, "max_pixel", 9 ) == 0 ) {
    /* dimension (char *source_path) function is defined in feature.h and implemented in feature.c */
    max_pixel (configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "min_pixel", 9 ) == 0 ) {
    /* dimension (char *source_path) function is defined in feature.h and implemented in feature.c */
    min_pixel (configuration.filenames[0]);
  }

  if ( strncmp( configuration.command, "max_component", 13 ) == 0 ) {
    /* dimension (char *source_path) function is defined in feature.h and implemented in feature.c */
    char *choice;
    choice=configuration.arguments[0];
    max_component (configuration.filenames[0],choice);
  }

  if ( strncmp( configuration.command, "min_component", 13 ) == 0 ) {
    /* dimension (char *source_path) function is defined in feature.h and implemented in feature.c */
    char *choice;
    choice=configuration.arguments[0];
    min_component (configuration.filenames[0],choice);
  }
  if (strncmp(configuration.command, "rotate_cw", 9) == 0) {
    rotate_cw(configuration.filenames[0]);
  }
  if (strncmp(configuration.command, "rotate_acw", 10) == 0) {
    rotate_acw(configuration.filenames[0]);
  }
  if (strncmp(configuration.command, "mirror_horizontal", 17) == 0) {
    mirror_horizontal(configuration.filenames[0]);
  }


  if ( strncmp( configuration.command, "color_desaturate", 16 ) == 0 ) {
    /* ten_pixel (char *source_path) function is defined in feature.h and implemented in feature.c */
    color_desaturate (configuration.filenames[0]);
  
  }


  if (strncmp(configuration.command, "second_line", 11) == 0) {
    second_line(configuration.filenames[0]);
  }

  if (strncmp(configuration.command, "scale_crop", 10) == 0) {
    int x,y,width,height;

    x=atoi(configuration.arguments[0]);
    y=atoi(configuration.arguments[1]);
    width=atoi(configuration.arguments[2]);
    height=atoi(configuration.arguments[3]);

    scale_crop(configuration.filenames[0],x,y,width,height);
  }
  
  return 0;
}



