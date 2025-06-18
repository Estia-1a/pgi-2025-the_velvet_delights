#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


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

void tenth_pixel(const char *source_path){
    int width, height,n;
    unsigned char *data ;
    read_image_data(source_path, &data, &width, &height, &n);
    printf("tenth_pixel: %d, %d, %d",data[9*n],data[9*n+1],data[9*n+2]);

}

void second_line(const char *source_path){
    int width, height,n,pixel;
    unsigned char *data ;
    read_image_data(source_path, &data, &width, &height, &n);
    pixel=((1)*width+(0))*n;
    printf("second_line: %d, %d, %d",data[pixel],data[pixel+1],data[pixel+2]);

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

void color_green(const char *source_path){
    int width, height,n, x, y, pixel   ;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &n);
    for(y=0;y<(height);y++){
        for(x=0;x<(width);x++){
            pixel=((y)*width+(x))*n;
            data[pixel+0]=0;
            data[pixel+2]=0;


        }
    }

    write_image_data("image_out.bmp", data, width, height);

            
        

}


void color_blue(const char *source_path){
    int width, height,n, x, y, pixel   ;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &n);
    for(y=0;y<(height);y++){
        for(x=0;x<(width);x++){
            pixel=((y)*width+(x))*n;
            data[pixel+0]=0;
            data[pixel+1]=0;


        }
    }

    write_image_data("image_out.bmp", data, width, height);            
}

void color_gray(const char *source_path){
    int width, height,n, x, y, pixel   ;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &n);
    for(y=0;y<(height);y++){
        for(x=0;x<(width);x++){
            pixel=((y)*width+(x))*n;
            unsigned char r = data[pixel + 0];
            unsigned char v = data[pixel + 1];
            unsigned char b = data[pixel + 2];
            unsigned char moyenne = (r + v + b) / 3;
            data[pixel + 0] = moyenne;
            data[pixel + 1] = moyenne;
            data[pixel + 2] = moyenne;
        }
    }
    write_image_data("image_out.bmp", data, width, height);            
}

void color_gray_luminance(const char *source_path){
    int width, height,n, x, y, pixel   ;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &n);
    for(y=0;y<(height);y++){
        for(x=0;x<(width);x++){
            pixel=((y)*width+(x))*n;
            unsigned char r = data[pixel + 0];
            unsigned char v = data[pixel + 1];
            unsigned char b = data[pixel + 2];
            unsigned char gris_luminance = (unsigned char)(0.21 * r + 0.72 * v + 0.07 * b);
             data[pixel + 0] = gris_luminance;
            data[pixel + 1] = gris_luminance;
            data[pixel + 2] = gris_luminance;
            }
    }
    write_image_data("image_out.bmp", data, width, height);            
}

void color_invert(const char *source_path){
    int width, height,n, x, y, pixel   ;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &n);
    for(y=0;y<(height);y++){
        for(x=0;x<(width);x++){
            pixel=((y)*width+(x))*n;
            data[pixel + 0] = 255 - data[pixel + 0];
            data[pixel + 1] = 255 - data[pixel + 1];
            data[pixel + 2] = 255 - data[pixel + 2];
        }
    }

    write_image_data("image_out.bmp", data, width, height);
}


