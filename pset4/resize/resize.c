// Resizes a BMP file by factor n

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    //convert n to int from string
    int n =  atoi(argv[1]);

    // ensure proper usage
    if (argc != 4 || argv[1] < 0 || n > 100)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 1;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 1;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 1;
    }
    // determines padding for infie to use in fseek
    int paddingIn = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //saving old height to a variable
    int biHeight = abs(bi.biHeight);
    int biWidth = bi.biWidth;

    // modifying headers accordingly
    bi.biWidth *= n;
    bi.biHeight *= n;

    // determine padding for scanlines for outfile
    int paddingOut = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //modifying size attributes of headers
    bi.biSizeImage = (paddingOut + (sizeof(RGBTRIPLE) * bi.biWidth)) * abs(bi.biHeight);
    bf.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi.biSizeImage;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0; i < biHeight; i++)
    {
        // temporary storage
        RGBTRIPLE triple;
        RGBTRIPLE temp[bi.biWidth];

        //set count to zero for each scanline
        int count = 0;
        //for each pixel
        for (int b = 0; b < biWidth; b++)
        {
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            //write to array n times
            for (int x = 0; x < n; x++)
            {
                temp[count] = triple;
                count++;
            }
        }
        // write array n times
        for (int a = 0; a < n; a++)
        {
            //iterate over array to write each element
            for (int y = 0; y < bi.biWidth; y++)
            {
                // write RGB triple to outfile
                fwrite(temp + y, sizeof(RGBTRIPLE), 1, outptr);
            }

            //adding paddingOut to outfile
            for (int k = 0; k < paddingOut; k++)
            {
                fputc(0x00, outptr);
            }
        }
        // skip over padding, if any
        fseek(inptr, paddingIn, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
