// BMP-related data types based on Microsoft's own

#include <stdint.h>

// aliases for C/C++ primitive data types
// https://msdn.microsoft.com/en-us/library/cc230309.aspx
typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

// information about the type, size, and layout of a file
// https://msdn.microsoft.com/en-us/library/dd183374(v=vs.85).aspx
typedef struct
{
    //takes total 14 bytes
    //the file type must be BM
    WORD bfType;

    //defines the size of bitmap file in bytes
    DWORD bfSize;

    //must be 0
    WORD bfReserved1;

    //must be 0
    WORD bfReserved2;

    /*The offset, in bytes, from the beginning of the BITMAPFILEHEADER
      structure to the bitmap bits */
    DWORD bfOffBits;
} __attribute__((__packed__))
BITMAPFILEHEADER;

// information about the dimensions and color format
// https://msdn.microsoft.com/en-us/library/dd183376(v=vs.85).aspx
typedef struct
{
    //takes total 40 bytes of memeory
    //The number of bytes required by the structure
    DWORD biSize;

    /*The width of the bitmap, in pixels
      If biCompression is BI_JPEG or BI_PNG, the biWidth member specifies
      the width of the decompressed JPEG or PNG image file, respectively */
    LONG biWidth;

    /*The height of the bitmap, in pixels. If biHeight is positive, the bitmap is a bottom-up DIB and its origin is the lower-left corner.
      If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner
      Top-down DIBs cannot be compressed.
      ## DIB = Device-Independent Bitmap ## */
    LONG biHeight;

    //The number of planes for the target device. This value must be set to 1.
    WORD biPlanes;

    //Determines the number of bits that define each pixel and the maximum number of colors in the bitmap
    WORD biBitCount;

    //The type of compression for a compressed bottom-up bitmap
    DWORD biCompression;

    //The size, in bytes, of the image. This may be set to zero for BI_RGB bitmaps.
    DWORD biSizeImage;

    //The horizontal resolution, in pixels-per-meter, of the target device for the bitmap.
    //An application can use this value to select a bitmap from a resource group that best matches the characteristics of the current device.
    LONG biXPelsPerMeter;

    //The vertical resolution, in pixels-per-meter, of the target device for the bitmap.
    LONG biYPelsPerMeter;

    //The number of color indexes in the color table that are actually used by the bitmap.
    DWORD biClrUsed;

    //The number of color indexes that are required for displaying the bitmap. If this value is zero, all colors are required.
    DWORD biClrImportant;
} __attribute__((__packed__))
BITMAPINFOHEADER;

// relative intensities of red, green, and blue
// https://msdn.microsoft.com/en-us/library/dd162939(v=vs.85).aspx
typedef struct
{
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;
