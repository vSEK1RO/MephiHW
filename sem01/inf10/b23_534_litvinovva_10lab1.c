/************************** Thu Nov 16 10:31:57 2023 **************************/
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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/********************************* CODE START *********************************/

int get_rand(int left, int right);
int * get_rand_data();
int * get_io_data();
void arr_print_int(int * arr);
void sort_quick_int_cnt(int * a, int left, int right, int * cntAssign, int * cntCompar);

int main()
{   
    srand(time(NULL));
    int * arr;
    //arr=get_rand_data();
    arr=get_io_data();
    arr_print_int(arr);
    int cntAssign=0, cntCompar=0;
    sort_quick_int_cnt(arr,0,arr_len_int(arr)-1,&cntAssign,&cntCompar);
    arr_del_int(arr);
    printf("%d %d\n",cntAssign,cntCompar);
}

/**************************** IMPLEMENTATIONS START ***************************/

int get_rand(int l, int r)
{
    return rand()%(r-l)+l;
}

int * get_rand_data()
{
    int n = 5;//get_rand(10,20);
    int * a = arr_init_int(n);
    for(int i=0;i<n;i++){
        a[i]=get_rand(0,100);
    }
    return a;
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

void sort_quick_int_cnt(int * a, int left, int right, int * cntAssign, int * cntCompar)
{
    int pivot=a[(left+right)/2],l=left,r=right;
    while(l<=r){
        while(a[l]<pivot){
            *cntCompar+=1;
            l++;
        }
        while(a[r]>pivot){
            *cntCompar+=1;
            r--;
        }
        *cntCompar+=2;
        if(l<=r){
            arr_swap_int(a,l,r);
            if(l!=r){
                arr_print_int(a);
               
            }
            *cntAssign+=3;
            l++;
            r--;
        }
    }
    *cntAssign+=1;
    if(left<r){
        sort_quick_int_cnt(a,left,r,cntAssign,cntCompar);
    }
    if(l<right){
        sort_quick_int_cnt(a,l,right,cntAssign,cntCompar);
    }
}

/********************************* PROGRAM END ********************************/