//-----------------------------------------------------------------------------
// Copyright:      RAD Electronic Co. LTD,
// Author:         jaruwit supa, Base on FontEditor written by H. Reddmann
//								 Modified by Sh. Nourbakhsh Rad for Persian and Arabic font
//								 and fixed some errors
// Remarks:        
// known Problems: none
// Version:        2.0.0  15.10.2011
// Description:    Font Library
//-----------------------------------------------------------------------------

#ifndef _FONT_H_
	#define _FONT_H_

	#include <string.h>
	#include "Graphic.h"
	#define  SCREEN_HOR_SIZE 48
	#define	 SCREEN_VER_SIZE 84

	// color
	#define BLACK                       RGB(0x00, 0x00, 0x00)
	#define WHITE                       RGB(0xFF, 0xFF, 0xFF)
	#define RED                         RGB(0xFF, 0x00, 0x00)
	#define GREEN                       RGB(0x00, 0xFF, 0x00)
	#define BLUE                        RGB(0x00, 0x00, 0xFF)
	#define YELLOW                      RGB(0xFF, 0xFF, 0x00)
	#define MAGENTA                     RGB(0xFF, 0x00, 0xFF)
	#define CYAN                        RGB(0x00, 0xFF, 0xFF)
	#define GRAY                        RGB(0x80, 0x80, 0x40)
	#define SILVER                      RGB(0xA0, 0xA0, 0x80)
	#define GOLD                        RGB(0xA0, 0xA0, 0x40)
	#define JIGARI                      RGB(0xA5, 0x00, 0x4C)
	#define CYAN_L                      RGB(0xDC, 0xF8, 0xFA)
	#define SORATI                      RGB(0xF6, 0x1F, 0xE0)
	#define GREEN_L                     RGB(0x9E, 0xF4, 0xA0)
	#define ORANG                       RGB(0xEA, 0x79, 0x14)
	#define BRIGHTBLUE     			    RGB(0,    0,      255)
	#define BRIGHTGREEN         		RGB(0,    255,    0)
	#define BRIGHTCYAN          		RGB(0,    255,    255)
	#define BRIGHTRED           		RGB(255,  0,      0)
	#define BRIGHTMAGENTA       		RGB(255,  0,      255)
	#define BRIGHTYELLOW        		RGB(255,  255,    0)
	#define BROWN               		RGB(255,  128,    0)
	#define LIGHTGRAY           		RGB(128,  128,    128)
	#define DARKGRAY            		RGB(64,   64,     64)
	#define LIGHTBLUE           		RGB(128,  128,    255)
	#define LIGHTGREEN          		RGB(128,  255,    128)
	#define LIGHTCYAN           		RGB(128,  255,    255)
	#define LIGHTRED            		RGB(255,  128,    128)
	#define LIGHTMAGENTA        		RGB(255,  128,    255)
	#define GRAY0       	    		RGB(224,  224,    224)
	#define GRAY1         	    		RGB(192,  192,    192)
	#define GRAY2               		RGB(160,  160,    160)
	#define GRAY3               		RGB(128,  128,    128)
	#define GRAY4               		RGB(96,   96,     96)
	#define GRAY5               		RGB(64,   64,     64)
	#define GRAY6	            		RGB(32,   32,     32)
	#define RGB(blue, green, red)	((unsigned int)( (( red >> 3 ) << 11 ) |  (( green >> 2 ) << 5  ) |  ( blue  >> 3 ))) 
	//******************

 	#define FONT_HEADER_SIZE  				7 					// header size of fonts

	// Letter type (English - Persian)
	typedef enum {
		E_LETTER,
		P_LETTER
	} Lt_Mode;

	/////////////////////////////////////////////////////////
	#define STYLE_NONE							0
	#define STYLE_NO_ZERO   					1
	#define STYLE_NO_SPACE  					2
	
	#define ALINE_LEFT								0
	#define ALINE_CENTER							1
	#define ALINE_RIGHT								2
	#define ALINE_MARK								(ALINE_LEFT | ALINE_CENTER | ALINE_RIGHT)
	
	#define BORDER_NONE								0x00
	#define BORDER_RECT								0x04
	#define BORDER_FILL								0x08
	#define BORDER_BEVEL							0xF0	// bevel radius 0x00(rectangle), 0x10-0xF0(radius size)
	#define BORDER_MASK								(BORDER_FILL | BORDER_RECT)
	#define bvl(x)									(x<<4)

	/////////////////////////////////////////////////////////	
	extern unsigned char 							rot;
	extern unsigned char 							Reverse;
	extern unsigned char							Horizontal_font;

	extern unsigned short							FgColor;
	extern unsigned short							BkColor;
	extern unsigned char							FontFixed;
	extern unsigned char							NonTransparence;
	
	extern unsigned char 							FontWidth;
	extern unsigned char 							FontHeight;
	extern unsigned char 							FontXScale;
	extern unsigned char 							FontYScale;
	extern unsigned char 							FontSpace;
	
	extern unsigned int 							cursorX;
	extern unsigned int 							cursorY;

	extern Lt_Mode										peLETTER;

	/////////////////////////////////////////////////////////	
	#define GetLetter() 							peLETTER

	#define GetCursorX() 							cursorX
	#define GetCursorY() 							cursorY
	#define SetCursorX(x) 							cursorX = x
	#define SetCursorY(y) 							cursorY = y
	#define SetCursor(x,y) 							{cursorX = x; cursorY = y;}
	
	#define LcdRot(n)								rot = n
	#define LcdReverse(n)							Reverse = n
	#define LcdHorizontal(n)						Horizontal = n
	
	#define LcdFontFixed(n)							FontFixed = n
	#define LcdNonTransparence(n)					NonTransparence = n
	
	#define SetFgColor(c)							FgColor = c
	#define SetBkColor(c)							BkColor = c
	#define GetFgColor()							FgColor
	#define GetBkColor()							BkColor
	
	#define LcdFontXScale(n)						FontXScale = n
	#define LcdFontYScale(n)						FontYScale = n
	#define LcdFontSpace(n)							FontSpace  = n
	
	#define LcdFontWidth() 	 						FontWidth
	#define LcdFontHeight()							FontHeight
	
	// complex function
	#define DrawStringAt(l,c,s,fk,bk)				{SetLine(l,c); SetFgColor(fk); SetBkColor(bk); Puts(s);}
	#define DrawStringAtP(l,c,s,fk,bk)				{SetLine(l,c); SetFgColor(fk); SetBkColor(bk); PutsP(s);}
		
	#define DISPLAY_WIDTH											320
	#define DISPLAY_HEIGHT											240
	
	/*#define T6963_SIZE_Y											DISPLAY_HEIGH
	#define T6963_SIZE_X											DISPLAY_WIDTH*/
	
	#define GetMaxX_font()							((unsigned int)SCREEN_HOR_SIZE -1)
	#define GetMaxY_font()							((unsigned int)SCREEN_VER_SIZE -1)

	#define lcd_draw_rectangle(x,y,w,h,c)	        PCD8544_DrawRectangle(x,y,w,h,1)
	#define lcd_bar(x0,y0,x1,y1,c)			PCD8544_DrawRectangle(x0,y0,x1,y1,c)
	#define	lcd_write_pixel(x,y,color)		lcd_write_pixel(x,y,color)
	
	//******************* Function Prototypes
	void LcdFont(const unsigned char *pointer);

	void SetLetter(Lt_Mode L);
	void SetLine(unsigned char line,unsigned char column);

	void PutChar(unsigned char c);
	void Puts(char *Text);

	void PutLong(unsigned long src, unsigned char digit, unsigned char decimal, unsigned char Parameter);
	void PutInt(unsigned short src, unsigned char digit, unsigned char decimal, unsigned char Parameter);
	void PutByte(unsigned char src, unsigned char digit, unsigned char decimal, unsigned char Parameter);
	
	void PutText(unsigned short left, unsigned short top, unsigned short right, unsigned short bottom, char *str, unsigned char style);
	void TextBox(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2, char *str, unsigned char style);

#endif	//_FONT_H_
