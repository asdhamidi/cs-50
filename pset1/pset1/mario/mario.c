#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    //To take an input of a number between 1 and 8
    do
    {
        height = get_int("Height :");
    }
    while (height > 8 || height < 1);
    //To print the required pyramid
    for (int i = height; i >= 1; i--)
    {
        for (int j = 1; j <= height; j++)
        {
            if (j >= i)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf(" ");
        for (int j = i; j >= height ; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}    