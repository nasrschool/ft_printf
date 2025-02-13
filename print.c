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


int the_great_extactor(const char* str, char *flagptr, unsigned int *widthptr, unsigned int *precisionptr,
    int *lengthmodptr,char *specifier,int i){
    char flags[] = {'-','+',' ','#','0'};
    char specifiers[] = {'d','i','u','o','x','X','f','F','e','E','g','G','a','A','c','s','p','n','%','\0'};
    unsigned int j;
    unsigned int h;

    i++;
    *flagptr = 'n';//means no flag was found which would be the default,it cant equal n on its own so i will use this as another flag
    j = 0;
    while(flags[j] != '\0'){
        if(str[i] == flags[j]){
            *flagptr = flags[j];
            i++;
            break;
        }
        j++;
    }
    
    *widthptr = 0;
    while((str[i] <= 9 + '0') && (str[i] >= '0')){
        printf("(str[i] - '0'): %d\n",(str[i] - '0'));
        *widthptr = *widthptr * 10 + (str[i] - '0');
        i++;
    }


    *precisionptr = 0;
    if(str[i] == '.'){
        i++;
        j = 0;
        while((str[i] <= 9 + '0') && (str[i] >= '0')){
            *precisionptr = *precisionptr * 10 + (str[i] - '0');
            i++;
        }
    }

    switch(str[i]){
    case 'h':
        i++;
        *lengthmodptr = (str[i] == 'h')?(++i - i + 1):(0);//++i - i will give 0 always, just wanted to increment i aswell
        break;
    case 'l':
        i++;
        *lengthmodptr = (str[i + 1] == 'l')?(++i - i + 3):(2);
        break;
    case 'j':
        *lengthmodptr = 4;
        i++;
        break;
    case 'z':
        *lengthmodptr = 5;
        i++;
        break;
    case 't':
        *lengthmodptr = 6;
        i++;
        break;
    case 'L':
        *lengthmodptr = 7;
        i++;
        break;
    default:
        *lengthmodptr = -1;
    }

    
    j = 0;
    while(specifiers[j] != '\0'){
        if(str[i] == specifiers[j]){
            *specifier = specifiers[j];
            i++;
            break;
        }
        j++;
    }
    
    return j;
}

/*int print(const char* str,...){
    va_list args;
    char* specifiers = {'d','i','u','o','x','X','f','F','e','E','g','G','a','A','c','s','p','n','%','\0'};
    char* flags = {'-','+',' ','#','*'};
    // width is a number;
    //presision is also a number that starts with .(not a decimal)
    char sign;
    int i;
    char* specifier;
    unsigned int width;
    unsigned int precision;
    char *lengthptr;


    va_start(args,str);

    i = 0;
    while(str[i] != '\0'){
        if(str[i] == '%'){
            //
        }
    }
    
    return 0;
}*/


int main(){
    char *str = "%#20.30ld";
    char flag; 
    unsigned int width; 
    unsigned int precision;
    int length;
    char specifier;
    int i;

    i = 0;
    i = the_great_extactor(str,&flag,&width,&precision,&length,&specifier,i);

    printf("test: %s | %c | %u | %u | %d | %c",str,flag,width,precision,length,specifier);

    return 0;

}