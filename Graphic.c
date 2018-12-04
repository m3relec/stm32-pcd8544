//-----------------------------------------------------------------------------
// Copyright:      RAD Electronic Co. LTD,
// Author:         Sh. Nourbakhsh Rad
// Remarks:        
// known Problems: none
// Version:        1.6.0
// Description:    GLCD's graphic founctions
//-----------------------------------------------------------------------------
#include "Graphic.h"
#include "pcd8544.h"
#include <stdlib.h>

// Description	: Draw a line on a graphic LCD
// Input        : x1,y1 - starting coordinates
//              : x2,y2 - ending coordinates
//********************************************************************
void Line(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int color)
{
	signed int  	x, y, addx, addy, dx, dy;
	signed long 	P;
	int 					i;

	dx = abs((signed int)(x2 - x1));
	dy = abs((signed int)(y2 - y1));
	x  = x1;
	y  = y1;

	addx = addy = 1;
	if(x1 > x2)		addx = -1;
	if(y1 > y2)		addy = -1;

	if (dx >= dy)
	{
		P = 2L*dy - dx;
		for (i=0; i<=dx; ++i)
		{
	  	PutPixel((unsigned char)x, (unsigned char)y, color);
			if(P < 0)
	  	{
	    	P += 2*dy;
	    	x += addx;
	  	}
			else
			{
	    	P += 2*dy - 2*dx;
	    	x += addx;
	    	y += addy;
	  	}
		}
	}
	else
	{
		P = 2L*dx - dy;
		for(i=0; i<=dy; ++i)
		{
	  	PutPixel((unsigned char)x, (unsigned char)y, color);
	  	if(P < 0)
	  	{
	    	P += 2*dx;
	    	y += addy;
	  	}
	  	else
	  	{
	    	P += 2*dx - 2*dy;
	    	x += addx;
	    	y += addy;
	  	}
		}
	}
}	//*Line

// Description  : Draw a rectangle on a graphic LCD
// Input        : x1,y1 - starting coordinates
//              : x2,y2 - ending coordinates
//********************************************************************

void Rectangle(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int color)
{
    RectangleFill(x1, y1, x2, y1, color);    // top
    RectangleFill(x1, y2, x2, y2, color);    // bottom
    RectangleFill(x1, y1, x1, y2, color);    // left
    RectangleFill(x2, y1, x2, y2, color);    // right
}	//*Rectangle

// Description	: Draws a beveled figure on the screen. 
// Input       	: x1, y1 - coordinate position of the upper left center
//		      	: x2, y2 - coordinate position of the lower right center
//             	: rad    - defines the radius of the circle,
//             	: fill   - fill yes or no
//********************************************************************
void RoundRectangle(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned char radius, unsigned char fill, unsigned int color)
{
	signed int 		a, b, P;

	a  = 0;       				// increment by 1
	b  = radius;  				// decrement by 1 using P
	P  = 1 - (signed int)(radius);

	if (fill)
	{		
		RectangleFill((unsigned int)(x1), (unsigned int)(y1+radius), (unsigned int)(x2), (unsigned int)(y2-radius), color);
		
		do
		{
			RectangleFill((unsigned int)(x1-a+radius), (unsigned int)(y1-b+radius), (unsigned int)(a+x2-radius), (unsigned int)(y1-b+radius), color);	// 8 --> 1
			RectangleFill((unsigned int)(x1-b+radius), (unsigned int)(y1-a+radius), (unsigned int)(b+x2-radius), (unsigned int)(y1-a+radius), color);	// 7 --> 2
			RectangleFill((unsigned int)(x1-b+radius), (unsigned int)(a+y2-radius), (unsigned int)(b+x2-radius), (unsigned int)(a+y2-radius), color);	// 6 --> 3
			RectangleFill((unsigned int)(x1-a+radius), (unsigned int)(b+y2-radius), (unsigned int)(a+x2-radius), (unsigned int)(b+y2-radius), color);	// 5 --> 4

			if(P < 0)		P+= 3 + 2*a++;
			else				P+= 5 + 2*(a++ - b--);
		} while(a <= b);
	} //fill
	else
	{
		RectangleFill((unsigned int)(x1+radius), (unsigned int)(y1)       , (unsigned int)(x2-radius), (unsigned int)(y1)       , color);	// top
		RectangleFill((unsigned int)(x1+radius), (unsigned int)(y2)       , (unsigned int)(x2-radius), (unsigned int)(y2)       , color);	// bottom
		RectangleFill((unsigned int)(x1)       , (unsigned int)(y1+radius), (unsigned int)(x1)       , (unsigned int)(y2-radius), color);	// left
		RectangleFill((unsigned int)(x2)       , (unsigned int)(y1+radius), (unsigned int)(x2)       , (unsigned int)(y2-radius), color);	// right
		do
		{
			PutPixel((unsigned int)(a+x2-radius), (unsigned int)(y1-b+radius), color);	// `````` Segment 1
			PutPixel((unsigned int)(b+x2-radius), (unsigned int)(y1-a+radius), color);	// `````` Segment 2
			
			PutPixel((unsigned int)(b+x2-radius), (unsigned int)(a+y2-radius), color);	// `````` Segment 3
			PutPixel((unsigned int)(a+x2-radius), (unsigned int)(b+y2-radius), color);	// `````` Segment 4
			
			PutPixel((unsigned int)(x1-a+radius), (unsigned int)(b+y2-radius), color);	// `````` Segment 5
			PutPixel((unsigned int)(x1-b+radius), (unsigned int)(a+y2-radius), color);	// `````` Segment 6
			
			PutPixel((unsigned int)(x1-b+radius), (unsigned int)(y1-a+radius), color);	// `````` Segment 7
			PutPixel((unsigned int)(x1-a+radius), (unsigned int)(y1-b+radius), color);	// `````` Segment 8
			
			if(P < 0)		P+= 3 + 2*a++;
			else				P+= 5 + 2*(a++ - b--);
		} while(a <= b);
	}
}

