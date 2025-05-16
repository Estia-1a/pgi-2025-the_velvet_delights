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

void second_line(const char *source_path){
    int width, height,n;
    unsigned char *data ;
    read_image_data(source_path, &data, &width, &height, &n);
    printf("second_line: %d, %d, %d",data[1*width*n],data[1*width*n+1],data[1*width*n+2]);

}
