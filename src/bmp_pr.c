/*
 * Get the Picture resolution for bmp file
*/
 
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>
#include <unistd.h>

#include "bmp_unit.h"

int bmp_pr_get(char *file)
{
      BITMAPFILEHEADER FileHead;  
      BITMAPINFOHEADER InfoHead;  
      int rc ,i ,j, x, y;  
      int ciWidth, ciHeight, ciBitCount;  
      long int BytesPerLine = 0;  
      COLOR picture_color;  
      PIXEL_T **fbp;  
      unsigned char *buffer, *tmpbuf;
      FILE *bmp_file;
       
      bmp_file = fopen(file , "rb");
      // read file head
      rc = fread(&FileHead, sizeof(BITMAPFILEHEADER), 1, bmp_file);  
      if (rc != 1)  
      {  
          printf("Error:read bmp header error!/n"); 
          fclose(infile);  
          teturn -1;  
      }  
        
      // judge file type
      if (memcmp(FileHead.cfType, "BM", 2) != 0)  
      {  
          printf("This is not a bmp picture!/n");   
          fclose(infile);  
          return -1;  
      }  
        
      // read bmp info heead 
      rc = fread((char *)&InfoHead, sizeof(BITMAPINFOHEADER), 1, infile);  
      if (rc != 1)  
      {  
          printf("\033[1;33;31mError:read bmp infoheader error!\033[0m\n"); 
          fclose(infile);  
          return -1;  
      }
      
      ciWidth     = (int)chartolong(InfoHead.ciWidth, 4);  
      ciHeight    = (int)chartolong(InfoHead.ciHeight,    4);  
      ciBitCount  = (int)chartolong(InfoHead.ciBitCount,  4);  
      fseek(infile, (int)chartolong(FileHead.cfoffBits, 4), SEEK_SET);  
      BytesPerLine = (ciWidth * ciBitCount + 31) / 32 * 4;
      
      bmp_width = ciWidth;
      bmp_height = ciHeight;
      
      return 0;
}
