#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//the use of most of these function will be for onlly positive numbers, they are not supporting negative numbers and they might break the fuctions
double power(int a,int b){
    int i;
    double output;
    
    output = 1;
    if(b > 0){
        i = 0;
        while(i < b){
            output *= a;
            i++;
        }
    }else if(b < 0){
        i = 0;
        while(i > b){
            output /= a;
            i--;
        }
    }
    return output;
    
}

int sizeOfStr(char *str){
    unsigned int i;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

char* join2strs(char* mainstr,char* secstr,int i){//supposed to be called only when mainstr has already enough allocated memory for both
    int j;
    j = 0;
    printf("not joinedStr: %s|%s |i: %d\n",mainstr,secstr,i);
    while(secstr[j] != '\0'){
        printf("j: %d",j);
        mainstr[i + j] = secstr[j];
        j++;
    }
    printf("\njoinedStr: %s\n",mainstr);
    return mainstr;
}

char* int_to_str(const unsigned long long int num,const int devisor,const char iscapital){
    unsigned long long int holder;
    int i;
    int len;
    int margin;//is the margin to decide if letter in the number are capital or not

    margin = (iscapital != 0)?('A' - '0' - 10):('a' - '0' - 10);
    //printf("margin: %d\n",margin);
    holder = num;
    i = 0;
    do{
        holder /= devisor;
        i++;
    }while(holder != 0);

    len = i;
    char *str = malloc(sizeof(char) * len + 1);
    //printf("len: %d\n",len);
    
    i = 0;
    holder = num;
    do{
        if((holder % devisor) > 9){//ensures that the devisor is above 10 aka in hex, but technically anydevisor will work with the entire system
            str[len - i - 1] = (holder % devisor) + '0' + margin;
        }else{
            str[len - i - 1] = (holder % devisor) + '0';
        }
        holder /= devisor;
        i++;
    }while(holder != 0);
    str[len] = '\0';

    return str;
}

char* decimalfloat_to_str(const double num,const int accuracy){//the accuracy because the the floating point accuracy is a goddam mess, there isnt one correct
    //output, u have to choose the degree of accuracy first thing
    //this only works with the base 10, will make one with a custom devisor soon
    int i;
    int j;
    double holder;
    char *intstr;
    char *doublestr;
    unsigned long long int intpart;
    
    intpart = (int)num;
    holder = num - intpart;
    //printf("holder: %f\n",holder);

    //we will the int part on its own, and turn the float part to an int before too turning it
    //to a str too, after adding a point
    intstr = int_to_str(intpart,10,0);
    //printf("int part: %s\n",intstr);
    i = 0;
    while(i < accuracy){
        holder *= 10;
        i++;
    }
    j = 0;
    while(intstr[j] != '\0'){
        j++;
    }
    doublestr = realloc(intstr,i + j + 2);//account for int part, float part and also both the '.' and the terminator
    //printf("i + j: %d\n",i + j);
    intstr = int_to_str(holder,10,0);
    doublestr[j] = '.';
    i = 0;
    while(intstr[i] != '\0'){
        doublestr[i + j + 1] = intstr[i];
        i++;
    }

    doublestr[i + j + 1] = '\0';

    return doublestr;
}


char* floatpart_to_str(const double num, const int devisor, const int accuracy,const char iscapital){
    //this a better float_to_str function that works with custom bases(devisors) but this one only takes care of the 
    //values after the coma
    int expo;//expo represents the exponent degree, it can be calculate with i but wth man, 4 bytes
    int i;
    int j;
    double holder;
    char *floatstr;
    char *str;
    int margin;

    margin = (iscapital != 0)?('A' - '0' - 10):('a' - '0' - 10);
    str = malloc(accuracy + 1);
    holder = num - (int)num;

    expo = -1;
    i = 0;
    while(expo >= - accuracy){
        ///printf("%d\n",expo);
        if(holder >= power(16,expo)){//holder will be between 1 * pow(..) and 15 * pow(..), from there we check what is the
            //highest number x from 1 to 15 checks that checks the condition holder >= x * power(16,i)
            ///printf("uhuh\n");
            //holder can never be above 15 * power(16,expo) as if it was it will be picked by the cases
            //before that 
            j = 1;
            while(j * power(16,expo) <= holder){
                j++;
            }
            j--;
            holder -= j * power(16,expo);
            if(j > 9){
                str[i] = j + '0' + margin;//to take care of letters in hex
            }else{
                str[i] = j + '0';
            }

        }else{
            str[i] = '0';
        }
        i++;
        expo--;
    }
    str[accuracy] = '\0';

    return str;
}

char* float_to_hexstr(const double num,const int accuracy,const char iscapital){
    //to take care of entire decimal float, even the int part and turn all of it to hex float
    int i;
    int j;
    int h;
    double holder;
    unsigned int expo;
    char exposign;
    char* tmpstr;
    char* tmpstr2;
    char* tmpstr3;
    char* str;

    holder = num;
    expo = 0;
    exposign = (num >= 1)?('+'):('-');
    while(((int)holder) != 1){
        (holder >= 1)?(holder /= 2):(holder *= 2);
        expo++;
    }

    tmpstr = int_to_str((int)holder,16,0);//in usual case this always outputs "1", thats what the previous loop makes sure of but, just in case man, just in case
    tmpstr2 = floatpart_to_str((holder - (int)holder),16,accuracy,iscapital);
    tmpstr3 = int_to_str(expo,10,0);

    printf("tmpstr: %s  |size1: %d\n",tmpstr,sizeOfStr(tmpstr));
    printf("tmpstr2: %s |size2: %d\n",tmpstr2,sizeOfStr(tmpstr2));
    printf("tmpstr3: %s |size3: %d\n",tmpstr3,sizeOfStr(tmpstr3));
    

    str = malloc(sizeOfStr(tmpstr) + sizeOfStr(tmpstr2) + sizeOfStr(tmpstr3) + 5);
    str[0] = '0';
    str[1] = (iscapital)?'X':'x';

    i = 2;
    join2strs(str,tmpstr,i);
    i += sizeOfStr(tmpstr);
    str[i] = '.';
    i++;
    join2strs(str,tmpstr2,i);
    i += sizeOfStr(tmpstr2);
    str[i] = (iscapital)?('P'):('p');
    str[i + 1] = exposign;
    i += 2;
    join2strs(str,tmpstr3,i);
    i += sizeOfStr(tmpstr3);
    str[i] = '\0';


    free(tmpstr);
    free(tmpstr2);
    free(tmpstr3);

    return str;
}



char* double_to_sc_notaion(const double num,const int accuracy,const char iscapital){
    int i;
    int j;
    int h;
    double holder;
    char *expostr;
    char *str;
    char sign;

    sign = (num >= 1)?('+'):('-');
    holder = num;
    i = 0;
    j = 0;
    while(holder < 1 || holder > 9){//assume num is always positive
        //a certain level of information detail is lost here, the values at the very edge to the right,
        //will be lost when u devide, but its fine, until another solution is implemented!
        //if a number is smaller than 0 it cant magically turn above 9 so if u multiply at first u will only keep multiplying, same for devision
        holder = (holder < 1)?(holder * 10):(holder / 10);
        j++;
    }
    
    str = decimalfloat_to_str(holder,accuracy);
    expostr = int_to_str(j,10,0);
    j = 0;
    while(str[j] != '\0'){
        j++;
    }
    i = 0;
    while(expostr[i] != '\0'){
        i++;
    }

    str = realloc(str,j + i + 2);
    str[j] = (iscapital)?('E'):('e');
    str[j + 1] = sign;
    
    h = 0;
    while(h < i){
        str[j + 2 + h] = expostr[h];
        h++; 
    }
    free(expostr);
    str[j + 2 + h] = '\0';

    return str;
    
}








int main(){

    double x = 154894.2356974568;
    //printf("printf: %+d\n",int_to_str(x,10,0));
    printf("mine:%s\n",float_to_hexstr(x,20,1));
    //printf("inttostr: %s\n",int_to_str(0,10,0));
    printf("help:%.20A\n",x);

    return 0;
}