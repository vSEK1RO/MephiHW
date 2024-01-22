/************************** Wed Dec 06 19:07:57 2023 **************************/
//#include "../clib/src/title.h"
/*                                _      _       __   _        _              */
/*        _ __ ___    ___  _ __  | |__  (_)     / /  (_)  ___ (_) ___         */
/*       | '_ ` _ \  / _ \| '_ \ | '_ \ | |    / /   | | / __|| |/ __|        */
/*       | | | | | ||  __/| |_) || | | || |   / /    | || (__ | |\__ \        */
/*       |_| |_| |_| \___|| .__/ |_| |_||_|  /_/     |_| \___||_||___/        */
/*                        |_|                                                 */
/*                                                                            */
/*                    Created by Vlad Litvinov b23-534                        */
/*                       https://github.com/vSEK1RO                           */
/*                                                                            */
//#endclude "../clib/src/title.h"
/************************************ Task ************************************/
/*                                                                            */
/*                            Works with matrices.                            */
/*             Calculates the value of a matrix "A*A^T + (A*B)^2"             */
/*                                                                            */
/******************************* INCLUDES START *******************************/

#include <inttypes.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "../clib/src/numsys.h"
#ifndef NUMSYS_H
#define NUMSYS_H

#include <inttypes.h>

char numsys_dtoc(int64_t digit);
int64_t numsys_ctod(char digit);
char * numsys_ntos(int64_t num, uint8_t base);
int64_t numsys_ston(char * str, uint8_t base);

//#include "numsys.c"
//#include "string.h"
#ifndef ITERABLE_STRING_H
#define ITERABLE_STRING_H

#include <inttypes.h>

char * str_init(uint64_t len);
char * str_cast(const char * a);
uint64_t str_len(char * a);
void str_del(char * a);
void str_copy(char ** a, char * b);
uint8_t str_isEqual(char * a, char * b);
void str_swap(char * a, uint64_t i1, uint64_t i2);
void str_rearr(char * a, uint64_t i1, uint64_t i2);
void str_erase(char ** a, uint64_t i1, uint64_t i2);
char * str_substr(char * a, uint64_t i1, uint64_t i2);
uint64_t str_find(char * a, char key, uint64_t entry);
uint64_t str_findStr(char * a, char * b, uint64_t entry);
uint64_t str_count(char * a, char n);
uint64_t str_countStr(char * a, char * b);
void str_pob(char ** a);
void str_pub(char ** a, char n);
void str_pof(char ** a);
void str_puf(char ** a, char n);
char * str_concat(char * a, char * b);
void str_ins(char ** a, char n, uint64_t i);
void str_insStr(char ** a, char * b, uint64_t i);
void str_repl(char ** a, char n, uint64_t i1, uint64_t i2);
void str_replStr(char ** a, char * b, uint64_t i1, uint64_t i2);
void str_reverse(char * a);

//#include "string.c"
#include <stdlib.h>

char * str_init(uint64_t len)
{
    char * a=(char *)calloc(sizeof(char),len+1);
    a[len]='\0';
    for(uint64_t i=0;i<len;i++){
        a[i]=' ';
    }
    return a;
}

char * str_cast(const char * a)
{   
    uint64_t len=0;
    while(a[len]!='\0'){
        len++;
    }
    char * b=str_init(len);
    for(uint64_t i=0;i<len;i++){
        b[i]=a[i];
    }
    return b;
}

uint64_t str_len(char * a)
{
    uint64_t len=0;
    while(a[len]!='\0'){
        len++;
    }
    return len;
}

void str_del(char * a)
{
    free((void *)a);
}

void str_copy(char ** a, char * b)
{
    *a = str_init(str_len(b));
    for(uint64_t i=0;i<str_len(b);i++){
        (*a)[i]=b[i];
    }
}

