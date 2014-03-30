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
    char* word;
    struct node* next;
}
node;

char wordIn[46];

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
                exit(1);
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
                exit(1);
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
    fclose(dictionary);
    return 0;
}
