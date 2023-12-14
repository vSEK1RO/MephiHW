/************************** Wed Dec 13 23:54:52 2023 **************************/
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
/************************************ TASK ************************************/
/*                                                                            */
/*              The task of finding the average score of students             */
/*                                                                            */
/******************************* INCLUDES START *******************************/

#include <inttypes.h>
typedef struct {
    uint64_t id;
    char fullName[32];
    char name[32];
    char city[32];
    char street[32];
    int house;
    int room;
    char section[32];
    int score;
} Student;
#define PTRARR_TYPE Student
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
#define PTRARR_TYPE char
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
//#include "../clib/src/string.h"
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
//#endclude "../clib/src/string.h"
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
typedef struct {
    char * name;
    int val; 
} City;
#define PTRARR_TYPE City
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
#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>

// 4
// Frolov Sergei Samara Sadovaya 34 87 Physics 92
// Popov Aleksandr Moscow Tverskaya 25 9 Biology 89
// Smirnov Nikolay Kazan Pushkina 19 38 History 95
// Bogdanov Ivan Moscow Pokrovka 12 46 Physics 94
/********************************* CODE START *********************************/

#define DEBUG 0
#define INPUT_TYPE 0 //0 - io, 1 - rand

int get_rand(int l, int r);
Student ** get_rand_student();
Student ** get_io_student();

int main()
{
    srand(time(NULL));
    Student ** stds;
    #if INPUT_TYPE == 0
    stds = get_io_student();
    #endif
    #if INPUT_TYPE == 1
    stds = get_rand_student());
    #endif
    int flags, flagc;
    char ** sections = ptrarr_init_char(0);
    char ** cities = ptrarr_init_char(0);
    City ** citiesVal = ptrarr_init_City(0);
    int * scoreByCity = arr_init_int(0);
    int * scoreBySection = arr_init_int(0);
    int * count = arr_init_int(0);
    int * avgScore = arr_init_int(0);
    for(int i=0;i<ptrarr_len_Student(stds);i++){
        flags = -1;
        flagc = -1;
        for(int j=0;j<ptrarr_len_char(sections);j++){
            if(str_isEqual(sections[j],stds[i]->section)){
                flags = j;
            }
        }
        for(int j=0;j<ptrarr_len_char(cities);j++){
            if(str_isEqual(cities[j],stds[i]->city)){
                flagc = j;
            }
        }
        if(flagc==-1){
            ptrarr_pub_char(&cities,stds[i]->city);
            arr_pub_int(&scoreByCity, stds[i]->score);
            City * buffer = (City *)malloc(sizeof(City));
            buffer->name = stds[i]->city;
            buffer->val = 0;
            ptrarr_pub_City(&citiesVal, buffer);
        }else{
            if(stds[i]->score>scoreByCity[flagc]){
                scoreByCity[flagc]=stds[i]->score;
            }
        }
        if(flags==-1){
            ptrarr_pub_char(&sections,stds[i]->section);
            arr_pub_int(&count, 1);
            arr_pub_int(&avgScore, stds[i]->score);
            arr_pub_int(&scoreBySection, stds[i]->score);
        }else{
            count[flags]++;
            avgScore[flags]+=stds[i]->score;
            if(stds[i]->score>scoreBySection[flags]){
                scoreBySection[flags]=stds[i]->score;
            }
        }
    }
    for(int i=0;i<arr_len_int(avgScore);i++){
        printf("%s %.1lf\n",sections[i],avgScore[i]/(double)count[i]);
    }
    for(int i=0;i<ptrarr_len_Student(stds);i++){
        flags = -1;
        for(int j=0;j<ptrarr_len_char(sections);j++){
            if(str_isEqual(sections[j],stds[i]->section)){
                flags = j;
            }
        }
        flagc = -1;
        for(int j=0;j<ptrarr_len_char(sections);j++){
            if(str_isEqual(sections[j],stds[i]->section)){
                flagc = j;
            }
        }
        if((double)(stds[i]->score)>avgScore[flags]/(double)count[flags]){
            citiesVal[flagc]->val++;
        }
    }
    for(int i=0;i<ptrarr_len_City(citiesVal);i++){
        for(int j=i;j<ptrarr_len_City(citiesVal)-1;j++){
            if(citiesVal[j]->val<citiesVal[j+1]->val){
                ptrarr_swap_City(citiesVal,j,j+1);
            }
        }
    }
    printf("\n");
    for(int i=0;i<ptrarr_len_char(sections);i++){
        printf("%s ",sections[i]);
        int cnt = 0;
        for(int j=0;j<ptrarr_len_Student(stds);j++){
            if(stds[j]->score==scoreBySection[i]){
                cnt++;
            }
        }
        for(int j=0;j<ptrarr_len_Student(stds);j++){
            if(stds[j]->score==scoreBySection[i]){
                cnt--;
                printf(cnt==0?"%s\n":"%s ",stds[j]->fullName);
            }
        }
    }
    printf("\n");
    for(int i=0;i<ptrarr_len_char(cities);i++){
        printf("%s ",cities[i]);
        int cnt = 0;
        for(int j=0;j<ptrarr_len_Student(stds);j++){
            if(stds[j]->score==scoreByCity[i]){
                cnt++;
            }
        }
        for(int j=0;j<ptrarr_len_Student(stds);j++){
            if(stds[j]->score==scoreByCity[i]){
                cnt--;
                printf(cnt==0?"%s\n":"%s ",stds[j]->fullName);
            }
        }
    }
    printf("\n");
    for(int i=0;i<ptrarr_len_City(citiesVal);i++){
        printf(i==ptrarr_len_City(citiesVal)-1?"%s\n":"%s ",citiesVal[i]->name);
    }
}

/**************************** IMPLEMENTATIONS START ***************************/

int get_rand(int l, int r)
{
    return rand()%(r-l)+l;
}

Student ** get_rand_student()
{
    int n = get_rand(3,6);
    printf("%d\n",n);
    Student ** emps = ptrarr_init_Student(n);
    for(int i=0;i<n;i++){
        emps[i] = (Student *)malloc(sizeof(Student)); 
        emps[i]->fullName[0]=(char)get_rand(65,90);
        emps[i]->fullName[1]='\0';
        emps[i]->name[0]=(char)get_rand(65,90);
        emps[i]->name[1]='\0';
        emps[i]->city[0]=(char)get_rand(65,90);
        emps[i]->city[1]='\0';
        emps[i]->street[0]=(char)get_rand(65,90);
        emps[i]->street[1]='\0';
        emps[i]->house=get_rand(1,3);
        emps[i]->room=get_rand(1,11);
        emps[i]->section[0]=(char)get_rand(65,70);
        emps[i]->section[1]='\0';
        emps[i]->score=get_rand(50,101);
        emps[i]->id=i;
    }
    return emps;
}

Student ** get_io_student()
{
    int n;
    scanf("%d",&n);
    Student ** emps = ptrarr_init_Student(n);
    for(int i=0;i<n;i++){
        emps[i] = (Student *)malloc(sizeof(Student)); 
        scanf("%s %s %s %s %d %d %s %d",
            emps[i]->fullName,emps[i]->name,
            emps[i]->city,emps[i]->street,
            &(emps[i]->house),&(emps[i]->room),
            emps[i]->section,&(emps[i]->score)
        );
        emps[i]->id=i;
    }
    return emps;
}

/********************************* PROGRAM END ********************************/