#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //Checks if there is an input in the command line arguments.
    if (argc != 2)
    {
        printf("No file found\n");
        return 1;
    }
    //Puts the data from card.raw into the input pointer.
    FILE *input = fopen(argv[1], "r");
    //Checks if there is any data or not
    if (!input)
    {
        return 1;
    }
    //Initializing bytes which will hold the data in the successive iterations of the while loop.
    unsigned char bytes[512];
    //imgCount will keep the count for the naming purposes.
    int imgCount = 0;
    //status wiil help in keeping checks in the while loop
    int status = 0;
    //output pointer will help in creating new jpegs by acting as pointer for them.
    FILE *output = NULL;
    
    while (fread(&bytes, 512, 1, input) == 1)
    {
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
        {
            if (status == 1) //Checking if we already have an open jpeg and closing it when found a new jpeg.
            {
                fclose(output);
            }
            else
            {
                status = 1; //Keeping the status quo otherwise. This wiil also ensure to find the first jpeg in the memory.
            }
            char name[8];
            sprintf(name, "%03i.jpg", imgCount);
            output = fopen(name, "w");
            imgCount++;
        }
        if (status == 1)
        {
            fwrite(&bytes, 512, 1, output); 
        }
    }
    if (output == NULL)
    {
        fclose(output);
    }
    
    if (input == NULL)
    {
        fclose(input);
            
    }
        
    return 0;
}
