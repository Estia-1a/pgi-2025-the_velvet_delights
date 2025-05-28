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

  if ( strncmp( configuration.command, "color_red", 11 ) == 0 ) {
    /* color_red(const char *source_path) function is defined in feature.h and implemented in feature.c */
    color_red(configuration.filenames[0]);
  
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
  
  

  
  return 0;
}



  