uint8_t str_isEqual(char * a, char * b)
{
    if(str_len(a)!=str_len(b)){
        return 0;
    }
    for(uint64_t i=0;i<str_len(a);i++){
        if(a[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}

void str_swap(char * a, uint64_t i1, uint64_t i2)
{
    i1%=str_len(a);
    i2%=str_len(a);
    a[i1]+=a[i2];
    a[i2]=a[i1]-a[i2];
    a[i1]-=a[i2];
}

void str_rearr(char * a, uint64_t i1, uint64_t i2)
{
    i1%=str_len(a);
    i2%=str_len(a);
    char buff=a[i1];
    for(uint64_t i=i1;i>i2;i--){
        a[i]=a[i-1];
    }
    a[i2]=buff;
}

void str_erase(char ** a, uint64_t i1, uint64_t i2)
{
    i1%=str_len(*a)+1;
    i2%=str_len(*a)+1;
    char * b=str_init(str_len(*a)-i2+i1);
    for(uint64_t i=0;i<i1;i++){
        b[i]=(*a)[i];
    }
    for(uint64_t i=i2;i<str_len(*a);i++){
        b[i+i1-i2]=(*a)[i];
    }
    str_del(*a);
    *a=b;
}

char * str_substr(char * a, uint64_t i1, uint64_t i2)
{
    i1%=str_len(a)+1;
    i2%=str_len(a)+1;
    char * b=str_init(i2-i1);
    for(uint64_t i=0;i<i2-i1;i++){
        b[i]=a[i+i1];
    }
    return b;
}

uint64_t str_find(char * a, char key, uint64_t entry)
{
    entry%=str_len(a)+1;
    uint64_t i=-1;
    while(entry && i!=str_len(a)){
        i++;
        if(a[i]==key){
            entry--;
        }
    }
    return (entry!=0?-1:i);
}

uint64_t str_findStr(char * a, char * b, uint64_t entry)
{
    entry%=str_len(a)+1;
    uint64_t i=-1;
    while(entry && i!=(str_len(a)-str_len(b))){
        i++;
        if(str_isEqual(str_substr(a,i,i+str_len(b)),b)){
            entry--;
        }
    }
    return (entry!=0?-1:i);
}

uint64_t str_count(char * a, char n)
{
    uint64_t c=0;
    for(uint64_t i=0;i<str_len(a);i++){
        if(a[i]==n){
            c++;
        }
    }
    return c;
}

uint64_t str_countStr(char * a, char * b)
{
    uint64_t c=0;
    for(uint64_t i=0;i<str_len(a)-str_len(b);i++){
        if(str_isEqual(str_substr(a,i,i+str_len(b)),b)){
            c++;
        }
    }
    return c;
}

void str_pob(char ** a)
{   
    if(str_len(*a)!=0){
        char * b=str_init(str_len(*a)-1);
        for(uint64_t i=0;i<str_len(*a)-1;i++){
            b[i]=(*a)[i];
        }
        str_del(*a);
        *a=b;
    }
}

void str_pub(char ** a, char n)
{
    char * b=str_init(str_len(*a)+1);
    for(uint64_t i=0;i<str_len(*a);i++){
        b[i]=(*a)[i];
    }
    b[str_len(b)-1]=n;
    str_del(*a);
    *a=b;
}

void str_pof(char ** a)
{
    if(str_len(*a)!=0){
        char * b=str_init(str_len(*a)-1);
        for(uint64_t i=0;i<str_len(*a)-1;i++){
            b[i]=(*a)[i+1];
        }
        str_del(*a);
        *a=b;
    }
}

void str_puf(char ** a, char n)
{
    char * b=str_init(str_len(*a)+1);
    for(uint64_t i=0;i<str_len(*a);i++){
        b[i+1]=(*a)[i];
    }
    b[0]=n;
    str_del(*a);
    *a=b;
}

char * str_concat(char * a, char * b)
{
    char * c=str_init(str_len(a)+str_len(b));
    for(uint64_t i=0;i<str_len(a);i++){
        c[i]=a[i];
    }
    for(uint64_t i=0;i<str_len(b);i++){
        c[i+str_len(a)]=b[i];
    }
    return c;
}

void str_ins(char ** a, char n, uint64_t i)
{
    i%=str_len(*a)+1;
    str_pub(a,n);
    str_rearr(*a,str_len(*a)-1,i);
}

void str_insStr(char ** a, char * b, uint64_t i)
{
    i%=str_len(*a)+1;
    *a=str_concat(str_concat(str_substr(*a,0,i),b),str_substr(*a,i,str_len(*a)));
}

void str_repl(char ** a, char n, uint64_t i1, uint64_t i2)
{
    i1%=str_len(*a)+1;
    i2%=str_len(*a)+1;
    str_erase(a,i1,i2);
    str_ins(a,n,i1);
}

void str_replStr(char ** a, char * b, uint64_t i1, uint64_t i2)
{
    i1%=str_len(*a)+1;
    i2%=str_len(*a)+1;
    str_erase(a,i1,i2);
    str_insStr(a,b,i1);
}

void str_reverse(char * a)
{
    for(uint64_t i=0;i<str_len(a)/2;i++){
        str_swap(a,i,str_len(a)-1-i);
    }
}
//#endclude "string.c"
#endif
//#endclude "string.h"
#include <math.h>

char numsys_dtoc(int64_t digit)
{
    if(digit>=0 && digit<10){
        return (char)(48+digit);
    }
    if(digit>=10 && digit<36){
        return (char)(55+digit);
    }
    if(digit>=36 && digit<62){
        return (char)(61+digit);
    }
    return (char)0;
}

int64_t numsys_ctod(char digit)
{
    if(digit>47 && digit<=57){
        return (int64_t)(digit-48);
    }
    if(digit>64 && digit<=90){
        return (int64_t)(digit-55);
    }
    if(digit>96 && digit<=122){
        return (int64_t)(digit-61);
    }
    return (int64_t)-1;
}

char * numsys_ntos(int64_t num, uint8_t base)
{
    char * str = str_init(0);
    if(num>0){
        while(num){
            str_puf(&str, numsys_dtoc(num%base));
            num/=base;
        }
    }else{
        num*=-1;
        while(num){
            str_puf(&str, numsys_dtoc(num%base));
            num/=base;
        }
        str_puf(&str, '-');
    }
    return str;
}

int64_t numsys_ston(char * str, uint8_t base)
{
    int64_t num = 0;
    for(uint64_t i=0;i<str_len(str);i++){
        if(str[str_len(str)-1-i]!='-'){
            num+=numsys_ctod(str[str_len(str)-1-i])*pow(base,i);
        }else{
            num*=-1;
        }
    }
    return num;
}
//#endclude "numsys.c"

#endif
//#endclude "../clib/src/numsys.h"
//#include "../clib/src/array.h"
#ifndef ARR_TYPE
#define ARR_TYPE int
#endif

#include <inttypes.h>
#define ARR_TEMPLATE(type, name) arr_  ## name ## _ ## type
#define ARR_FUNC(...) ARR_TEMPLATE(__VA_ARGS__)

ARR_TYPE * ARR_FUNC(ARR_TYPE, init)(uint64_t len);
uint64_t ARR_FUNC(ARR_TYPE, len)(ARR_TYPE * a);
void ARR_FUNC(ARR_TYPE, del)(ARR_TYPE * a);
void ARR_FUNC(ARR_TYPE, copy)(ARR_TYPE ** a, ARR_TYPE * b);
ARR_TYPE ARR_FUNC(ARR_TYPE, max)(ARR_TYPE * a);
ARR_TYPE ARR_FUNC(ARR_TYPE, min)(ARR_TYPE * a);
uint8_t ARR_FUNC(ARR_TYPE, isEqual)(ARR_TYPE * a, ARR_TYPE * b);
void ARR_FUNC(ARR_TYPE, swap)(ARR_TYPE * a, uint64_t i1, uint64_t i2);
void ARR_FUNC(ARR_TYPE, rearr)(ARR_TYPE * a, uint64_t i1, uint64_t i2);
void ARR_FUNC(ARR_TYPE, erase)(ARR_TYPE ** a, uint64_t i1, uint64_t i2);
ARR_TYPE * ARR_FUNC(ARR_TYPE, substr)(ARR_TYPE * a, uint64_t i1, uint64_t i2);
uint64_t ARR_FUNC(ARR_TYPE, find)(ARR_TYPE * a, ARR_TYPE key, uint64_t entry);
uint64_t ARR_FUNC(ARR_TYPE, findArr)(ARR_TYPE * a, ARR_TYPE * b, uint64_t entry);
uint64_t ARR_FUNC(ARR_TYPE, count)(ARR_TYPE * a, ARR_TYPE n);
uint64_t ARR_FUNC(ARR_TYPE, countArr)(ARR_TYPE * a, ARR_TYPE * b);
void ARR_FUNC(ARR_TYPE, pob)(ARR_TYPE ** a);
void ARR_FUNC(ARR_TYPE, pub)(ARR_TYPE ** a, ARR_TYPE n);
void ARR_FUNC(ARR_TYPE, pof)(ARR_TYPE ** a);
void ARR_FUNC(ARR_TYPE, puf)(ARR_TYPE ** a, ARR_TYPE n);
ARR_TYPE * ARR_FUNC(ARR_TYPE, concat)(ARR_TYPE * a, ARR_TYPE * b);
void ARR_FUNC(ARR_TYPE, ins)(ARR_TYPE ** a, ARR_TYPE n, uint64_t i);
void ARR_FUNC(ARR_TYPE, insArr)(ARR_TYPE ** a, ARR_TYPE * b, uint64_t i);
void ARR_FUNC(ARR_TYPE, repl)(ARR_TYPE ** a, ARR_TYPE n, uint64_t i1, uint64_t i2);
void ARR_FUNC(ARR_TYPE, replArr)(ARR_TYPE ** a, ARR_TYPE * b, uint64_t i1, uint64_t i2);
void ARR_FUNC(ARR_TYPE, reverse)(ARR_TYPE * a);

//#include "array.c"
#include <stdlib.h>

ARR_TYPE * ARR_FUNC(ARR_TYPE,init)(uint64_t len)
{
    uint64_t memlen;
    if(sizeof(ARR_TYPE)>sizeof(uint64_t)){
        memlen=1;
    }else{
        if(sizeof(uint64_t)%sizeof(ARR_TYPE)==0){
            memlen=sizeof(uint64_t)/sizeof(ARR_TYPE);
        }else{
            memlen=sizeof(uint64_t)/sizeof(ARR_TYPE)+1;
        }
    }
    ARR_TYPE * a=(ARR_TYPE *)calloc(sizeof(ARR_TYPE),len+memlen)+memlen;
    ((uint64_t *)a)[-1]=len;
    for(uint64_t i=0;i<len;i++){
        a[i]=0;
    }
    return a;
}

uint64_t ARR_FUNC(ARR_TYPE,len)(ARR_TYPE * a)
{
    return ((uint64_t *)a)[-1];
}

void ARR_FUNC(ARR_TYPE,del)(ARR_TYPE * a)
{
    uint64_t memlen;
    if(sizeof(ARR_TYPE)>sizeof(uint64_t)){
        memlen=1;
    }else{
        if(sizeof(uint64_t)%sizeof(ARR_TYPE)==0){
            memlen=sizeof(uint64_t)/sizeof(ARR_TYPE);
        }else{
            memlen=sizeof(uint64_t)/sizeof(ARR_TYPE)+1;
        }
    }
    free((void *)(a-memlen));
}

void ARR_FUNC(ARR_TYPE,copy)(ARR_TYPE ** a, ARR_TYPE * b)
{
    *a = ARR_FUNC(ARR_TYPE,init)(ARR_FUNC(ARR_TYPE,len)(b));
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(b);i++){
        (*a)[i]=b[i];
    }
}

ARR_TYPE ARR_FUNC(ARR_TYPE,max)(ARR_TYPE * a)
{
    ARR_TYPE max=a[0];
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(a);i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    return max;
}

ARR_TYPE ARR_FUNC(ARR_TYPE,min)(ARR_TYPE * a)
{
    ARR_TYPE min=a[0];
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(a);i++){
        if(min>a[i]){
            min=a[i];
        }
    }
    return min;
}

uint8_t ARR_FUNC(ARR_TYPE,isEqual)(ARR_TYPE * a, ARR_TYPE * b)
{
    if(ARR_FUNC(ARR_TYPE,len)(a)!=ARR_FUNC(ARR_TYPE,len)(b)){
        return 0;
    }
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(a);i++){
        if(a[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}

void ARR_FUNC(ARR_TYPE,swap)(ARR_TYPE * a, uint64_t i1, uint64_t i2)
{
    i1%=ARR_FUNC(ARR_TYPE,len)(a);
    i2%=ARR_FUNC(ARR_TYPE,len)(a);
    ARR_TYPE buff = a[i1];
    a[i1]=a[i2];
    a[i2]=buff;
}

void ARR_FUNC(ARR_TYPE,rearr)(ARR_TYPE * a, uint64_t i1, uint64_t i2)
{
    i1%=ARR_FUNC(ARR_TYPE,len)(a);
    i2%=ARR_FUNC(ARR_TYPE,len)(a);
    ARR_TYPE buff=a[i1];
    for(uint64_t i=i1;i>i2;i--){
        a[i]=a[i-1];
    }
    a[i2]=buff;
}

void ARR_FUNC(ARR_TYPE,erase)(ARR_TYPE ** a, uint64_t i1, uint64_t i2)
{
    i1%=ARR_FUNC(ARR_TYPE,len)(*a)+1;
    i2%=ARR_FUNC(ARR_TYPE,len)(*a)+1;
    ARR_TYPE * b=ARR_FUNC(ARR_TYPE,init)(ARR_FUNC(ARR_TYPE,len)(*a)-i2+i1);
    for(uint64_t i=0;i<i1;i++){
        b[i]=(*a)[i];
    }
    for(uint64_t i=i2;i<ARR_FUNC(ARR_TYPE,len)(*a);i++){
        b[i+i1-i2]=(*a)[i];
    }
    ARR_FUNC(ARR_TYPE,del)(*a);
    *a=b;
}

ARR_TYPE * ARR_FUNC(ARR_TYPE,substr)(ARR_TYPE * a, uint64_t i1, uint64_t i2)
{
    i1%=ARR_FUNC(ARR_TYPE,len)(a)+1;
    i2%=ARR_FUNC(ARR_TYPE,len)(a)+1;
    ARR_TYPE * b=ARR_FUNC(ARR_TYPE,init)(i2-i1);
    for(uint64_t i=0;i<i2-i1;i++){
        b[i]=a[i+i1];
    }
    return b;
}

uint64_t ARR_FUNC(ARR_TYPE,find)(ARR_TYPE * a, ARR_TYPE key, uint64_t entry)
{
    entry%=ARR_FUNC(ARR_TYPE,len)(a)+1;
    uint64_t i=-1;
    while(entry && i!=ARR_FUNC(ARR_TYPE,len)(a)){
        i++;
        if(a[i]==key){
            entry--;
        }
    }
    return (entry!=0?-1:i);
}

uint64_t ARR_FUNC(ARR_TYPE,findArr)(ARR_TYPE * a, ARR_TYPE * b, uint64_t entry)
{
    entry%=ARR_FUNC(ARR_TYPE,len)(a)+1;
    uint64_t i=-1;
    ARR_TYPE * c;
    while(entry && i!=(ARR_FUNC(ARR_TYPE,len)(a)-ARR_FUNC(ARR_TYPE,len)(b))){
        i++;
        c=ARR_FUNC(ARR_TYPE,substr)(a,i,i+ARR_FUNC(ARR_TYPE,len)(b));
        if(ARR_FUNC(ARR_TYPE,isEqual)(c,b)){
            entry--;
        }
        ARR_FUNC(ARR_TYPE,del)(c);
    }
    return (entry!=0?-1:i);
}

uint64_t ARR_FUNC(ARR_TYPE,count)(ARR_TYPE * a, ARR_TYPE n)
{
    uint64_t c=0;
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(a);i++){
        if(a[i]==n){
            c++;
        }
    }
    return c;
}

uint64_t ARR_FUNC(ARR_TYPE,countArr)(ARR_TYPE * a, ARR_TYPE * b)
{
    uint64_t c=0;
    ARR_TYPE * d;
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(a)-ARR_FUNC(ARR_TYPE,len)(b);i++){
        d=ARR_FUNC(ARR_TYPE,substr)(a,i,i+ARR_FUNC(ARR_TYPE,len)(b));
        if(ARR_FUNC(ARR_TYPE,isEqual)(d,b)){
            c++;
        }
        ARR_FUNC(ARR_TYPE,del)(d);
    }
    return c;
}

void ARR_FUNC(ARR_TYPE,pob)(ARR_TYPE ** a)
{
    if(ARR_FUNC(ARR_TYPE,len)(*a)!=0){
        ARR_TYPE * b=ARR_FUNC(ARR_TYPE,init)(ARR_FUNC(ARR_TYPE,len)(*a)-1);
        for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(*a)-1;i++){
            b[i]=(*a)[i];
        }
        ARR_FUNC(ARR_TYPE,del)(*a);
        *a=b;
    }
}

