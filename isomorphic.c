#include <stdio.h>
#include <stdbool.h> 
#include <string.h>
#include <assert.h>

int isomorphic(char *str1, char *str2);

int main()
{
    assert(isomorphic("ok", "tp") == 1);
    assert(isomorphic("oo", "oo") == 1);
    assert(isomorphic("abc", "def") == 1);
    assert(isomorphic("foo", "bar") == 0);
    assert(isomorphic("bar", "foo") == 0);
    assert(isomorphic("o", "pt") == 0);
    assert(isomorphic("", "") == 1);
    assert(isomorphic("", "t") == 0);
    printf("Success\n");
    return 0;
}

int isomorphic(char *str1, char *str2){
    int i; 
    
    if (strlen(str1) != strlen(str2))
        return 0;
    
    //create empty arrays for our key-value pairs using ASCII keys
    char fromstr1[128]; //keep track of mapping from str1 to str2
    char fromstr2[128]; //keep track of mapping from str2 to str1
    
    //initialize array to hold only values of 0 
    for (i=0; i < 128; i++){
        fromstr1[i] = 0;
        fromstr2[i] = 0;
    }
    
    // check that we don't map from the same key twice 
    for (i=0; i < strlen(str1); i++){ 
        if (fromstr1[str1[i]] == 0) // check if we already initialized this key with a value 
            fromstr1[str1[i]] = str2[i]; // if not, we create a new mapping 
        else {
            if (fromstr1[str1[i]] != str2[i]) // check if we're repeating a key-value pair
                return 0;
        }
        
        if (fromstr2[str2[i]] == 0) // check if we already associated this value with a key 
            fromstr2[str2[i]] = str1[i]; // if not, we create a new mapping
        else {
            if (fromstr2[str2[i]] != str1[i]) // check if we're repeating a key-value pair
                return 0; 
        }
    }
    
    return 1; // return true 
}
