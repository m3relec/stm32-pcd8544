//-----------------------------------------------------------------------------
// Copyright:      RAD Electronic Co. LTD,
// Author:         Sh. Nourbakhsh Rad
// Remarks:        
// known Problems: none
// Version:        1.6.0
// Description:    GLCD's graphic founctions
//-----------------------------------------------------------------------------

#ifndef _Graphic_H_
	#define _Graphic_H_	
	

	#define PutPixel(x, y, clr)					PCD8544_DrawPixel (x,y,clr)
	#define RectangleFill(x1, y1, x2, y2, clr)			PCD8544_DrawFilledRectangle(x1,y1,x2,y2,1);

	//Line(x1, y1, x2, y2, clr)                                       lcd_draw_line (x1, y1, x2, y2, clr)
	//Rectangle(x1, y1, x2, y2, clr)                                  lcd_draw_rectangle(x1, y1, x2, y2,clr)

	#define Bevel(x1, y1, x2, y2, r, clr) 					RoundRectangle(x1, y1, x2, y2, r, 0, clr)
	#define BevelFill(x1, y1, x2, y2, r, clr)				RoundRectangle(x1, y1, x2, y2, r, 1, clr)
	#define Circle(x, y, r, clr)						Circle_Fill(x, y, r, 0, clr)
	#define CircleFill(x, y, r, clr)					Circle_Fill(x, y, r, 1, clr)

	#define VertLine(x, y, length, clr) 					drawVLine(x, y, x, y+length, clr)
	#define HoriLine(x, y, length, clr) 					drawHLine(x, y, x+length, y, clr)


	//******************* Function Prototypes
	void Line(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int color);
	void Rectangle(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int color);
	void RoundRectangle(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned char radius, unsigned char fill, unsigned int color);
	extern void Circle_Fill(unsigned int x, unsigned int y, unsigned int radius, unsigned char fill, unsigned int color);
//	void drawBitmap_rotate(int x, int y, int sx, int sy,const unsigned int* data, int deg, int rox, int roy);
//	void drawBitmap(int x, int y, int sx, int sy,unsigned int* data, int scale,char orient);

#endif	//_GRAPHIC_H_
