#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension (const char *source_path){
    int width, height,n;
    unsigned char *data ;
    read_image_data(source_path, &data, &width, &height, &n);
    printf("dimension: %d, %d", width, height);
}

void second_line(const char *source_path){
    int width, height,n;
    unsigned char *data ;
    read_image_data(source_path, &data, &width, &height, &n);
    printf("second_line: %d, %d, %d",data[1*width*n],data[1*width*n+1],data[1*width*n+2]);

}

void print_pixel(const char *source_path,int x, int y){
    int width, height,n,pixel;
    unsigned char *data ;
    read_image_data(source_path, &data, &width, &height, &n);
    if(x>=width){
        printf("Erreur pixel en dehors de l'image");
    }
    if(y>=height){
        printf("Erreur pixel en dehors de l'image");
    }

    pixel=((y-1)*height+(x-1))*n;

    printf("(%d, %d) %d, %d, %d",x,y,data[pixel],data[pixel+1],data[pixel+2]);

}