void ARR_FUNC(ARR_TYPE,pub)(ARR_TYPE ** a, ARR_TYPE n)
{
    ARR_TYPE * b=ARR_FUNC(ARR_TYPE,init)(ARR_FUNC(ARR_TYPE,len)(*a)+1);
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(*a);i++){
        b[i]=(*a)[i];
    }
    b[ARR_FUNC(ARR_TYPE,len)(b)-1]=n;
    *a=b;
}

void ARR_FUNC(ARR_TYPE,pof)(ARR_TYPE ** a)
{
    if(ARR_FUNC(ARR_TYPE,len)(*a)!=0){
        ARR_TYPE * b=ARR_FUNC(ARR_TYPE,init)(ARR_FUNC(ARR_TYPE,len)(*a)-1);
        for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(*a)-1;i++){
            b[i]=(*a)[i+1];
        }
        ARR_FUNC(ARR_TYPE,del)(*a);
        *a=b;
    }
}

void ARR_FUNC(ARR_TYPE,puf)(ARR_TYPE ** a, ARR_TYPE n)
{
    ARR_TYPE * b=ARR_FUNC(ARR_TYPE,init)(ARR_FUNC(ARR_TYPE,len)(*a)+1);
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(*a);i++){
        b[i+1]=(*a)[i];
    }
    b[0]=n;
    *a=b;
}

