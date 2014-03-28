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
    
    char buffer[1];
    char word[47];
    int counter = 0;
    
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
    
    fclose(newDict);
    
    return 0;
}
