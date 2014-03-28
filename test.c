/****************************************************************************
 * testing for loading a dictionary
 *
 * attempts to fread the dictionary file and eventually a hash table trie
 * 
 * attempts to print test values loaded into dictionary and make a trie
 * 
 ***************************************************************************/
 #include <stdbool.h>
 #include <stdio.h>
 #include <stdlib.h>
 
 
 // default dictionary
#define DICTIONARY "smallDict"
// #define DICTIONARY "/home/cs50/pset6/dictionaries/large"

// struct used for trie data structure
typedef struct node
{
    bool wordEnd;
    struct node* children[27];
}
node;

int main(int argc, char* argv[])
{
    // check for correct number of args
    if (argc != 2 && argc != 3)
    {
        printf("Usage: test [dictionary] text\n");
        return 1;
    }

    // determine dictionary to use
    char* dictionary = (argc == 3) ? argv[1] : DICTIONARY;
    
    // open the dictionary file
    FILE* newDict = fopen(dictionary, "r");
    
    // create root for trie data structure
    node* root = malloc(sizeof(node));
    
    if (root == NULL)
    {
        printf("Could not malloc root node");
        return 2;
    }
    
    // initialize root's children to NULL
    root->wordEnd = false;
    for(int i = 0; i <= 27; i++)
    {
        root->children[i] = NULL;
    }
    
    // create cursor
    node* cursor = malloc(sizeof(node));
    
    if (cursor == NULL)
    {
        printf("Could not malloc cursor ");
        return 3;
    }
    
    // initialize cursor's children to NULL
    cursor->wordEnd = false;
    for(int i = 0; i <= 27; i++)
    {
        cursor->children[i] = NULL;
    }
    
    cursor = root;
    
    char buffer[1];
    char word[47];
    int counter;
    
    // for every character in dictionary
    while(! feof(newDict))
    {
        counter = 0;
        
        // make word
        while(buffer[0])
        {
            fread(buffer, sizeof(char), 1, newDict);
            word[counter] = buffer[0];
            
            if (buffer[0] == '\n')
            {
                break;
            }
            
            counter++;
        }
        
        // add to trie
        for(int i = 0; i < counter; i++)
        {
            int hash;
            
            if(word[i] == '\n')
            {
                continue;
            }
            
            // if an apostrophe
            else if(word[i] == 39)
            {
                hash = 26;
            }
            
            // if between a and z
            else
            {
                hash = word[i] - 97;
            }
            
            // if hash node* is NULL, make new one
            if (cursor->children[hash] == NULL)
            {
                // make new node
                node* newNode = malloc(sizeof(node));
    
                if (newNode == NULL)
                {
                    printf("Could not malloc cursor ");
                    return 4;
                }
                
                // initialize children to NULL
                newNode->wordEnd = false;
                for(int i = 0; i <= 27; i++)
                {
                    newNode->children[i] = NULL;
                }
                
                // connect the new node
                cursor->children[hash] = newNode;
                
                // keep track of current position in the trie
                cursor = newNode;
                
                //  if end of word
                if(i == counter)
                {
                    newNode->wordEnd = true;
                    
                    // reset cursor to point to beginning root
                    cursor = root;
                } 
            }   
        }
    }
    fclose(newDict);
    
    return 0;
}
