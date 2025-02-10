#include "header.h"
#include <stdio.h>

char** specifiers_casing(const char speci,va_list* args){
    //char** specifiers = {{'d','i'},{'u'},{'o'},{'x','X'},{'f','F'},{'e','E'},{'g','G'},{'a','A'},{'c'},{'s'},{'p'},{'n'},{'%'}};
    char* str;
    char sign;
    switch(speci){
    case 'd':
        

    }
}

int print(const char* str,...){
    va_list args;
    char** specifiers = {{'d','i'},{'u'},{'o'},{'x','X'},{'f','F'},{'e','E'},{'g','G'},{'a','A'},{'c'},{'s'},{'p'},{'n'},{'%'}};
    char** types = {"signed int","usigned int","unsigned octal",""}
    float buffer;
    char* new_string;

    va_start(args,str);
    
    return 0;
}