void first_pixel(char *source_path){
        unsigned char *data = NULL;
    int width, height, n;

    /*Lire les données de l’image*/
    if (read_image_data(source_path, &data, &width, &height, &n) == 0) {
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

    printf("print_pixel (%d,%d) : %d,%d,%d",x,y,data[pixel],data[pixel+1],data[pixel+2]);

}


void max_pixel (const char *source_path){
    int width, height,n,x,xp,y,yp,R,G,B,pixel;
    unsigned char *data ;
    R=0;
    G=0;
    B=0;
    xp=0;
    yp=0;
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


void min_pixel (const char *source_path){
    int width, height,n,x,xp,y,yp,R,G,B,pixel;
    unsigned char *data ;
    R=255;
    G=255;
    B=255;
    xp=0;
    yp=0;
    read_image_data(source_path, &data, &width, &height, &n);

    for(y=0;y<(height);y++){
        for(x=0;x<(width);x++){
            pixel=((y)*width+(x))*n;
            if (data[pixel]+data[pixel+1]+data[pixel+2]<(R+G+B)){
                xp=x;
                yp=y;
                R=(data[pixel]);
                G=(data[pixel+1]);
                B=(data[pixel+2]);
            }
        }
    }
    printf("min_pixel (%d, %d): %d, %d, %d",xp,yp,R,G,B);

}

void max_component (const char *source_path, char *choice){
    int width, height,n,x,xp,y,yp,pixel,C;
    unsigned char *data ;
    C=0;
    xp=0;
    yp=0;
    read_image_data(source_path, &data, &width, &height, &n);
    for(y=0;y<(height);y++){
        for(x=0;x<(width);x++){
            pixel=((y)*width+(x))*n;
            if (*choice =='R'){
                if(data[pixel]>C){
                    C=data[pixel];
                    xp=x;
                    yp=y;
                }                
            }
            if (*choice =='G'){
                if(data[pixel+1]>C){
                    C=data[pixel+1];
                    xp=x;
                    yp=y;
                }    
            }
            if (*choice =='B'){
                if(data[pixel+2]>C){
                    C=data[pixel+2];
                    xp=x;
                    yp=y;
                }  
            }
        }
    }
    printf("max_component %s (%d, %d): %d",choice,xp,yp,C);
    
}

void min_component (const char *source_path, char *choice){
    int width, height,n,x,xp,y,yp,pixel,C;
    unsigned char *data ;
    C=255;
    xp=0;
    yp=0;
    read_image_data(source_path, &data, &width, &height, &n);
    for(y=0;y<(height);y++){
        for(x=0;x<(width);x++){
            pixel=((y)*width+(x))*n;
            if (*choice =='R'){
                if(data[pixel]<C){
                    C=data[pixel];
                    xp=x;
                    yp=y;
                }                
            }
            if (*choice =='G'){
                if(data[pixel+1]<C){
                    C=data[pixel+1];
                    xp=x;
                    yp=y;
                }    
            }
            if (*choice =='B'){
                if(data[pixel+2]<C){
                    C=data[pixel+2];
                    xp=x;
                    yp=y;
                }  
            }
        }
    }
    printf("min_component %s (%d, %d): %d",choice,xp,yp,C);
    
}
void rotate_cw(char *filename) {
    unsigned char *data;
    int width, height, channel_count;
 
    read_image_data(filename, &data, &width, &height, &channel_count);
 
    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));
 
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int source = (y * width + x) * channel_count;
            int emplacement = ((x * height + (height - 1 - y))) * channel_count;
 
            new_data[emplacement] = data[source];
            new_data[emplacement + 1] = data[source + 1];
            new_data[emplacement + 2] = data[source + 2];
        }
    }
 
    write_image_data("image_out.bmp", new_data, height, width); 
}
void rotate_acw(char *filename) {
    unsigned char *data;
    int width, height, channel_count;
 
    read_image_data(filename, &data, &width, &height, &channel_count);
 
    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));
 
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int source = (y * width + x) * channel_count;
            int emplacement = ((width - 1 - x) * height + y) * channel_count;
 
            new_data[emplacement] = data[source];
            new_data[emplacement + 1] = data[source + 1];
            new_data[emplacement + 2] = data[source + 2];
        }
    }
 
    write_image_data("image_out.bmp", new_data, height, width); 
}
void mirror_horizontal(char *filename) {
    unsigned char *data;
    int width, height, channel_count;
 
    read_image_data(filename, &data, &width, &height, &channel_count);
 
    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));
 
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int source = (y * width + x) * channel_count;
            int emplacement = (y * width + (width - 1 - x)) * channel_count;
 
            new_data[emplacement] = data[source];
            new_data[emplacement + 1] = data[source + 1];
            new_data[emplacement + 2] = data[source + 2];
        }
    }

    write_image_data("image_out.bmp", new_data, width, height);
}
void mirror_vertical(char *filename) {
    unsigned char *data;
    int x, y ,a, width, height, channel_count , place;
    read_image_data(filename, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));

    for (y = 0; y < height; ++y) {
        for (x = 0; x < width; ++x) {
            place = (y * width + x) * channel_count;
            a = ((height - 1 - y) * width + x) * channel_count;

            new_data[a] = data[place];
            new_data[a+ 1] = data[place + 1];
            new_data[a + 2] = data[place + 2];
        }
    }

    write_image_data("image_out.bmp", new_data, width, height);
}
void mirror_total(char *filename) {
    unsigned char *data;
    int width, height, channel_count;

    read_image_data(filename, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int source = (y * width + x) * channel_count;
            int target = ((height - 1 - y) * width + (width - 1 - x)) * channel_count;

            new_data[target] = data[source];
            new_data[target + 1] = data[source + 1];
            new_data[target + 2] = data[source + 2];
        }
    }

    write_image_data("image_out.bmp", new_data, width, height);
    free(data);
    free(new_data);
}











void color_desaturate(const char *source_path){
    int width, height,n, x, y, pixel,val,R,G,B,min,max ;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &n);
    for(y=0;y<(height);y++){
        for(x=0;x<(width);x++){
            pixel=((y)*width+(x))*n;
            R=data[pixel];
            G=data[pixel+1];
            B=data[pixel+2];


            if(R<G){
		        if(R<B){
			        min=R;
		        }
		        else {
			        min=B;
		        }
	        }else {
		        if(G<B){
			        min=G;
		        }
		        else {
			        min=B;
		        }
	        }


            if(R>G){
		        if(R>B){
			        max=R;
		        }
		        else {
			        max=B;
		        }
	        }else {
		        if(G>B){
			        max=G;
		        }
		        else {
			        max=B;
		        }
	        }

            val=(min+max)/2;

            data[pixel]=val;
            data[pixel+1]=val;
            data[pixel+2]=val;


        }
    }
    write_image_data("image_out.bmp", data, width, height);    

}




void scale_crop (const char *filenames, int x, int y, int new_width, int new_height){
    int width, height,n,xmax,xmin,xp,ymax,ymin,yp,pixel,new_pixel,crop_width,crop_height;
    unsigned char *data ;
    read_image_data(filenames, &data, &width, &height, &n);
    xmin=x-(new_width/2);
    xmax=x+(new_width/2);
    ymin=y-(new_height/2);
    ymax=y+(new_height/2);

    if (xmin<0){
        xmin=0;
    }
    if (xmax>width){
        xmax=width;
    }
    if (ymin<0){
        ymin=0;
    }
    if (ymax>height){
        ymax=height;
    }

    crop_width=xmax-xmin;
    crop_height=ymax-ymin;

    unsigned char *new_data = (unsigned char *)malloc(crop_width * crop_height * n);


    for (yp=ymin; yp< ymax; yp++){
        for (xp=xmin; xp< xmax; xp++){
            pixel=((yp)*width+(xp))*n;
            new_pixel=((yp-ymin)*crop_width+(xp-xmin))*n;

            new_data[new_pixel]=data[pixel];
            new_data[new_pixel+1]=data[pixel+1];
            new_data[new_pixel+2]=data[pixel+2];
            
        }
        
    }
    

    write_image_data("image_out.bmp", new_data, crop_width, crop_height); 

    free(new_data);
}

