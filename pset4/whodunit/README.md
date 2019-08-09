# Questions

## What's `stdint.h`?

1. *stdint.h* allows us to make our program more dyanamic (i.e. you can run your program universally on any system) by providing us a set of typedefs that
   specify more advanced integer data types (i.e. exact width integers, max and min width integers) and their size.
2. Actual size of already available integer types depends on implementation, processor and compiler thus size may vary across different platform or system
   as even on the same processor two different compiler implementation may differ.
3. You don't know everytime that what size an int gonna take 32 bit or 16 bit, what size a long int or any other int gonna take so you can be more specific
   about the size of an int regardless of implementation of compiler and processor.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Above ints are *signed and unsigned fixed width integer data types* difined in *stdint.h*
We are using them in our program as we want our program to be dyanamic and it should run perfectly on any system
We are being more specific about the size of ints and not letting compiler or processor decide their size

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

first three are unsigned ints & LONG is signed int
*BYTE = 8 bits*(First bit / MSB is not reserved for signing in unsigned ints)
*WORD = 16 bits*
*DWORD = 32 bits* (Double Word)
*LONG = 32 bits* (Stored in 2's comp format & First bit / MSB is reserved for signing)

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

Hexadecimal - *424d*
This represent the file type & it must be of size 2 bytes & BM

## What's the difference between `bfSize` and `biSize`?

*bfsize* specifies the *size of bitmap* file in bytes whereas *bisize* specifies the *size of the structure BITINFOHEADER*

## What does it mean if `biHeight` is negative?

If *biheight* is negative then the bitmap is a *top-down DIB* and its origin is the *upper-left corner*
# Top-down DIBs cannot be compressed

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

fopen returns NULL when we run out of memory or when fopen is unsable to open the desired file.

## Why is the third argument to `fread` always `1` in our code?

The third argument to `fread` is always `1` because we read one data structure at a time.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

`padding` = 3 if `bi.biWidth` is `3`

## What does `fseek` do?

`fseek` works as File location indicator. Its like the cursor and we can change its position, it indicates the position in a file.

## What is `SEEK_CUR`?

`fseek` will move the cursor or current location in file in accordance with the current position if we use `SEEK_CUR`

## Whodunit?

It was proffesor plum with the candlestick in library.
