#include "input.h"
#include <stdlib.h>
#include <string.h>
#ifndef NULL
#define NULL 0
#endif

int getNumCandies(FILE * file){
    printf("Counting those candies!\n");
    int count = 0;
    int maxChars = 255;
    char *line = malloc(sizeof(char)*maxChars);
    while(feof(file) == 0){
        fscanf(file, "%s", line);
        if(strcmp(line, "START") == 0){
            count++;
        }
        line = NULL;
        line = malloc(sizeof(char)*maxChars);
        //printf("%d\n", count);
    }
    rewind(file);
    return count;
}

