#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //Getting the sentence from the user.
    string data = get_string("Text : ");
    
    int length = strlen(data);
    int letter = 0, words = 0, sentences = 0;
    float avgLet, avgSent;
    char ch;
    
    //Using a for-loop to count letters, words, and sentences.
    for (int i = 0 ; i < length ; i++)
    {
        ch = data[i];
        if (isalpha(ch))
        {
            letter++;
        }
        if (isspace(ch))
        {
            words++;
        }
        if (ch == '.' || ch == '!' || ch == '?')
        {
            sentences++;
        }
    }
    
    words = words + 1;
    
    //Calculating the average number of letters per 100 words.
    avgLet = (letter / (float)words) * 100.00;
    
    //Calculating the average number of sentences per  100 words.
    avgSent = (sentences / (float)words) * 100.00;
    
    //Calculating the index.
    float index = 0.0588 * avgLet - 0.296 * avgSent - 15.8;
    index = round(index);
    int level = (int)index;
    
    //Using a if-else if-else control structure to print the required grade level.
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index <= 16 && index >= 1)
    {
        printf("Grade %i\n", level);
    }
    else
    {
        printf("Grade 16+\n");
    }
}