// Description	: Draw a circle on the screen. 
// Input       	: x,y  - the center of the circle
//             	: rad  - defines the radius of the circle,
//             	: fill - fill yes or no
//********************************************************************

void Circle_Fill(unsigned int x, unsigned int y, unsigned int radius, unsigned char fill, unsigned int color)
{
	signed int 	a, b, P;
   
	a = 0;
	b = radius;
	P = 1 - (signed int)(radius);

	do
	{
		if(fill)
		{
			RectangleFill((unsigned int)(x-a), (unsigned int)(y+b), (unsigned int)(x+a), (unsigned int)(y+b), color);	// 5 --> 4
			RectangleFill((unsigned int)(x-a), (unsigned int)(y-b), (unsigned int)(x+a), (unsigned int)(y-b), color);	// 8 --> 1
			RectangleFill((unsigned int)(x-b), (unsigned int)(y+a), (unsigned int)(x+b), (unsigned int)(y+a), color);	// 6 --> 3
			RectangleFill((unsigned int)(x-b), (unsigned int)(y-a), (unsigned int)(x+b), (unsigned int)(y-a), color);	// 7 --> 2
		}
		else
		{
																										//       		8	1
																										//       	7			2
																										//       	6			3
																										//       		5	4
																										//
			PutPixel((unsigned int)(a+x), (unsigned int)(b+y), color);	// `````` Segment 4
			PutPixel((unsigned int)(b+x), (unsigned int)(a+y), color);	// `````` Segment 3
			PutPixel((unsigned int)(x-a), (unsigned int)(b+y), color);	// `````` Segment 5
			PutPixel((unsigned int)(x-b), (unsigned int)(a+y), color);	// `````` Segment 6
			PutPixel((unsigned int)(b+x), (unsigned int)(y-a), color);	// `````` Segment 2
			PutPixel((unsigned int)(a+x), (unsigned int)(y-b), color);	// `````` Segment 1
			PutPixel((unsigned int)(x-a), (unsigned int)(y-b), color);	// `````` Segment 8
			PutPixel((unsigned int)(x-b), (unsigned int)(y-a), color);	// `````` Segment 7
		}

		if(P < 0)    P += 3 +2 *a++;
    else         P += 5 +2 *(a++ - b--);
	} while(a <= b);
}	//Circle_Fill



/*void drawBitmap(int x, int y, int sx, int sy,const unsigned int* data, int scale,char orient)
{
	unsigned int col;
	int tx, ty, tc, tsx, tsy;
	//char r, g, b;

	if (scale==1)
	{
		if (orient==PORTRAIT)
		{
			lcd_setarea(x, y, x+sx-1, y+sy-1);
			for (tc=0; tc<(sx*sy); tc++)
			{
				col=pgm_read_word(&data[tc]);
				lcd_WrDat(col);
			}
		}
		else
		{
			for (ty=0; ty<sy; ty++)
			{
				lcd_setarea(x, y+ty, x+sx-1, y+ty);
				for (tx=sx; tx>=0; tx--)
				{
					col=pgm_read_word(&data[(ty*sx)+tx]);
					lcd_WrDat(col);
				}
			}
		}
	}
	else
	{
		if (orient==PORTRAIT)
		{
			for (ty=0; ty<sy; ty++)
			{
				lcd_setarea(x, y+(ty*scale), x+((sx*scale)-1), y+(ty*scale)+scale);
				for (tsy=0; tsy<scale; tsy++)
				for (tx=0; tx<sx; tx++)
				{
					col=pgm_read_word(&data[(ty*sx)+tx]);
					for (tsx=0; tsx<scale; tsx++)
					lcd_WrDat(col);
				}
			}
		}
		else
		{
			for (ty=0; ty<sy; ty++)
			{
				for (tsy=0; tsy<scale; tsy++)
				{
					lcd_setarea(x, y+(ty*scale)+tsy, x+((sx*scale)-1), y+(ty*scale)+tsy);
					for (tx=sx; tx>=0; tx--)
					{
						col=pgm_read_word(&data[(ty*sx)+tx]);
						for (tsx=0; tsx<scale; tsx++)
						lcd_WrDat(col);
					}
				}
			}
		}
	}
}

void drawBitmap_rotate(int x, int y, int sx, int sy,const unsigned int* data, int deg, int rox, int roy)
{
	unsigned int col;
	int tx, ty, newx, newy;
	//char r, g, b;
	double radian;
	radian=deg*0.0175;

	if (deg==0)
	drawBitmap(x, y, sx, sy, data,1,VERTICAL);
	else
	{
		for (ty=0; ty<sy; ty++)
		for (tx=0; tx<sx; tx++)
		{
			col=pgm_read_word(&data[(ty*sx)+tx]);

			newx=x+rox+(((tx-rox)*cos(radian))-((ty-roy)*sin(radian)));
			newy=y+roy+(((ty-roy)*cos(radian))+((tx-rox)*sin(radian)));

			lcd_setarea(newx, newy, newx, newy);
			lcd_WrDat(col);
		}
	}
}

*/
