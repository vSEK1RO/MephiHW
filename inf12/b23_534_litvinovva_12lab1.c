/************************** Thu Dec 07 10:19:49 2023 **************************/
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
/*                     Create a company employee structure                    */
/*         Implement a search for the employee with the lowest salary         */
/*                   Outputting employee data to the console                  */
/*                                                                            */
/******************************* INCLUDES START *******************************/

#include <inttypes.h>
typedef struct {
    uint64_t id;
    char fullName[32];
    char name[32];
    int depart;
    int salary;
    int bonus;
    int dues;
    int val;
} Employee;

#define PTRARR_TYPE Employee
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

// 5
// Petrov Ivan 2 1000 200 130
// Zakruzhnyy Pasha 1 9999 1110 0
// Mitin Vasya 2 1000 100 100
// Perlovskyy Vovchick 2 1000 50 50
// Utkin Petya 3 1000 100 100
/********************************* CODE START *********************************/

#define DEBUG 0
#define INPUT_TYPE 0 //0 - io, 1 - rand

int get_rand(int l, int r);
Employee ** get_rand_employee();
Employee ** get_io_employee();
Employee ** find_by_lowest_real_salary(Employee ** arr);
Employee ** find_unless_than_salary(Employee ** arr, Employee * emp);
void ptrarr_print_Employee(Employee ** arr);

int main()
{
    srand(time(NULL));
    Employee ** emps;
    #if INPUT_TYPE == 0
    emps = get_io_employee();
    #endif
    #if INPUT_TYPE == 1
    emps = get_rand_employee();
    #endif
    ptrarr_print_Employee(emps);
    Employee ** found_epms = find_by_lowest_real_salary(emps);
    if(ptrarr_len_Employee(found_epms)!=0){
        Employee ** found_sepms = find_unless_than_salary(emps,found_epms[0]);
        printf("\n");
        for(int i=0;i<ptrarr_len_Employee(found_epms);i++){
            printf("%s %s\n",found_epms[i]->fullName,found_epms[i]->name);
        }
        printf("\n");
        for(int i=0;i<ptrarr_len_Employee(found_sepms);i++){
            printf("%s %s\n",found_sepms[i]->fullName,found_sepms[i]->name);
        }
        ptrarr_del_Employee(found_sepms);
    }
    for(int i=0;i<ptrarr_len_Employee(emps);i++){
        free(emps[i]);
    }
    ptrarr_del_Employee(emps);
    ptrarr_del_Employee(found_epms);
}

/**************************** IMPLEMENTATIONS START ***************************/

int get_rand(int l, int r)
{
    return rand()%(r-l)+l;
}

Employee ** get_rand_employee()
{
    int n = get_rand(3,6);
    printf("%d\n",n);
    Employee ** emps = ptrarr_init_Employee(n);
    for(int i=0;i<n;i++){
        emps[i] = (Employee *)malloc(sizeof(Employee)); 
        emps[i]->fullName[0]=(char)get_rand(65,90);
        emps[i]->fullName[1]='\0';
        emps[i]->name[0]=(char)get_rand(65,90);
        emps[i]->name[1]='\0';
        emps[i]->depart=get_rand(1,3);
        emps[i]->salary=get_rand(1,11);
        emps[i]->bonus=get_rand(1,11);
        emps[i]->dues=get_rand(1,11);
        emps[i]->val=emps[i]->salary+emps[i]->bonus-emps[i]->dues;
        emps[i]->id=i;
    }
    return emps;
}

Employee ** get_io_employee()
{
    int n;
    scanf("%d",&n);
    Employee ** emps = ptrarr_init_Employee(n);
    for(int i=0;i<n;i++){
        emps[i] = (Employee *)malloc(sizeof(Employee)); 
        scanf("%s %s %d %d %d %d",
            emps[i]->fullName,emps[i]->name,
            &(emps[i]->depart),&(emps[i]->salary),
            &(emps[i]->bonus),&(emps[i]->dues)
        );
        emps[i]->val=emps[i]->salary+emps[i]->bonus-emps[i]->dues;
        emps[i]->id=i;
    }
    return emps;
}

Employee ** find_by_lowest_real_salary(Employee ** arr)
{
    int min = INT_MAX;
    for(int i=0;i<ptrarr_len_Employee(arr);i++){
        if(arr[i]->val<min && arr[i]->depart==1){
            min = arr[i]->val;
        }
    }
    Employee ** res = ptrarr_init_Employee(0);
    for(int i=0;i<ptrarr_len_Employee(arr);i++){
        if(arr[i]->val==min && arr[i]->depart==1){
            ptrarr_pub_Employee(&res,arr[i]);
        }
    }
    return res;
}

Employee ** find_unless_than_salary(Employee ** arr, Employee * emp)
{
    Employee ** res = ptrarr_init_Employee(0);
    for(int i=0;i<ptrarr_len_Employee(arr);i++){
        if(emp->val>=arr[i]->val && arr[i]->depart!=1){
            #if DEBUG == 1
            printf("%d\n",arr[i]->val);
            #endif
            ptrarr_pub_Employee(&res,arr[i]);
        }
    }
    return res;
}

void ptrarr_print_Employee(Employee ** arr)
{
    for(int i=0;i<ptrarr_len_Employee(arr);i++){
        printf("%-15s%-15s%5d%5d%5d%5d\n",
            arr[i]->fullName,arr[i]->name,
            arr[i]->depart,arr[i]->salary,
            arr[i]->bonus,arr[i]->dues
        );
    }
}

/********************************* PROGRAM END ********************************/