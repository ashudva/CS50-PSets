#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //check correct usage
    if (argc != 2)
    {
        fprintf(stderr, "usage: ./recover name.raw\n");
        return 1;
    }

    //open file to read
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }
    //buffer for each block
    unsigned char block[512];

    //buffer for sprintf
    char name[8];
    int imgNum = 0;
    int found = 0;
    FILE *img = NULL;

    //repeat untill fond EOF
    while (fread(block, 512, 1, file) == 1)
    {
        //start of a new JPEG
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {
            //if found any JPEG
            if (found)
            {
                //image found so close previous image
                fclose(img);
                sprintf(name, "%03i.jpg", imgNum);
                img = fopen(name, "w");
                imgNum++;
            }
            //if no any image found
            else
            {
                found = 1;
                sprintf(name, "%03i.jpg", imgNum);
                img = fopen(name, "w");
                imgNum++;
            }
        }

        //write everytime a file is open
        if (img != NULL)
        {
            fwrite(block, 512, 1, img);
        }
    }

    //close any open file
    fclose(img);
    fclose(file);

    return 0;
}