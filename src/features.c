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
    printf("L'image mesure %d x %d pixels", width, height);
}

void tenth_pixel(const char *source_path){
    int width, height,n;
    unsigned char *data ;
    read_image_data(source_path, &data, &width, &height, &n);
    printf("tenth_pixel: %d, %d, %d",data[9*n],data[9*n+1],data[9*n+2]);

}

void color_red(const char *source_path){
    int width, height,n, x, y, pixel   ;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &n);
    for(y=0;y<(height);y++){
        for(x=0;x<(width);x++){
            pixel=((y)*width+(x))*n;
            data[pixel+1]=0;
            data[pixel+2]=0;


        }
    }
    write_image_data("image_out.bmp", data, width, height);

            
        

}