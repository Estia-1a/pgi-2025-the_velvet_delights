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

    pixel=((y)*width+(x))*n;

    printf("print_pixel (%d, %d) %d, %d, %d",x,y,data[pixel],data[pixel+1],data[pixel+2]);

}


void max_pixel (const char *source_path){
    int width, height,n,x,xp,y,yp,R,G,B,pixel;
    unsigned char *data ;
    R=0;
    G=0;
    B=0;
    xp=1;
    yp=1;
    read_image_data(source_path, &data, &width, &height, &n);

    for(y=0;y<(height);y++){
        for(x=0;x<(width);x++){
            pixel=((y)*width+(x))*n;
            if (data[pixel]+data[pixel+1]+data[pixel+2]>(R+G+B)){
                xp=x;
                yp=y;
                R=(data[pixel]);
                G=(data[pixel+1]);
                B=(data[pixel+2]);
            }
        }
    }
    printf("max_pixel (%d, %d): %d, %d, %d",xp,yp,R,G,B);

}