#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>


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

void first_pixel(char *source_path){
        unsigned char *data = NULL;
    int width, height, n;

    /*Lire les données de l’image*/
    if (read_image_data(source_path, &data, &width, &height, &n) != 0) {
        fprintf(stderr, "Erreur : impossible de lire l’image.\n");
        return;
    }

    /* Vérification : il faut au moins 3 canaux pour RGB*/
    if (data == NULL || n < 3) {
        fprintf(stderr, "Erreur : données d’image invalides ou image sans couleur RGB.\n");
        free(data); /* on libère quand même si alloué*/ 
        return;
    }

    /* Le pixel (0,0) est représenté par les 3 premières valeurs de data[]*/
    int R = data[0];
    int G = data[1];
    int B = data[2];

    printf("first_pixel: %d, %d, %d\n", R, G, B);

    /* Libérer la mémoire après utilisation*/
    free(data);

}

