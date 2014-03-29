/****************************************************************************
 * dictionary.c aj;dsjf;adf git load
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

typedef struct node
{
    char* word[45];
    struct node* next;
}
node;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    
    // open the dictionary file
    FILE* newDict = fopen(dictionary, "r");
    
    // create root for hash table
    node* root[27];
    
    for (int i = 0; i < 27; i++)
    {
        root[i] = NULL;
    }
    
    // for every dictionary word, iterate through the trie
    
    
    // each element in children corresponds to a different letter
    
    
    // check the value of children[i]
    
    
        // if NULL create a new node and point children[i] point to it
        
        
        // if not NULL move to new node and continue
    
    
    // if at end of word, set 'isWord' to true
    
    
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
