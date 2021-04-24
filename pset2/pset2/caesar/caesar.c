#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    
    int k, length;
    string plainText, argum;
    //For checking if less than or more than 2 command line arguements are not given by the user.
    if (argc != 2)
    {
        printf("Command Line Error");
        return 1;
    }
    
    argum = argv[1];
    int argLen = strlen(argum);
    //Checking if there is a non-digit in the arguement.
    for (int i = 0 ; i < argLen ; i++)
    {
        char c = argum[i];
        if (!(isdigit(c)))
        {
            return 1;
        }
        
    }
    //Converting String form of arguement into the int form
    k = atoi(argum);

    //This if control structure makes sure if the key is more than 26 it changed to neeeded number.
    if (k > 26)
    {
        k = k % 26;
    }
    
    plainText = get_string("plaintext: ");
    //To get the length of the entered string for the for-loop
    length = strlen(plainText);
    
    char ch;
    
    printf("ciphertext: ");
    //This for loop changes each letter of the plain text, one by one, to the cipher text.
    for (int i = 0 ; i < length ; i++)
    {
        ch = plainText[i];
        int chNum = (int)ch;
        int k1 = k;
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            if (plainText[i] + k <= 'z' || plainText[i] + k <= 'Z')
            {
                printf("%c", plainText[i] + k);
            }
            else if (chNum + k > 122)
            {
                k1 = k1 - (123 - chNum);
                
                printf("%c", (97 + k1));
            }
            else if (plainText[i] + k > 'Z')
            {
                k1 = k1 - (91 - chNum);
                printf("%c", (65 + k1));
            }
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    
    printf("\n");
    return 0;
}