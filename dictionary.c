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
    char* word;
    struct node* next;
}
node;

char wordIn[46];

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
    // open the dictionary file
    FILE* newDict = fopen(dictionary, "r");
    
    // create root for hash table
    node* root[27];
    
    for (int i = 0; i < 27; i++)
    {
        root[i] = NULL;
    }
    
    node* head;
    head = NULL;
    
    // while there are words to read
    while(fscanf(newDict, "%s ", wordIn) > 0)
    {
        // hash the first letter for the location in root
        int hash = wordIn[0] - 97;
        
        if(root[hash] == NULL)
        {
            // make new node
            node* newNode = malloc(sizeof(node));
                
            // check for NULL
            if(newNode == NULL)
            {
                return false;
            }
                
            // intitialize
            newNode->word = wordIn;
            newNode->next = NULL;
            
            // connect to root
            root[hash] = newNode;
            
            // new node is now the head
            head = newNode;
        }
        
        else
        {
            // make new node
            node* newNode = malloc(sizeof(node));
                
            // check for NULL
            if(newNode == NULL)
            {
                return false;
            }
                
            // intitialize
            newNode->word = wordIn;
            newNode->next = NULL;
            
            // insert new node at head
            newNode->next = head;
            
            // update head
            head = newNode;
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