ARR_TYPE * ARR_FUNC(ARR_TYPE,concat)(ARR_TYPE * a, ARR_TYPE * b)
{
    ARR_TYPE * c=ARR_FUNC(ARR_TYPE,init)(ARR_FUNC(ARR_TYPE,len)(a)+ARR_FUNC(ARR_TYPE,len)(b));
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(a);i++){
        c[i]=a[i];
    }
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(b);i++){
        c[i+ARR_FUNC(ARR_TYPE,len)(a)]=b[i];
    }
    return c;
}

void ARR_FUNC(ARR_TYPE,ins)(ARR_TYPE ** a, ARR_TYPE n, uint64_t i)
{
    i%=ARR_FUNC(ARR_TYPE,len)(*a)+1;
    ARR_FUNC(ARR_TYPE,pub)(a,n);
    ARR_FUNC(ARR_TYPE,rearr)(*a,ARR_FUNC(ARR_TYPE,len)(*a)-1,i);
}

void ARR_FUNC(ARR_TYPE,insArr)(ARR_TYPE ** a, ARR_TYPE * b, uint64_t i)
{
    i%=ARR_FUNC(ARR_TYPE,len)(*a)+1;
    ARR_TYPE * c, * d, * e;
    c=ARR_FUNC(ARR_TYPE,substr)(*a,0,i);
    d=ARR_FUNC(ARR_TYPE,concat)(c,b);
    e=ARR_FUNC(ARR_TYPE,substr)(*a,i,ARR_FUNC(ARR_TYPE,len)(*a));
    *a=ARR_FUNC(ARR_TYPE,concat)(d,e);
    ARR_FUNC(ARR_TYPE,del)(c);
    ARR_FUNC(ARR_TYPE,del)(d);
    ARR_FUNC(ARR_TYPE,del)(e);
}

