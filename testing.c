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


int main(){
    //int *ptr = malloc(16);
   
    float num = 102.3 - ((int)(102.3 / 1));
    printf("%f\n",num);
    return 0;
}