/****************************************************************************
 * dictionary.c aj;dsjf;adf git load
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

typedef struct node
{
    char* dword;
    struct node* next;
}
node;

// keep track of #of words in dictionary loaded
int wordCounter = 0;

// create root for hash table
node* root[26];

// create cursor to keep place in creating, pointing, and traversing through nodes
node* current = NULL;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    
    // size of word read into buffer
    int wordSize = sizeof(word);
    
    // prepare to make a new lowercase only word for comparison
    char bufWord[wordSize];
    
    // make it
    for(int i = 0; i < wordSize; i++)
    {   
        if (i == wordSize - 1)
        {
            bufWord[i] = '\0';
        }
        
        else
        {
            bufWord[i] = tolower(word[i]);
        }
    }
    
    // hash word to achieve proper root node location
    int hash = bufWord[0] - 97;
    
    // point to the correct root node to begin traversing
    current = root[hash];
    
    // make sure there is even a word in hash table location
    if(root[hash] == NULL)
    {
        return false;
    }
    
    else if(root[hash] != NULL)
    {
        // progress through the nodes until the last node's next pointer member is NULL
        while(current != NULL)
        {               
            // hold a copy of the dictionary word limiting to the same #of characters as word to check
            char dictWord[wordSize];
            
            // hold copy of struct member value to compare to dictWord
            char* wordTemp = current->dword;

            //  check dictionary word against struct member value
            if 
            
            printf("current is: %p\n", current);
            printf("current->next is: %p\n", current->next);
            printf("current->dword is: %s\n", wordTemp);
            printf("wordTemp = current->dword is: %s\n\n", current->dword);
            
            for(int i = 0; i < wordSize; i++)
            {   
                dictWord[i] = wordTemp[i];
            }
            
            // do a spell check
            if(strcmp(bufWord, dictWord) == 0)
            {
                return true;
            }
            
            else
            {
                // set current to the next node if any or NULL if it's already the last node in the list
                current = current->next;
            }
        }    
    }
    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{   
    // buffer for reading in dictionary words
    char wordIn[LENGTH + 1];
    
    // open the dictionary file
    FILE* newDict = fopen(dictionary, "r");
    
    for (int i = 0; i < 27; i++)
    {
        root[i] = NULL;
    }
    
    // while there are words to read
    while(fscanf(newDict, "%s ", wordIn) > 0)
    {
        
        // keep track of #of words for constant time read in size function
        wordCounter++;
        
        // hash the first letter for the location in root
        int hash = wordIn[0] - 97;
        
        // malloc space for a new node
        node* newNode = malloc(sizeof(node));
        
        // error check
        if (newNode == NULL)
        {
            return false;
        }
        
        // set value member of node to current word
        newNode->dword = wordIn;
        
        // first insertion into linked list if that root node has not been used yet 
        if(root[hash] == NULL)
        {
            // sets to NULL
            newNode->next = root[hash];
            
            // link it
            root[hash] = newNode;
        }
        
        else if(root[hash] != NULL)
        {
            // starts at the root
            node* current = root[hash];
            
            // insert into new beginning of list
            newNode->next = current;
            root[hash] = newNode;
        }
    }
    
    fclose(newDict);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return wordCounter;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