void ARR_FUNC(ARR_TYPE,repl)(ARR_TYPE ** a, ARR_TYPE n, uint64_t i1, uint64_t i2)
{
    i1%=ARR_FUNC(ARR_TYPE,len)(*a)+1;
    i2%=ARR_FUNC(ARR_TYPE,len)(*a)+1;
    ARR_FUNC(ARR_TYPE,erase)(a,i1,i2);
    ARR_FUNC(ARR_TYPE,ins)(a,n,i1);
}

void ARR_FUNC(ARR_TYPE,replArr)(ARR_TYPE ** a, ARR_TYPE * b, uint64_t i1, uint64_t i2)
{
    i1%=ARR_FUNC(ARR_TYPE,len)(*a)+1;
    i2%=ARR_FUNC(ARR_TYPE,len)(*a)+1;
    ARR_FUNC(ARR_TYPE,erase)(a,i1,i2);
    ARR_FUNC(ARR_TYPE,insArr)(a,b,i1);
}

void ARR_FUNC(ARR_TYPE,reverse)(ARR_TYPE * a)
{
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(a)/2;i++){
        ARR_FUNC(ARR_TYPE,swap)(a,i,ARR_FUNC(ARR_TYPE,len)(a)-1-i);
    }
}
//#endclude "array.c"

#undef ARR_FUNC
#undef ARR_TEMPLATE
#undef ARR_TYPE
//#endclude "../clib/src/array.h"
//#include "../clib/src/ptrarr.h"
#ifndef PTRARR_TYPE
#define PTRARR_TYPE int
#endif

#include <inttypes.h>
#define PTRARR_TEMPLATE(type, name) ptrarr_  ## name ## _ ## type
#define PTRARR_FUNC(...) PTRARR_TEMPLATE(__VA_ARGS__)

PTRARR_TYPE ** PTRARR_FUNC(PTRARR_TYPE, init)(uint64_t len);
uint64_t PTRARR_FUNC(PTRARR_TYPE, len)(PTRARR_TYPE ** a);
void PTRARR_FUNC(PTRARR_TYPE, del)(PTRARR_TYPE ** a);
void PTRARR_FUNC(PTRARR_TYPE, copy)(PTRARR_TYPE *** a, PTRARR_TYPE ** b);
uint8_t PTRARR_FUNC(PTRARR_TYPE, isEqual)(PTRARR_TYPE ** a, PTRARR_TYPE ** b);
void PTRARR_FUNC(PTRARR_TYPE, swap)(PTRARR_TYPE ** a, uint64_t i1, uint64_t i2);
void PTRARR_FUNC(PTRARR_TYPE, rearr)(PTRARR_TYPE ** a, uint64_t i1, uint64_t i2);
void PTRARR_FUNC(PTRARR_TYPE, erase)(PTRARR_TYPE *** a, uint64_t i1, uint64_t i2);
PTRARR_TYPE ** PTRARR_FUNC(PTRARR_TYPE, substr)(PTRARR_TYPE ** a, uint64_t i1, uint64_t i2);
void PTRARR_FUNC(PTRARR_TYPE, pob)(PTRARR_TYPE *** a);
void PTRARR_FUNC(PTRARR_TYPE, pub)(PTRARR_TYPE *** a, PTRARR_TYPE * n);
void PTRARR_FUNC(PTRARR_TYPE, pof)(PTRARR_TYPE *** a);
void PTRARR_FUNC(PTRARR_TYPE, puf)(PTRARR_TYPE *** a, PTRARR_TYPE * n);
PTRARR_TYPE ** PTRARR_FUNC(PTRARR_TYPE, concat)(PTRARR_TYPE ** a, PTRARR_TYPE ** b);
void PTRARR_FUNC(PTRARR_TYPE, ins)(PTRARR_TYPE *** a, PTRARR_TYPE * n, uint64_t i);
void PTRARR_FUNC(PTRARR_TYPE, insArr)(PTRARR_TYPE *** a, PTRARR_TYPE ** b, uint64_t i);
void PTRARR_FUNC(PTRARR_TYPE, repl)(PTRARR_TYPE *** a, PTRARR_TYPE * n, uint64_t i1, uint64_t i2);
void PTRARR_FUNC(PTRARR_TYPE, replArr)(PTRARR_TYPE *** a, PTRARR_TYPE ** b, uint64_t i1, uint64_t i2);
void PTRARR_FUNC(PTRARR_TYPE, reverse)(PTRARR_TYPE ** a);

//#include "ptrarr.c"
#include <stdlib.h>

PTRARR_TYPE ** PTRARR_FUNC(PTRARR_TYPE,init)(uint64_t len)
{
    uint64_t memlen;
    if(sizeof(PTRARR_TYPE *)>sizeof(uint64_t)){
        memlen=1;
    }else{
        if(sizeof(uint64_t)%sizeof(PTRARR_TYPE *)==0){
            memlen=sizeof(uint64_t)/sizeof(PTRARR_TYPE *);
        }else{
            memlen=sizeof(uint64_t)/sizeof(PTRARR_TYPE *)+1;
        }
    }
    PTRARR_TYPE ** a=(PTRARR_TYPE **)calloc(sizeof(PTRARR_TYPE *),len+memlen)+memlen;
    ((uint64_t *)a)[-1]=len;
    for(uint64_t i=0;i<len;i++){
        a[i]=0;
    }
    return a;
}

uint64_t PTRARR_FUNC(PTRARR_TYPE,len)(PTRARR_TYPE ** a)
{
    return ((uint64_t *)a)[-1];
}

void PTRARR_FUNC(PTRARR_TYPE,del)(PTRARR_TYPE ** a)
{
    uint64_t memlen;
    if(sizeof(PTRARR_TYPE *)>sizeof(uint64_t)){
        memlen=1;
    }else{
        if(sizeof(uint64_t)%sizeof(PTRARR_TYPE *)==0){
            memlen=sizeof(uint64_t)/sizeof(PTRARR_TYPE *);
        }else{
            memlen=sizeof(uint64_t)/sizeof(PTRARR_TYPE *)+1;
        }
    }
    free((void *)(a-memlen));
}

