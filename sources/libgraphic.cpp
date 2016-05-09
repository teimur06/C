#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include "graphic.h"
#include "common.h"


static int fbfd = 0;
static struct fb_var_screeninfo vinfo;
static struct fb_fix_screeninfo finfo;
static long int screensize = 0;
static char *fbp = 0;
static struct fb_var_screeninfo vinfo_orig;


void openfb()
{
	
	
     fbfd = open("/dev/fb0", O_RDWR);
     if (fbfd == -1) {
         perror("Error: cannot open framebuffer device");
         exit(1);
     }
     printf("The framebuffer device was opened successfully.\n");

     if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
         perror("Error reading fixed information");
         exit(2);
     }
		
     if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
         perror("Error reading variable information");
         exit(3);
     }
	 
	 memcpy(&vinfo_orig, &vinfo, sizeof(struct fb_var_screeninfo));
	 
  // Set variable info
/*	vinfo.xres = 1024;
	vinfo.yres = 780;
	vinfo.xres_virtual = 1024;
	vinfo.yres_virtual = 780; // double the physical height

	if (ioctl(fbfd, FBIOPUT_VSCREENINFO, &vinfo)) {
		printf("Error setting variable information.\n");
	}	 
*/
 
	
     screensize = vinfo.xres_virtual * vinfo.yres_virtual * vinfo.bits_per_pixel / 8;
	 
     fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
}


void closefb(){
/*	if (ioctl(fbfd, FBIOPUT_VSCREENINFO, &vinfo_orig)) {
		printf("Error setting variable information.\n");
	}	 */
    munmap(fbp, screensize);
    close(fbfd);
}


void clearScreen(){
	for(int i = 0; i<screensize; i++)
	{
		if (vinfo.bits_per_pixel == 32) {
               *(fbp + i) = 0;     
		}
	}
}


void line(int x1, int y1, int x2, int y2) {
	int x_start ,x_end, _y1,_y2, temp ;
	long int location;
	
	_y1 = min(y1, y2);
	_y2 = max(y1, y2);
	if (_y1 == _y2) _y2++;
	
	for(int y = _y1; y <= _y2; y++)
	{
		x_start =  (y-_y1) * (x2-x1) / (_y2-_y1) + x1;
		x_end = (y+1-_y1) * (x2-x1) / (_y2-_y1) + x1;

		temp = x_start;
		x_start = min(x_start,x_end);
		x_end = max(temp, x_end);
		
		for (int x = x_start; x <= x_end; x++)
		{
			location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + 
					   (y+vinfo.yoffset) * finfo.line_length;
							
			if (vinfo.bits_per_pixel == 32) {
					//RGBA
					 *(fbp + location) = y;          // B
					 *(fbp + location + 1) = x;      // G
					 *(fbp + location + 2) = 200;    // R
					 *(fbp + location + 3) = 0;      // A
			}
		}
	}
}


