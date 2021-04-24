#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int checker(string, int); //Prototype for the function which will check if the arguement/key is valid or not.

int main(int argc, string argv[])
{
    string key = argv[1]; //Putting the key in a variable called key for ease in further use.
    int check = checker(key, argc);
    if (check == 1) //If the check function returned one, the key is invalid and main have to return 1, as well.
    {
        return 1;
    }

    //Getting the plain text from the user.
    string plain = get_string("plaintext: ");

    int length = strlen(plain);

    printf("ciphertext: ");

    char ch;
    int chNum;

    //This loop will go through the plain text, character by character, and change it as per the key.
    for (int i = 0; i < length ; i++)
    {
        ch = plain[i];
        if (!(isalpha(ch))) //This will check if a certain character is not an alphabet, hence print it as is.
        {
            printf("%c", ch);
        }
        else if (ch >= 'a' && ch <= 'z') //This will deal with the lower case alphabets and change them accordingly.
        {
            chNum = (int)ch;
            //This basically uses the ASCII digit of an alphabet and finds its position from the letter 'a' to deteremine which letter to use from the key, and turn it lowercase as needed.
            printf("%c", tolower(key[(chNum - 97)]));
        }
        else if (ch >= 'A' && ch <= 'Z') //This will do the same with upper case alphabets.
        {
            chNum = (int)ch;
            //This basically uses the ASCII digit of an alphabet and finds its position from the letter 'A' to deteremine which letter to use from the key, and turn it lowercase as needed.
            printf("%c", toupper(key[(chNum - 65)]));
        }
    }
    printf("\n");
    return 0;
}

int checker(string k, int argc)
{
    if (argc > 2 || argc < 2)
    {
        printf("Error! No or more than 1 arguemnets.\n");
        return 1;
    }

    int keyLen = strlen(k);

    if (keyLen != 26)
    {
        printf("Error! Incompatible arguement.\n");
        return 1;
    }

    for (int i = 0; i < keyLen ; i++)
    {
        if (!(isalpha(k[i]))) //This checks if there is a non-alphabetic character in the key and shows error and stops the function.
        {
            printf("Error! Key has non-alphabetic character.\n");
            return 1;
        }

        for (int j = 0 ; j < keyLen ; j++) //This checks if the key has a duplicate letter.
        {
            if (j == i)
            {
                continue;
            }
            else if (k[i] == k[j])
            {
                printf("Error! Key has duplicate characters. \n");
                return 1;
            }
        }
    }
    return 0;
}