void PTRARR_FUNC(PTRARR_TYPE, copy)(PTRARR_TYPE *** a, PTRARR_TYPE ** b)
{
    *a = PTRARR_FUNC(PTRARR_TYPE, init)(PTRARR_FUNC(PTRARR_TYPE, len)(b));
    for(uint64_t i=0;i<PTRARR_FUNC(PTRARR_TYPE, len)(b);i++){
        (*a)[i]=b[i];
    }
}

uint8_t PTRARR_FUNC(PTRARR_TYPE,isEqual)(PTRARR_TYPE ** a, PTRARR_TYPE ** b)
{
    if(PTRARR_FUNC(PTRARR_TYPE,len)(a)!=PTRARR_FUNC(PTRARR_TYPE,len)(b)){
        return 0;
    }
    for(uint64_t i=0;i<PTRARR_FUNC(PTRARR_TYPE,len)(a);i++){
        if(a[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}

void PTRARR_FUNC(PTRARR_TYPE,swap)(PTRARR_TYPE ** a, uint64_t i1, uint64_t i2)
{
    i1%=PTRARR_FUNC(PTRARR_TYPE,len)(a);
    i2%=PTRARR_FUNC(PTRARR_TYPE,len)(a);
    PTRARR_TYPE * buff = a[i1];
    a[i1]=a[i2];
    a[i2]=buff;
}

void PTRARR_FUNC(PTRARR_TYPE,rearr)(PTRARR_TYPE ** a, uint64_t i1, uint64_t i2)
{
    i1%=PTRARR_FUNC(PTRARR_TYPE,len)(a);
    i2%=PTRARR_FUNC(PTRARR_TYPE,len)(a);
    PTRARR_TYPE * buff=a[i1];
    for(uint64_t i=i1;i>i2;i--){
        a[i]=a[i-1];
    }
    a[i2]=buff;
}

void PTRARR_FUNC(PTRARR_TYPE,erase)(PTRARR_TYPE *** a, uint64_t i1, uint64_t i2)
{
    i1%=PTRARR_FUNC(PTRARR_TYPE,len)(*a)+1;
    i2%=PTRARR_FUNC(PTRARR_TYPE,len)(*a)+1;
    PTRARR_TYPE ** b=PTRARR_FUNC(PTRARR_TYPE,init)(PTRARR_FUNC(PTRARR_TYPE,len)(*a)-i2+i1);
    for(uint64_t i=0;i<i1;i++){
        b[i]=(*a)[i];
    }
    for(uint64_t i=i2;i<PTRARR_FUNC(PTRARR_TYPE,len)(*a);i++){
        b[i+i1-i2]=(*a)[i];
    }
    PTRARR_FUNC(PTRARR_TYPE,del)(*a);
    *a=b;
}

PTRARR_TYPE ** PTRARR_FUNC(PTRARR_TYPE,substr)(PTRARR_TYPE ** a, uint64_t i1, uint64_t i2)
{
    i1%=PTRARR_FUNC(PTRARR_TYPE,len)(a)+1;
    i2%=PTRARR_FUNC(PTRARR_TYPE,len)(a)+1;
    PTRARR_TYPE ** b=PTRARR_FUNC(PTRARR_TYPE,init)(i2-i1);
    for(uint64_t i=0;i<i2-i1;i++){
        b[i]=a[i+i1];
    }
    return b;
}

void PTRARR_FUNC(PTRARR_TYPE,pob)(PTRARR_TYPE *** a)
{
    if(PTRARR_FUNC(PTRARR_TYPE,len)(*a)!=0){
        PTRARR_TYPE ** b=PTRARR_FUNC(PTRARR_TYPE,init)(PTRARR_FUNC(PTRARR_TYPE,len)(*a)-1);
        for(uint64_t i=0;i<PTRARR_FUNC(PTRARR_TYPE,len)(*a)-1;i++){
            b[i]=(*a)[i];
        }
        PTRARR_FUNC(PTRARR_TYPE,del)(*a);
        *a=b;
    }
}

void PTRARR_FUNC(PTRARR_TYPE,pub)(PTRARR_TYPE *** a, PTRARR_TYPE * n)
{
    PTRARR_TYPE ** b=PTRARR_FUNC(PTRARR_TYPE,init)(PTRARR_FUNC(PTRARR_TYPE,len)(*a)+1);
    for(uint64_t i=0;i<PTRARR_FUNC(PTRARR_TYPE,len)(*a);i++){
        b[i]=(*a)[i];
    }
    b[PTRARR_FUNC(PTRARR_TYPE,len)(b)-1]=n;
    *a=b;
}

void PTRARR_FUNC(PTRARR_TYPE,pof)(PTRARR_TYPE *** a)
{
    if(PTRARR_FUNC(PTRARR_TYPE,len)(*a)!=0){
        PTRARR_TYPE ** b=PTRARR_FUNC(PTRARR_TYPE,init)(PTRARR_FUNC(PTRARR_TYPE,len)(*a)-1);
        for(uint64_t i=0;i<PTRARR_FUNC(PTRARR_TYPE,len)(*a)-1;i++){
            b[i]=(*a)[i+1];
        }
        PTRARR_FUNC(PTRARR_TYPE,del)(*a);
        *a=b;
    }
}

void PTRARR_FUNC(PTRARR_TYPE,puf)(PTRARR_TYPE *** a, PTRARR_TYPE * n)
{
    PTRARR_TYPE ** b=PTRARR_FUNC(PTRARR_TYPE,init)(PTRARR_FUNC(PTRARR_TYPE,len)(*a)+1);
    for(uint64_t i=0;i<PTRARR_FUNC(PTRARR_TYPE,len)(*a);i++){
        b[i+1]=(*a)[i];
    }
    b[0]=n;
    *a=b;
}

PTRARR_TYPE ** PTRARR_FUNC(PTRARR_TYPE,concat)(PTRARR_TYPE ** a, PTRARR_TYPE ** b)
{
    PTRARR_TYPE ** c=PTRARR_FUNC(PTRARR_TYPE,init)(PTRARR_FUNC(PTRARR_TYPE,len)(a)+PTRARR_FUNC(PTRARR_TYPE,len)(b));
    for(uint64_t i=0;i<PTRARR_FUNC(PTRARR_TYPE,len)(a);i++){
        c[i]=a[i];
    }
    for(uint64_t i=0;i<PTRARR_FUNC(PTRARR_TYPE,len)(b);i++){
        c[i+PTRARR_FUNC(PTRARR_TYPE,len)(a)]=b[i];
    }
    return c;
}

void PTRARR_FUNC(PTRARR_TYPE,ins)(PTRARR_TYPE *** a, PTRARR_TYPE * n, uint64_t i)
{
    i%=PTRARR_FUNC(PTRARR_TYPE,len)(*a)+1;
    PTRARR_FUNC(PTRARR_TYPE,pub)(a,n);
    PTRARR_FUNC(PTRARR_TYPE,rearr)(*a,PTRARR_FUNC(PTRARR_TYPE,len)(*a)-1,i);
}

void PTRARR_FUNC(PTRARR_TYPE,insArr)(PTRARR_TYPE *** a, PTRARR_TYPE ** b, uint64_t i)
{
    i%=PTRARR_FUNC(PTRARR_TYPE,len)(*a)+1;
    PTRARR_TYPE ** c, ** d, ** e;
    c=PTRARR_FUNC(PTRARR_TYPE,substr)(*a,0,i);
    d=PTRARR_FUNC(PTRARR_TYPE,concat)(c,b);
    e=PTRARR_FUNC(PTRARR_TYPE,substr)(*a,i,PTRARR_FUNC(PTRARR_TYPE,len)(*a));
    *a=PTRARR_FUNC(PTRARR_TYPE,concat)(d,e);
    PTRARR_FUNC(PTRARR_TYPE,del)(c);
    PTRARR_FUNC(PTRARR_TYPE,del)(d);
    PTRARR_FUNC(PTRARR_TYPE,del)(e);
}

void PTRARR_FUNC(PTRARR_TYPE,repl)(PTRARR_TYPE *** a, PTRARR_TYPE * n, uint64_t i1, uint64_t i2)
{
    i1%=PTRARR_FUNC(PTRARR_TYPE,len)(*a)+1;
    i2%=PTRARR_FUNC(PTRARR_TYPE,len)(*a)+1;
    PTRARR_FUNC(PTRARR_TYPE,erase)(a,i1,i2);
    PTRARR_FUNC(PTRARR_TYPE,ins)(a,n,i1);
}

void PTRARR_FUNC(PTRARR_TYPE,replArr)(PTRARR_TYPE *** a, PTRARR_TYPE ** b, uint64_t i1, uint64_t i2)
{
    i1%=PTRARR_FUNC(PTRARR_TYPE,len)(*a)+1;
    i2%=PTRARR_FUNC(PTRARR_TYPE,len)(*a)+1;
    PTRARR_FUNC(PTRARR_TYPE,erase)(a,i1,i2);
    PTRARR_FUNC(PTRARR_TYPE,insArr)(a,b,i1);
}

void PTRARR_FUNC(PTRARR_TYPE,reverse)(PTRARR_TYPE ** a)
{
    for(uint64_t i=0;i<PTRARR_FUNC(PTRARR_TYPE,len)(a)/2;i++){
        PTRARR_FUNC(PTRARR_TYPE,swap)(a,i,PTRARR_FUNC(PTRARR_TYPE,len)(a)-1-i);
    }
}
//#endclude "ptrarr.c"

#undef PTRARR_FUNC
#undef PTRARR_TEMPLATE
#undef PTRARR_TYPE
//#endclude "../clib/src/ptrarr.h"

/********************************* CODE START *********************************/
#define DEBUG 1
#define INPUT_TYPE 2 //0 - io, 1 - rand, 2 - file
#define MTRX_NULL_PRINT -8
#define MTRX_NULL_TRANSPOSE -7
#define MTRX_NULL_SUM -1
#define MTRX_NULL_MUT -2
#define MTRX_NULL_POW -3
#define MTRX_SIZE_SUM -4
#define MTRX_SIZE_MUT -5
#define MTRX_SIZE_POW -6

int8_t catch_exept(int8_t flag);
int get_rand(int l, int r);
int ** get_rand_mtrx(int m, int n, int l, int r);
int ** get_file_mtrx(char * path);
int ** get_io_mtrx();
int8_t mtrx_print_int(int ** a);
int8_t mtrx_transpose_int(int *** mtrx, int ** a);
int8_t mtrx_sum_int(int *** mtrx, int ** a, int ** b);
int8_t mtrx_mut_int(int *** mtrx, int ** a, int ** b);
int8_t mtrx_pow_int(int *** mtrx, int ** a);
void mtrx_free(int ** a);

int main()
{
    srand(time(NULL));
    int ** mtrx_a, ** mtrx_b;
    #if INPUT_TYPE == 1
    mtrx_a = get_rand_mtrx(3,4,1,10);
    #endif
    #if INPUT_TYPE == 2
    mtrx_a = get_file_mtrx("test_11hw2_1.txt");
    #endif
    #if INPUT_TYPE == 0
    mtrx_a = get_io_mtrx();
    #endif

    #if INPUT_TYPE == 1
    mtrx_b = get_rand_mtrx(4,3,1,10);
    #endif
    #if INPUT_TYPE == 2
    mtrx_b = get_file_mtrx("test_11hw2_2.txt");
    #endif
    #if INPUT_TYPE == 0
    mtrx_b = get_io_mtrx();
    #endif

    int ** mtrx_a_tpd;
    if(catch_exept(mtrx_transpose_int(&mtrx_a_tpd,mtrx_a)))return 1;
    int ** mtrx_buff1;
    #if DEBUG == 1
    mtrx_print_int(mtrx_a_tpd);
    printf("\n");
    #endif
    if(catch_exept(mtrx_mut_int(&mtrx_buff1,mtrx_a,mtrx_b)))return 1;
    mtrx_free(mtrx_b);
    int ** mtrx_buff2;
    #if DEBUG == 1
    mtrx_print_int(mtrx_buff1);
    printf("\n");
    #endif
    if(catch_exept(mtrx_pow_int(&mtrx_buff2,mtrx_buff1)))return 1;
    mtrx_free(mtrx_buff1);
    #if DEBUG == 1
    mtrx_print_int(mtrx_buff2);
    printf("\n");
    #endif
    if(catch_exept(mtrx_mut_int(&mtrx_buff1,mtrx_a,mtrx_a_tpd)))return 1;
    mtrx_free(mtrx_a_tpd);
    mtrx_free(mtrx_a);
    #if DEBUG == 1
    mtrx_print_int(mtrx_buff1);
    printf("\n");
    #endif
    if(catch_exept(mtrx_sum_int(&mtrx_a_tpd,mtrx_buff1,mtrx_buff2)))return 1;
    mtrx_free(mtrx_buff1);
    mtrx_free(mtrx_buff2);

    mtrx_print_int(mtrx_a_tpd);
    mtrx_free(mtrx_a_tpd);
}

/**************************** IMPLEMENTATIONS START ***************************/

int8_t catch_exept(int8_t flag)
{
    switch (flag){
        case MTRX_NULL_PRINT: printf("!null_print\n");return 1;
        case MTRX_NULL_TRANSPOSE: printf("!null_transpose\n");return 1;
        case MTRX_NULL_SUM: printf("!null_sum\n");return 1;
        case MTRX_NULL_MUT: printf("!null_mut\n");return 1;
        case MTRX_NULL_POW: printf("!null_pow\n");return 1;
        case MTRX_SIZE_SUM: printf("!1\n");return 1;
        case MTRX_SIZE_MUT: printf("!2\n");return 1;
        case MTRX_SIZE_POW: printf("!3\n");return 1;
        default:break;
    }
    return 0;
}

int get_rand(int l, int r)
{
    return rand()%(r-l)+l;
}

int ** get_rand_mtrx(int m, int n, int l, int r)
{
    int ** res = ptrarr_init_int(n);
    for(int i=0;i<n;i++){
        res[i]=arr_init_int(m);
        for(int j=0;j<m;j++){
            res[i][j]=get_rand(l,r);
        }
    }
    return res;
}

int ** get_file_mtrx(char * path)
{
    FILE * file = fopen(path,"r");
    char * buffStr = str_init(0);
    int n[2];
    int buff;
    for(int j=0;j<2;j++){
        buff = fgetc(file);
        while(buff!=EOF && !isspace(buff)){
            str_pub(&buffStr,buff);
            buff = fgetc(file);
        }
        n[j]=numsys_ston(buffStr,10);
        str_erase(&buffStr,0,str_len(buffStr));
    }
    int ** res = ptrarr_init_int(n[0]);
    for(int i=0;i<n[0];i++){
        res[i]=arr_init_int(n[1]);
        for(int j=0;j<n[1];j++){
            buff = fgetc(file);
            while(buff!=EOF && !isspace(buff)){
                str_pub(&buffStr,buff);
                buff = fgetc(file);
            }
            res[i][j]=numsys_ston(buffStr,10);
            str_erase(&buffStr,0,str_len(buffStr));
        }
    }
    str_del(buffStr);
    fclose(file);
    return res;
}

int ** get_io_mtrx()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int ** res = ptrarr_init_int(n);
    for(int i=0;i<n;i++){
        res[i]=arr_init_int(m);
        for(int j=0;j<m;j++){
            scanf("%d",res[i]+j);
        }
    }
    return res;
}

int8_t mtrx_print_int(int ** a)
{
    if(a==NULL)return MTRX_NULL_PRINT;
    for(int i=0;i<ptrarr_len_int(a);i++){
        for(int j=0;j<arr_len_int(a[0]);j++){
            printf(j==arr_len_int(a[0])-1?"%6d\n":"%6d",a[i][j]);
        }
    }
    return 0;
}

int8_t mtrx_transpose_int(int *** mtrx, int ** a)
{
    if(a==NULL)return MTRX_NULL_TRANSPOSE;

    (*mtrx) = ptrarr_init_int(arr_len_int(a[0]));

    for(int j=0;j<arr_len_int(a[0]);j++){
        (*mtrx)[j] = arr_init_int(ptrarr_len_int(a));
        for(int i=0;i<ptrarr_len_int(a);i++){
            (*mtrx)[j][i]=a[i][j];
        }
    }
    return 0;
}

int8_t mtrx_sum_int(int *** mtrx, int ** a, int ** b)
{
    if(a==NULL || b==NULL)return MTRX_NULL_SUM;
    if(ptrarr_len_int(a)!=ptrarr_len_int(b) 
    || arr_len_int(a[0])!=arr_len_int(b[0]))return MTRX_SIZE_SUM;

    (*mtrx) = ptrarr_init_int(ptrarr_len_int(a));

    for(int i=0;i<ptrarr_len_int(a);i++){
        (*mtrx)[i] = arr_init_int(arr_len_int(a[0]));
        for(int j=0;j<arr_len_int(a[0]);j++){
            (*mtrx)[i][j]=a[i][j]+b[i][j];
        }
    }
    return 0;
}

int8_t mtrx_mut_int(int *** mtrx, int ** a, int ** b)
{
    if(a==NULL || b==NULL)return MTRX_NULL_MUT;
    if(arr_len_int(a[0])!=ptrarr_len_int(b))return MTRX_SIZE_MUT;

    (*mtrx) = ptrarr_init_int(ptrarr_len_int(a));
    for(int i=0;i<ptrarr_len_int(a);i++){
        (*mtrx)[i] = arr_init_int(arr_len_int(b[0]));
        for(int j=0;j<arr_len_int(b[0]);j++){
            for(int k=0;k<arr_len_int(a[0]);k++){
                (*mtrx)[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return 0;
}

int8_t mtrx_pow_int(int *** mtrx, int ** a)
{
    if(a == NULL)return MTRX_NULL_POW;
    if(ptrarr_len_int(a)!=arr_len_int(a[0]))return MTRX_SIZE_POW;
    mtrx_mut_int(mtrx,a,a);
    return 0;
}

void mtrx_free(int ** a)
{
    for(int i=0;i<ptrarr_len_int(a);i++){
        arr_del_int(a[i]);
    }
    ptrarr_del_int(a);
}

/********************************* PROGRAM END ********************************/