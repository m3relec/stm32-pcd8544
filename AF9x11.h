/*
    created with FontEditor written by H. Reddmann
    HaReddmann at t-online dot de

    File Name           : AF9x11.h
    Date                : 2011/10/23
    Font size in bytes  : 0x09EA, 2538
    Font width          : 12
    Font height         : 12
    Font first char     : 0x00
    Font last char      : 0xFF
    Font bits per pixel : 1
    Font is compressed  : false

    The font data are defined as

    struct _FONT_ {
     // common shared fields
       uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
       uint8_t    font_Width_in_Pixel_for_fixed_drawing;
       uint8_t    font_Height_in_Pixel_for_all_Characters;
       uint8_t    font_Bits_per_Pixels;
                    // if MSB are set then font is a compressed font
       uint8_t    font_First_Char;
       uint8_t    font_Last_Char;
       uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
                    // for each character the separate width in pixels,
                    // characters < 128 have an implicit virtual right empty row
                    // characters with font_Char_Widths[] == 0 are undefined

     // if compressed font then additional fields
       uint8_t    font_Byte_Padding;
                    // each Char in the table are aligned in size to this value
       uint8_t    font_RLE_Table[3];
                    // Run Length Encoding Table for compression
       uint8_t    font_Char_Size_in_Bytes[font_Last_Char - font_First_Char +1];
                    // for each char the size in (bytes / font_Byte_Padding) are stored,
                    // this get us the table to seek to the right beginning of each char
                    // in the font_data[].

     // for compressed and uncompressed fonts
       uint8_t    font_data[];
                    // bit field of all characters
    }
*/

#ifndef AF9x11_H
#define AF9x11_H


