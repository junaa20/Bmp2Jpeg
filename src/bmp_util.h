#include <sys/types.h>
#include <sys/stat.h>

#include <jpeglib.h>

typedef struct jpeg_pixel_t  
{  
        unsigned char r;  
        unsigned char g;  
        unsigned char b;  
        unsigned char a;  
}PIXEL_T;  

typedef struct jpeg_color  
{  
        unsigned char r;  
        unsigned char g;  
        unsigned char b;  
}COLOR;

typedef struct bmp_file_header  
{  
        char cfType[2];             //must be “BM”（0x4D42）  
        char cfSize[4];             // file size（bytes）  
        char cfReserved[4];         // must be 0
        char cfoffBits[4];          //
}__attribute__((packed)) BITMAPFILEHEADER; 

typedef struct bmp_info_header  
{  
        char ciSize[4];             //sizeof of BITMAPINFOHEADER  
        char ciWidth[4];
        char ciHeight[4];
        char ciPlanes[2];           // must be "1"
        char ciBitCount[2];         // pixel bit，1，4，8 or 24  
        char ciCompress[4];
        char ciSizeImage[4];            // image size（bytes）  
        char ciXPelsPerMeter[4];
        char ciYPelsPerMeter[4];
        char ciClrUsed[4];
        char ciClrImportant[4];
}__attribute__((packed)) BITMAPINFOHEADER;
