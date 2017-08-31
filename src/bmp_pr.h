#include <sys/types.h>
#include <sys/stat.h>

typedef struct bmp_file_header
{  
        char cfType[2];             //文件类型，必须为“BM”（0x4D42）  
        char cfSize[4];             //文件的大小（字节）  
        char cfReserved[4];         //保留，必须为0  
        char cfoffBits[4];          //位图阵列相对与文件头的偏移量（字节）  
}__attribute__((packed)) BITMAPFILEHEADER;  //文件头结构

typedef struct bmp_info_header 
{  
        char ciSize[4];             //sizeof of BITMAPINFOHEADER  
        char ciWidth[4];            //位图宽度（像素）  
        char ciHeight[4];           //位图高度（像素）  
        char ciPlanes[2];           //目标设备的位平面数，必须置为1  
        char ciBitCount[2];         //每个像素的位数，1，4，8或24  
        char ciCompress[4];         // compress way, 0 = none compress 
        char ciSizeImage[4];
        char ciXPelsPerMeter[4];
        char ciYPelsPerMeter[4];
        char ciClrUsed[4];          //位图实际使用的颜色表的颜色数
        char ciClrImportant[4];         //重要颜色索引的个数  
}__attribute__((packed)) BITMAPINFOHEADER;
