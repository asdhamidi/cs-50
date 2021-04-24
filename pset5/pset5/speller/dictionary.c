// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int counter = 0;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int index = hash(word); //Using the hash function to directly go to the desired array for checking.
    for (node *tmp = table[index] ; true ; tmp = tmp -> next)
    {
        if (strcasecmp(word, tmp->word) == 0)
        {
            return true; //Iterates over the linked list to find the match.
        }
        if (tmp->next == NULL)
        {
            break; //If encounters NULL, the loop breaks and false is returned.
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //This is a simple algorithm which basically takes the first letter of the passed word.
    //It changes is to lowercase and finds out the hash index by calculating the difference in ASCII value.
    //It basically calculates how far the first letter is from the lowercase 'a', and returns that value.
    return (((int)(tolower(word[0])) - 96)); 
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *input = fopen(dictionary, "r"); //Opening a file named input to take the values of dictionary.
    if (input == NULL)
    {
        fclose(input); //If a value is not alloted return false and close the file.
        free(input);
        return false;
    }
    
    char word[LENGTH + 1];
    int filled = 0; // To check if the first node if filled or not.
    
    while (true)
    {
        
        if ((fscanf(input, "%s", word) == EOF))
        {
            //This closes this function when EOF is encountered and closes the input file.
            fclose(input); 
            return true;
        }
        
        node *current = malloc(sizeof(node)); //Creating a new node.
                    
        if (current == NULL)
        {
            return false;
        }
                    
        strcpy(current->word, word);//Copying the word into the "word" element of the node struct.
        current->next = NULL;
        
        int c1 = hash(word); //getting the hash
        
        if (filled == 0)
        {
            //This part is for initializing a bucket.
            table[c1] = current;
            counter++;
            filled = 1;
        }
        else
        {
            //This part is for filling into already initialized buckets.
            current->next = table[c1];
            table[c1] = current;
            counter++;
        }
    }
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0 ; i < N ; i++) //Going over each bucket.
    {
        node *cursor = table[i];
        
        while (cursor)
        {
            //This loop while go over each node of the linked lists freeing the memory.
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        
        if (i == N - 1 && cursor == NULL)
        {
            //The function will end as NULL is encountered in the last bucket.
            return true;
        }
    }
    

    return false;
}