#define AF9x11_WIDTH 12
#define AF9x11_HEIGHT 12

  const unsigned char AF9x11[] = {
    0x09, 0xF0, 0x0C, 0x0C, 0x01, 0x00, 0xFF,
    0x04, 0x05, 0x05, 0x05, 0x03, 0x03, 0x03, 0x08, 0x07, 0x08, 0x07, 0x08, 0x07, 0x0A, 0x0A, 0x09, 
    0x02, 0x02, 0x05, 0x06, 0x07, 0x07, 0x06, 0x07, 0x07, 0x05, 0x09, 0x07, 0x02, 0x03, 0x03, 0x03, 
    0x01, 0x01, 0x03, 0x07, 0x05, 0x0B, 0x07, 0x01, 0x03, 0x03, 0x05, 0x07, 0x02, 0x05, 0x01, 0x09, 
    0x06, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x01, 0x02, 0x06, 0x07, 0x06, 0x05, 
    0x09, 0x07, 0x06, 0x06, 0x07, 0x06, 0x05, 0x07, 0x07, 0x03, 0x04, 0x06, 0x05, 0x08, 0x07, 0x08, 
    0x06, 0x08, 0x06, 0x06, 0x07, 0x07, 0x07, 0x0B, 0x06, 0x07, 0x06, 0x03, 0x09, 0x03, 0x07, 0x05, 
    0x02, 0x05, 0x06, 0x05, 0x06, 0x06, 0x04, 0x06, 0x06, 0x01, 0x03, 0x05, 0x01, 0x09, 0x06, 0x06, 
    0x06, 0x06, 0x03, 0x04, 0x04, 0x06, 0x05, 0x09, 0x05, 0x05, 0x04, 0x05, 0x01, 0x05, 0x07, 0x06, 
    0x06, 0x08, 0x03, 0x06, 0x05, 0x06, 0x0F, 0x0E, 0x06, 0x0A, 0x0A, 0x05, 0x06, 0x06, 0x03, 0x03, 
    0x03, 0x08, 0x03, 0x05, 0x05, 0x08, 0x06, 0x06, 0x03, 0x0A, 0x07, 0x05, 0x09, 0x08, 0x07, 0x09, 
    0x09, 0x03, 0x03, 0x05, 0x06, 0x07, 0x03, 0x05, 0x04, 0x08, 0x03, 0x06, 0x04, 0x04, 0x08, 0x04, 
    0x04, 0x06, 0x07, 0x09, 0x07, 0x09, 0x06, 0x02, 0x04, 0x09, 0x03, 0x06, 0x08, 0x08, 0x08, 0x06, 
    0x03, 0x03, 0x04, 0x03, 0x04, 0x03, 0x08, 0x01, 0x08, 0x06, 0x08, 0x08, 0x06, 0x06, 0x06, 0x04, 
    0x04, 0x03, 0x03, 0x0D, 0x0D, 0x0C, 0x0C, 0x08, 0x06, 0x06, 0x05, 0x05, 0x03, 0x08, 0x08, 0x08, 
    0x05, 0x06, 0x05, 0x06, 0x06, 0x05, 0x04, 0x07, 0x07, 0x07, 0x0F, 0x0E, 0x08, 0x08, 0x0F, 0x0E, 
    0x06, 0x06, 0x03, 0x03, 0x06, 0x07, 0x06, 0x07, 0x06, 0x06, 0x06, 0x06, 0x07, 0x03, 0x08, 0x03, 
    
    0x00, 0xE0, 0x0F, 0x00, 0x01, 0x10, 0x00, 0x40, 0x00, 0xF6, 0x20, 0x10, 0x00, 0x01, 0x00, 0x04, 
    0x20, 0x0F, 0x04, 0x21, 0x10, 0x00, 0x00, 0x80, 0xFE, 0x0C, 0x50, 0x00, 0x01, 0x10, 0x00, 0x01, 
    0x4C, 0x08, 0x01, 0x10, 0xC8, 0x80, 0x10, 0x02, 0x81, 0x0C, 0x00, 0x01, 0x10, 0x20, 0x01, 0x11, 
    0x10, 0x05, 0x0A, 0xC0, 0x00, 0x08, 0x00, 0x07, 0x8A, 0xA0, 0x08, 0xA6, 0x40, 0x08, 0x8C, 0x40, 
    0x01, 0x10, 0x00, 0x01, 0x12, 0x10, 0x01, 0x11, 0xA0, 0x00, 0x0C, 0x80, 0x00, 0x70, 0xA0, 0x08, 
    0x8A, 0x60, 0x08, 0x84, 0xC0, 0x08, 0x14, 0x00, 0x01, 0x10, 0x20, 0x01, 0x11, 0x14, 0x01, 0x0A, 
    0xC0, 0x00, 0x08, 0x00, 0x07, 0x8A, 0xA0, 0x08, 0x86, 0x48, 0x08, 0x8C, 0x40, 0x01, 0x10, 0x00, 
    0x01, 0x0C, 0x00, 0x01, 0x10, 0x00, 0x01, 0x0C, 0x00, 0x01, 0x10, 0xE0, 0x00, 0x10, 0x00, 0x01, 
    0x0C, 0x00, 0x01, 0x10, 0x08, 0x21, 0x0C, 0x08, 0x01, 0x10, 0xE0, 0x00, 0x10, 0x00, 0x01, 0x08, 
    0x00, 0x01, 0x18, 0x60, 0x01, 0x11, 0x10, 0x01, 0x0E, 0xC0, 0x00, 0x0C, 0x0C, 0x00, 0x3F, 0x0C, 
    0x80, 0x03, 0xD0, 0x03, 0x01, 0x0C, 0xC0, 0x00, 0x38, 0x00, 0x3D, 0x0C, 0x00, 0x01, 0x0C, 0x80, 
    0x00, 0x3C, 0x80, 0x3F, 0x18, 0x40, 0x02, 0x24, 0x00, 0x01, 0xC0, 0x01, 0x22, 0x14, 0x82, 0x18, 
    0x10, 0x02, 0x22, 0xC0, 0x01, 0x20, 0x18, 0x41, 0x0A, 0x64, 0x00, 0x02, 0x10, 0xC0, 0x00, 0x30, 
    0x00, 0x0C, 0x00, 0x03, 0x0C, 0x30, 0xC0, 0x00, 0x00, 0x03, 0x0C, 0x30, 0xC0, 0x00, 0x30, 0x00, 
    0x0C, 0x00, 0x83, 0x01, 0x24, 0x40, 0x02, 0xF8, 0x00, 0x30, 0x00, 0x01, 0x10, 0x80, 0x00, 0x10, 
    0x84, 0x01, 0x16, 0x10, 0x01, 0x11, 0xE0, 0x00, 0x10, 0x00, 0x01, 0x16, 0x90, 0x01, 0x11, 0x90, 
    0x00, 0x08, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x40, 0x01, 0x00, 0x40, 0x01, 0x0C, 0x00, 0x00, 
    0x16, 0x50, 0x01, 0x00, 0xFE, 0xE2, 0x00, 0x00, 0xE0, 0x00, 0x40, 0x80, 0x34, 0xF8, 0xE0, 0x34, 
    0xF8, 0xE0, 0x04, 0x08, 0x80, 0x09, 0x24, 0xE1, 0x3F, 0x24, 0x81, 0x0C, 0x1C, 0x20, 0x02, 0x22, 
    0xC0, 0x21, 0x80, 0x01, 0x07, 0x0C, 0x20, 0x1C, 0x20, 0x02, 0x22, 0xC0, 0xC1, 0x1C, 0x32, 0x22, 
    0x22, 0x52, 0xC2, 0x18, 0x80, 0x01, 0x26, 0x0E, 0x80, 0x1F, 0x06, 0x16, 0x80, 0x01, 0x68, 0x60, 
    0xF8, 0x01, 0x05, 0x20, 0x80, 0x0F, 0x20, 0x00, 0x05, 0x20, 0x00, 0x02, 0x20, 0xC0, 0x1F, 0x20, 
    0x00, 0x02, 0x20, 0x00, 0x80, 0x00, 0x06, 0x20, 0x00, 0x02, 0x20, 0x00, 0x02, 0x20, 0x00, 0x03, 
    0x20, 0x00, 0x01, 0x08, 0x40, 0x00, 0x02, 0x10, 0x80, 0x00, 0x04, 0x20, 0x00, 0xFC, 0x21, 0x20, 
    0x02, 0x22, 0x20, 0x02, 0xC2, 0x1F, 0x04, 0x42, 0x20, 0xFE, 0x03, 0x20, 0x00, 0x42, 0x30, 0x82, 
    0x22, 0x24, 0x42, 0x22, 0x22, 0x1C, 0x42, 0x10, 0x02, 0x22, 0x22, 0x22, 0x22, 0x22, 0xDC, 0x01, 
    0x06, 0x50, 0x80, 0x04, 0x44, 0xE0, 0x3F, 0x40, 0xE0, 0x11, 0x12, 0x22, 0x21, 0x12, 0x22, 0x21, 
    0xE2, 0x81, 0x1F, 0x14, 0x22, 0x21, 0x12, 0x22, 0x21, 0xE0, 0x21, 0x00, 0x02, 0x22, 0x18, 0x62, 
    0xA0, 0x01, 0x06, 0xC0, 0x1D, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0xDC, 0xC1, 0x03, 0x42, 0x22, 
    0x24, 0x42, 0x22, 0x14, 0xFC, 0x00, 0x33, 0x00, 0x08, 0x66, 0x20, 0x00, 0x05, 0x50, 0x80, 0x08, 
    0x88, 0x40, 0x10, 0x28, 0x80, 0x02, 0x28, 0x80, 0x02, 0x28, 0x80, 0x02, 0x28, 0x40, 0x10, 0x88, 
    0x80, 0x08, 0x50, 0x00, 0x05, 0x20, 0x40, 0x00, 0xC2, 0x22, 0x02, 0x22, 0xC0, 0x01, 0x70, 0xC0, 
    0x18, 0x74, 0xA1, 0x28, 0x8A, 0xA2, 0x2F, 0x84, 0xC0, 0x08, 0x70, 0x00, 0x30, 0xE0, 0xC0, 0x09, 
    0x82, 0xC0, 0x09, 0xE0, 0x00, 0x30, 0xFE, 0x23, 0x22, 0x22, 0x22, 0x22, 0x22, 0xC2, 0x1D, 0xF8, 
    0x40, 0x10, 0x02, 0x22, 0x20, 0x02, 0x22, 0x20, 0xFE, 0x23, 0x20, 0x02, 0x22, 0x20, 0x02, 0x42, 
    0x10, 0xF8, 0xE0, 0x3F, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x02, 0xE2, 0x3F, 0x22, 0x20, 0x02, 
    0x22, 0x20, 0x00, 0xF8, 0x40, 0x10, 0x02, 0x22, 0x20, 0x22, 0x22, 0x22, 0xE4, 0xE3, 0x3F, 0x20, 
    0x00, 0x02, 0x20, 0x00, 0x02, 0x20, 0xE0, 0x3F, 0x02, 0xE2, 0x3F, 0x02, 0x02, 0x20, 0x02, 0x22, 
    0x20, 0xFE, 0xE1, 0x3F, 0x20, 0x00, 0x05, 0x88, 0x40, 0x10, 0x02, 0xE2, 0x3F, 0x00, 0x02, 0x20, 
    0x00, 0x02, 0x20, 0xFE, 0x63, 0x00, 0x38, 0x00, 0x0C, 0xC0, 0x80, 0x03, 0x06, 0xE0, 0x3F, 0xFE, 
    0x63, 0x00, 0x18, 0x00, 0x02, 0xC0, 0x00, 0x30, 0xFE, 0x83, 0x0F, 0x04, 0x21, 0x20, 0x02, 0x22, 
    0x20, 0x02, 0x42, 0x10, 0xF8, 0xE0, 0x3F, 0x42, 0x20, 0x04, 0x42, 0x20, 0x04, 0x3C, 0x80, 0x0F, 
    0x04, 0x21, 0x20, 0x02, 0x22, 0x60, 0x02, 0x4A, 0x90, 0xF8, 0xE0, 0x3F, 0x22, 0x20, 0x02, 0x62, 
    0xC0, 0x19, 0x00, 0xC2, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0xC4, 0x21, 0x00, 0x02, 0x20, 
    0x00, 0xFE, 0x23, 0x00, 0x02, 0x20, 0x00, 0xFE, 0x00, 0x10, 0x00, 0x02, 0x20, 0x00, 0x02, 0x10, 
    0xFE, 0x60, 0x00, 0x38, 0x00, 0x1C, 0x00, 0x02, 0x1C, 0x38, 0x60, 0x00, 0x06, 0x80, 0x07, 0x80, 
    0x03, 0x0C, 0x38, 0x60, 0x00, 0x38, 0x00, 0x0C, 0x80, 0x83, 0x07, 0x06, 0x20, 0x20, 0x8C, 0x01, 
    0x07, 0x70, 0xC0, 0x18, 0x02, 0x22, 0x00, 0x0C, 0x00, 0x01, 0xE0, 0x03, 0x01, 0x0C, 0x20, 0x00, 
    0x02, 0x23, 0x28, 0x62, 0x22, 0x21, 0x0A, 0x62, 0x20, 0x01, 0x18, 0x80, 0xFF, 0x2F, 0x00, 0x04, 
    0x80, 0x00, 0x10, 0x00, 0x02, 0x40, 0x00, 0x08, 0x00, 0x01, 0x20, 0xFF, 0x1F, 0x80, 0x01, 0x08, 
    0x01, 0x08, 0x40, 0x00, 0x02, 0x40, 0x00, 0x08, 0x00, 0x01, 0x00, 0x02, 0x20, 0x00, 0x02, 0x20, 
    0x00, 0x22, 0x00, 0x04, 0x00, 0x18, 0x50, 0x02, 0x25, 0x50, 0x02, 0x3E, 0xFE, 0x03, 0x22, 0x10, 
    0x02, 0x21, 0x10, 0x02, 0x1E, 0xE0, 0x01, 0x21, 0x10, 0x02, 0x21, 0x10, 0x02, 0x1E, 0x10, 0x02, 
    0x21, 0x10, 0x02, 0x11, 0xFE, 0x03, 0x1E, 0x50, 0x02, 0x25, 0x50, 0x02, 0x25, 0x60, 0x01, 0x01, 
    0xFC, 0x23, 0x01, 0x12, 0x00, 0x1E, 0x10, 0x0A, 0xA1, 0x10, 0x0A, 0x91, 0xF0, 0xE7, 0x3F, 0x20, 
    0x00, 0x01, 0x10, 0x00, 0x01, 0xE0, 0x83, 0x3E, 0x00, 0x08, 0x81, 0xF4, 0xE7, 0x3F, 0x40, 0x00, 
    0x0A, 0x10, 0x81, 0x20, 0xFE, 0x03, 0x3F, 0x10, 0x00, 0x01, 0x10, 0x00, 0x3E, 0x10, 0x00, 0x01, 
    0x10, 0x00, 0x3E, 0xF0, 0x03, 0x02, 0x10, 0x00, 0x01, 0x10, 0x00, 0x3E, 0xE0, 0x01, 0x21, 0x10, 
    0x02, 0x21, 0x10, 0x02, 0x1E, 0xF0, 0x0F, 0x22, 0x10, 0x02, 0x21, 0x10, 0x02, 0x1E, 0xE0, 0x01, 
    0x21, 0x10, 0x02, 0x21, 0x10, 0x01, 0xFF, 0xF0, 0x03, 0x02, 0x10, 0x00, 0x23, 0x48, 0x82, 0x24, 
    0x88, 0x01, 0x01, 0xFC, 0x01, 0x21, 0x10, 0x02, 0x1F, 0x00, 0x02, 0x20, 0x00, 0x02, 0x10, 0xF0, 
    0x03, 0x03, 0xC0, 0x00, 0x30, 0xC0, 0x00, 0x03, 0x30, 0x00, 0x0C, 0x00, 0x03, 0x0C, 0x30, 0x00, 
    0x0C, 0x00, 0x03, 0x0C, 0x30, 0x00, 0x21, 0x20, 0x01, 0x0C, 0x20, 0x01, 0x21, 0x30, 0x00, 0x8C, 
    0x00, 0x07, 0x0C, 0x30, 0x00, 0x31, 0x90, 0x02, 0x25, 0x30, 0x02, 0x04, 0x40, 0xE0, 0x7B, 0x01, 
    0x18, 0x80, 0xFE, 0x13, 0x80, 0x01, 0xE8, 0x7B, 0x40, 0x00, 0x04, 0x30, 0x80, 0x00, 0x08, 0x00, 
    0x01, 0x20, 0x00, 0x02, 0x18, 0x00, 0x70, 0xA0, 0x48, 0x85, 0x50, 0x08, 0x8A, 0x00, 0x09, 0x10, 
    0x00, 0x01, 0x13, 0x4A, 0x81, 0x14, 0xF0, 0x00, 0x0C, 0x20, 0x01, 0x10, 0x00, 0x05, 0x90, 0x00, 
    0x05, 0x10, 0xE0, 0x00, 0x00, 0x00, 0x08, 0x60, 0x00, 0x01, 0x10, 0x32, 0x81, 0x14, 0x4A, 0x01, 
    0x0F, 0x00, 0x00, 0x80, 0x00, 0x06, 0x80, 0x00, 0x06, 0x00, 0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 
    0x00, 0x02, 0xF8, 0x60, 0x00, 0x39, 0x48, 0x84, 0x82, 0x24, 0x48, 0x82, 0x44, 0x45, 0x28, 0x44, 
    0x85, 0x44, 0x48, 0x04, 0x39, 0x60, 0x00, 0xF8, 0x00, 0x30, 0x00, 0x04, 0x80, 0x00, 0x08, 0x00, 
    0x01, 0x12, 0x20, 0x01, 0x12, 0x00, 0x01, 0x08, 0x80, 0x00, 0x04, 0x30, 0x00, 0x00, 0x80, 0x00, 
    0x04, 0x20, 0x00, 0x04, 0x80, 0x00, 0x0C, 0x20, 0x21, 0x8C, 0x01, 0x07, 0x8C, 0x21, 0x24, 0x80, 
    0x01, 0x18, 0x40, 0x02, 0x18, 0x00, 0x01, 0x10, 0xC0, 0x00, 0x10, 0x00, 0x01, 0x10, 0xC0, 0x00, 
    0x10, 0x00, 0x01, 0x0E, 0x00, 0x00, 0x02, 0x50, 0x80, 0x08, 0x04, 0x01, 0x10, 0x00, 0x01, 0x13, 
    0x50, 0x81, 0x14, 0x88, 0x00, 0x70, 0xA0, 0x08, 0x8A, 0x60, 0x0A, 0xB4, 0x40, 0x08, 0x80, 0x40, 
    0x08, 0x78, 0x10, 0x48, 0x84, 0x90, 0x07, 0x00, 0x02, 0x40, 0x00, 0xC0, 0x00, 0x12, 0x00, 0x01, 
    0x10, 0x34, 0x41, 0x15, 0x4A, 0xA1, 0x08, 0x00, 0x40, 0x00, 0x02, 0x00, 0x00, 0x04, 0x20, 0x00, 
    0x04, 0x20, 0x00, 0x00, 0x40, 0x00, 0x02, 0x40, 0x00, 0x02, 0x00, 0x10, 0x00, 0x01, 0x7E, 0x10, 
    0x05, 0x29, 0x60, 0x01, 0x10, 0x00, 0x01, 0x00, 0x40, 0x00, 0x04, 0x40, 0x00, 0x04, 0x40, 0x00, 
    0x00, 0x40, 0x00, 0x04, 0x40, 0x00, 0x04, 0x40, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x40, 0x00, 
    0x3C, 0x40, 0x00, 0x00, 0xC0, 0x03, 0x08, 0x00, 0x03, 0x08, 0xC0, 0x03, 0x00, 0x07, 0x8A, 0xA0, 
    0x08, 0x86, 0x40, 0x08, 0x8C, 0x40, 0x01, 0x00, 0x04, 0x81, 0x08, 0x50, 0x00, 0x02, 0x00, 0x07, 
    0x80, 0x00, 0x08, 0x80, 0x80, 0x08, 0x94, 0x40, 0x06, 0x08, 0x00, 0x01, 0x10, 0x00, 0x01, 0x12, 
    0x10, 0x05, 0x91, 0xA0, 0x04, 0x0C, 0x80, 0x00, 0x70, 0xA0, 0x08, 0x8A, 0x60, 0x0A, 0xB4, 0xC0, 
    0x08, 0x14, 0x00, 0x60, 0x00, 0x18, 0x01, 0x16, 0x80, 0x01, 0x18, 0xFE, 0x00, 0x10, 0x00, 0x01, 
    0x70, 0x00, 0x08, 0x80, 0x00, 0x08, 0x88, 0x40, 0x09, 0x64, 0x80, 0x00, 0x10, 0x00, 0x00, 0x18, 
    0x40, 0x01, 0x11, 0x18, 0x81, 0x0C, 0x20, 0xC2, 0x1F, 0x22, 0x21, 0x20, 0x04, 0x82, 0x10, 0xF0, 
    0x00, 0x09, 0x90, 0x00, 0x0F, 0x08, 0x01, 0x00, 0x06, 0x80, 0x11, 0x60, 0x01, 0x18, 0x80, 0xE1, 
    0x0F, 0x00, 0x00, 0x00, 0x9F, 0x4F, 0x23, 0x5A, 0x24, 0x49, 0x22, 0x45, 0x2C, 0x00, 0x20, 0x00, 
    0x00, 0x20, 0x00, 0xF0, 0x80, 0x10, 0x64, 0x42, 0x29, 0x94, 0x42, 0x20, 0x08, 0x01, 0x0F, 0x00, 
    0x20, 0x00, 0x04, 0x00, 0x00, 0x20, 0x00, 0x05, 0xA8, 0x00, 0x05, 0x88, 0x00, 0x03, 0x24, 0x20, 
    0x01, 0x18, 0x40, 0x03, 0x26, 0x20, 0x01, 0x18, 0x00, 0x0F, 0x08, 0x41, 0x2F, 0x54, 0x42, 0x25, 
    0xA4, 0x82, 0x10, 0xF0, 0xC0, 0x00, 0x28, 0x40, 0x01, 0x06, 0x00, 0x00, 0x0E, 0xA0, 0x00, 0x0E, 
    0x00, 0x00, 0x20, 0x02, 0x22, 0xF8, 0x02, 0x22, 0x20, 0x02, 0x00, 0x04, 0x60, 0x11, 0x62, 0x01, 
    0x18, 0x80, 0xE1, 0x0F, 0x00, 0x40, 0x00, 0x16, 0x21, 0x16, 0x80, 0x01, 0x18, 0xFE, 0x00, 0x10, 
    0x00, 0x01, 0x00, 0x04, 0x20, 0x11, 0x64, 0x21, 0x18, 0x80, 0xE1, 0x0F, 0x40, 0x07, 0x86, 0x20, 
    0x08, 0x80, 0x80, 0x08, 0x94, 0x40, 0x06, 0x08, 0x00, 0xC1, 0x00, 0x1E, 0xE0, 0x3F, 0x02, 0xE0, 
    0x3F, 0x02, 0x00, 0x0C, 0xC0, 0x00, 0x00, 0x00, 0x08, 0xA0, 0x00, 0x0C, 0x00, 0x04, 0x20, 0x11, 
    0x64, 0x21, 0x18, 0x80, 0xE1, 0x0F, 0x00, 0x01, 0x10, 0x00, 0x00, 0x16, 0x50, 0x01, 0x00, 0x88, 
    0x00, 0x05, 0xA8, 0x00, 0x05, 0x20, 0x80, 0x00, 0x3C, 0x02, 0x10, 0xC0, 0x00, 0x13, 0x88, 0x41, 
    0x3C, 0x00, 0x81, 0x00, 0x3C, 0x02, 0x10, 0xC0, 0x00, 0x03, 0x48, 0x42, 0x34, 0xC0, 0x42, 0x02, 
    0x2C, 0x42, 0x13, 0xC0, 0x00, 0x13, 0x88, 0x41, 0x3C, 0x00, 0xC1, 0x01, 0x22, 0x20, 0x02, 0xC2, 
    0x22, 0x00, 0x04, 0x00, 0x90, 0x00, 0x01, 0x8C, 0x00, 0x01, 0x1C, 0xA0, 0x40, 0x00, 0xF2, 0x41, 
    0x00, 0x02, 0x40, 0x00, 0xF6, 0x21, 0x00, 0xC8, 0xC8, 0x92, 0x24, 0x09, 0x7C, 0x00, 0xE8, 0xDF, 
    0x00, 0x44, 0x0E, 0x06, 0x21, 0x10, 0x00, 0x81, 0x11, 0x24, 0x41, 0x12, 0xC8, 0xE0, 0x1F, 0xC0, 
    0x00, 0x12, 0x00, 0x01, 0x10, 0x00, 0x05, 0x10, 0x00, 0x01, 0x0E, 0x00, 0x20, 0x0C, 0x28, 0x21, 
    0x11, 0x20, 0x01, 0x0C, 0xC0, 0x00, 0x12, 0x00, 0x81, 0x10, 0x00, 0x81, 0x10, 0x00, 0x01, 0x0E, 
    0xC0, 0x00, 0x12, 0x00, 0x81, 0x10, 0x02, 0x81, 0x10, 0x00, 0x01, 0x0E, 0x00, 0x07, 0x8A, 0xA0, 
    0x08, 0xA6, 0x40, 0x08, 0x84, 0x00, 0x07, 0x8A, 0xA0, 0x08, 0x86, 0x40, 0x08, 0x84, 0x00, 0x07, 
    0x8A, 0xA0, 0x08, 0x86, 0x48, 0x08, 0x84, 0x00, 0x01, 0x11, 0x20, 0x01, 0x0C, 0x04, 0x01, 0x11, 
    0x20, 0x01, 0x0C, 0x00, 0x08, 0x84, 0x80, 0x07, 0x80, 0x48, 0x08, 0x78, 0x80, 0x03, 0x40, 0x00, 
    0x04, 0x40, 0x00, 0x04, 0x3C, 0x00, 0x01, 0x10, 0x00, 0x01, 0x0C, 0x00, 0x01, 0x10, 0xE0, 0x00, 
    0x38, 0x00, 0x04, 0x40, 0x00, 0x04, 0x40, 0xC0, 0x83, 0x10, 0x02, 0x81, 0x10, 0xC0, 0x00, 0x10, 
    0x00, 0x01, 0x0E, 0x80, 0x03, 0x40, 0x00, 0x04, 0x40, 0x00, 0x04, 0x3C, 0x00, 0x01, 0x18, 0x60, 
    0x01, 0x11, 0x10, 0x01, 0x0E, 0x80, 0x03, 0x40, 0x00, 0x04, 0x40, 0x00, 0x04, 0x3C, 0x00, 0x01, 
    0x18, 0x60, 0x41, 0x11, 0x10, 0x01, 0x0E, 0x00, 0x40, 0x10, 0x88, 0x00, 0x05, 0x20, 0x00, 0x05, 
    0x88, 0x40, 0x10, 0x00, 0xE1, 0x1F, 0x60, 0x01, 0x11, 0x10, 0x01, 0x0E, 0x00, 0xE1, 0x1F, 0x60, 
    0x41, 0x11, 0x10, 0x01, 0x0E, 0x60, 0x07, 0x89, 0x90, 0x08, 0x85, 0x40, 0x08, 0x76, 0x90, 0x48, 
    0x89, 0x50, 0x08, 0x84, 0x00, 0x01, 0x10, 0x00, 0x01, 0x0C, 0x20, 0x01, 0x10, 0x00, 0x01, 0x13, 
    0x4A, 0x81, 0x14, 0xF0, 0x00, 0x38, 0x00, 0x04, 0x40, 0x00, 0x44, 0x46, 0x90, 0x44, 0x29, 0xE0, 
    0x01, 0x0C, 0x20, 0x01, 0x10, 0x00, 0x01, 0x13, 0x50, 0x81, 0x14, 0x88, 0x00, 0x18, 0x52, 0x42, 
    0x25, 0x50, 0x02, 0x3E, 0x80, 0x03, 0x40, 0x00, 0x04, 0x40, 0x00, 0xE4, 0x3F, 0x80, 0x41, 0x25, 
    0x52, 0x42, 0x25, 0xE0, 0x03, 0x40, 0x00, 0x03, 0x0E, 0x10, 0x01, 0x11, 0xE0, 0x00, 0x38, 0x00, 
    0x04, 0x42, 0x00, 0x04, 0x40, 0x80, 0x03, 0x0C, 0x28, 0x01, 0x11, 0x20, 0x01, 0x0C, 0xC0, 0x08, 
    0x92, 0x20, 0x09, 0x7C, 0x30, 0x80, 0x04, 0x48, 0x80, 0x04, 0xF0, 0x00, 0x10, 0x00, 0x01, 0x03, 
    0x4A, 0xB0, 0x04, 0x49, 0x00, 0x0F, 0x00, 0x01, 0x10, 0x30, 0xA0, 0x04, 0x48, 0xA0, 0x04, 0xF0, 
    0x00, 0x10, 0x00, 0x01, 0xF8, 0x60, 0x00, 0x01, 0x88, 0x80, 0x04, 0x24, 0x40, 0x32, 0x04, 0x40, 
    0x32, 0x24, 0x80, 0x04, 0x88, 0x0C, 0x01, 0x60, 0x00, 0xF8, 0x00, 0x30, 0x00, 0x04, 0x80, 0x00, 
    0x08, 0x00, 0x01, 0x10, 0x00, 0x01, 0x12, 0x20, 0x01, 0x09, 0x80, 0x00, 0x04, 0x30, 0x00, 0xE0, 
    0x00, 0x10, 0x00, 0x01, 0x50, 0x18, 0x41, 0x52, 0x24, 0x81, 0x0C, 0xE0, 0x00, 0x10, 0x00, 0x01, 
    0x10, 0x18, 0x41, 0x12, 0x24, 0x81, 0x0C, 0x80, 0x0F, 0x06, 0x10, 0x8F, 0x14, 0x28, 0x4F, 0x12, 
    0x44, 0x41, 0xF0, 0x44, 0x41, 0x12, 0x28, 0x8F, 0x14, 0x10, 0x0F, 0x06, 0x80, 0x0F, 0x00, 0x03, 
    0x40, 0x00, 0x09, 0xB0, 0x00, 0x14, 0x40, 0x01, 0x17, 0x40, 0x01, 0x16, 0xB0, 0x00, 0x09, 0x40, 
    0x00, 0x03, 0x00, 0x10, 0x40, 0x01, 0x0A, 0xA0, 0x00, 0x14, 0x00, 0x01, 0x70, 0xA0, 0x08, 0x85, 
    0x50, 0x08, 0x8A, 0x00, 0x09, 0x10, 0x00, 0x41, 0x0E, 0x00, 0x01, 0x10, 0xFE, 0x00, 0x1E, 0x14, 
    0x22, 0x21, 0x14, 0x02, 0x21, 0xE0, 0x01, 0x10, 0x00, 0x01, 0x16, 0x92, 0x01, 0x11, 0x90, 0x00, 
    0x08, 0x00, 0x01, 0x14, 0xA4, 0x00, 0x0A, 0x40, 0x01, 0x10, 0x20, 0x00, 0x02, 0x20, 0xC0, 0x1A, 
    0x20, 0x00, 0x02, 0x20, 0x00, 0x10, 0x00, 0x01, 0x0E, 0x10, 0x01, 0x11, 0xE0, 0x00, 0x1F, 0x00, 
    0x22, 0x20, 0x04, 0x02, 0x10, 0xF0, 0x03, 0x10, 0x00, 0x41, 0x13, 0x54, 0xA1, 0x14, 0x8A, 0x00, 
    0x1F, 0x04, 0x22, 0x20, 0x04, 0x02, 0x10, 0xF0, 0x03, 0x00, 0x06, 0x88, 0xD1, 0x60, 0x05, 0x18, 
    0x80, 0xE1, 0x0F, 0x00, 0x05, 0x90, 0xC0, 0x04, 0x10, 0x00, 0x01, 0x1E, 0x14, 0x41, 0x11, 0xE8, 
    0x01, 0x11, 0xE0, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00
	};

#endif
