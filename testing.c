#include <stdio.h>
#include <stdarg.h>

#include <stdlib.h>

char* ass(va_list* args){
    va_arg(*args, int);
    va_arg(*args, int);
    return "stringgsgsgsg";
}

void print(int num,...){
    va_list args;
    va_start(args,num);

    //char* strr = ass(&args);
    
    va_arg(args,int);
    printf("%d\n",*args);
    va_arg(args,int);
    printf("%d\n",*args);
    //printf("%s\n",strr);
    va_end(args);
}

#define ullint unsigned long long int 
int main(){
    int x = 2;

    //x  = x++ - x;
    
    printf("%d\n",(++x - x + 1));
    //printf("sizeof(x): %d",sizeof(short int));
    return 0;
}