/************************** Thu Nov 23 11:02:23 2023 **************************/
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
/******************************* INCLUDES START *******************************/

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
#include <stdio.h>

/********************************* CODE START *********************************/

void sort_ptrarr_quick_int(int ** a, int left, int right);
int * get_io_data();
void arr_print_int(int * a);
void ptrarr_print_int(int ** a);

int main()
{
    int * a = get_io_data();
    int * b = get_io_data();
    int ** sorted_ab = ptrarr_init_int(0);
    for(int i=0;i<arr_len_int(a);i++){
        ptrarr_pub_int(&sorted_ab, a+i);
    }
    for(int i=0;i<arr_len_int(b);i++){
        ptrarr_pub_int(&sorted_ab, b+i);
    }
    sort_ptrarr_quick_int(sorted_ab,0,ptrarr_len_int(sorted_ab)-1);
    arr_print_int(a);
    arr_print_int(b);
    ptrarr_reverse_int(sorted_ab);
    ptrarr_print_int(sorted_ab);
    arr_del_int(a);
    arr_del_int(b);
    ptrarr_del_int(sorted_ab);
}

/**************************** IMPLEMENTATIONS START ***************************/

void sort_ptrarr_quick_int(int ** a, int left, int right)
{
    int pivot=*a[(left+right)/2],l=left,r=right;
    while(l<=r){
        while(*a[l]<pivot){
            l++;
        }
        while(*a[r]>pivot){
            r--;
        }
        if(l<=r){
            ptrarr_swap_int(a,l,r);
            l++;
            r--;
        }
    }
    if(left<r){
        sort_ptrarr_quick_int(a,left,r);
    }
    if(l<right){
        sort_ptrarr_quick_int(a,l,right);
    }
}

int * get_io_data()
{
    int n;
    scanf("%d",&n);
    int * a = arr_init_int(n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    return a;
}

void arr_print_int(int * a)
{
    for(int i=0;i<arr_len_int(a);i++){
        printf("%3d",i+1);
    }
    printf("\n");
    for(int i=0;i<arr_len_int(a);i++){
        printf("%3d",a[i]);
    }
    printf("\n\n");
}

void ptrarr_print_int(int ** a)
{
    for(int i=0;i<ptrarr_len_int(a);i++){
        printf("%3d",i+1);
    }
    printf("\n");
    for(int i=0;i<ptrarr_len_int(a);i++){
        printf("%3d",*a[i]);
    }
    printf("\n\n");
}

/********************************* PROGRAM END ********************************/