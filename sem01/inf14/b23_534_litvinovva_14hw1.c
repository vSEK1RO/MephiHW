/************************** Sun Dec 17 09:59:02 2023 **************************/
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
/*                        Work with double linked list                        */
/*                                                                            */
/******************************* INCLUDES START *******************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// 42 7 23 19 5 80 74 6 n
// 19
// 38
/********************************* CODE START *********************************/

typedef struct DList{
    int data;
    struct DList * next;
    struct DList * prev;
} DList;

void dlist_print(DList ** begin);
void dlist_print_rev(DList ** end);
void dlist_push_back(DList ** begin, DList ** end, int n);
void dlist_pop_back(DList ** begin, DList ** end);
void dlist_push_front(DList ** begin, DList ** end, int n);
void dlist_pop_front(DList ** begin, DList ** end);
void dlist_del(DList ** begin, DList ** end);
void dlist_rand(DList ** begin, DList ** end, int n, int a, int b);
int dlist_sum(DList ** begin);
//functions for 14hw1:
DList * dlist_find(DList ** begin, DList ** end, int n);
void dlist_ins_after(DList ** begin, DList ** end, DList * q, int n);
void dlist_erase(DList ** begin, DList ** end, DList * q);

int main(){
    srand(time(NULL));
    DList * dlb = NULL;
    DList * dle = NULL;
    char buff[256]; 
    while(strcmp(buff,"n")!=0){
        scanf("%s",buff);
        if(strcmp(buff,"n")!=0){
            dlist_push_front(&dlb,&dle,atoi(buff));
        }
    }
    int a,b;
    scanf("%d %d",&a,&b);
    DList * lf = dlist_find(&dlb,&dle,a);
    if(lf->data==a){
        dlist_ins_after(&dlb,&dle,lf,b);
        dlist_print(&dlb);
        dlist_erase(&dlb,&dle,lf);
        dlist_print(&dlb);
    }else{
        dlist_print(&dlb);
        dlist_print(&dlb);
    }
}

/**************************** IMPLEMENTATIONS START ***************************/

void dlist_print(DList ** begin)
{
    DList * b = *begin;
    if(b!=NULL){
        while(b->next!=NULL){
            printf("%4d",b->data);
            b=b->next;
        }
        printf("%4d",b->data);
    }
    printf("\n");
}

void dlist_print_rev(DList ** end)
{
    DList * b = *end;
    if(b!=NULL){
        while(b->prev!=NULL){
            printf("%4d",b->data);
            b=b->prev;
        }
        printf("%4d",b->data);
    }
    printf("\n");
}

void dlist_push_back(DList ** begin, DList ** end, int n)
{
    DList * b = (DList *)malloc(sizeof(DList));
    if(*end!=NULL){
        (*end)->next=b;
    }
    b->next=NULL;
    b->prev=*end;
    b->data=n;
    *end=b;
    if(*begin==NULL){
        *begin=b;
    }
    if((*end)->prev==*begin){
        (*begin)->next=*end;
    }
}

void dlist_pop_back(DList ** begin, DList ** end)
{
    DList * b = *end;
    *end=b->prev;
    (*end)->next=NULL;
    free(b);
}

void dlist_push_front(DList ** begin, DList ** end, int n)
{
    DList * b = (DList *)malloc(sizeof(DList));
    if(*begin!=NULL){
        (*begin)->prev=b;
    }
    b->next=*begin;
    b->prev=NULL;
    b->data=n;
    *begin=b;
    if(*end==NULL){
        *end=b;
    }
    if((*begin)->next==*end){
        (*end)->prev=*begin;
    }
}

void dlist_pop_front(DList ** begin, DList ** end)
{
    DList * b = *begin;
    if(*begin == *end){
        *begin=NULL;
        *end=NULL;
    }else{
        *begin=b->next;
        (*begin)->prev=NULL;
    }
    free(b);
}

void dlist_del(DList ** begin, DList ** end)
{
    while((*begin)->next!=NULL){
        dlist_pop_front(begin,end);
    }
}

void dlist_rand(DList ** begin, DList ** end, int n, int a, int b){
    for(int i=0;i<n;i++){
        dlist_push_front(begin,end,rand()%(b-a)+a);
    }
    for(int i=0;i<n;i++){
        dlist_push_back(begin,end,rand()%(b-a)+a);
    }
}

int dlist_sum(DList ** begin)
{
    int sum=0;
    DList * b = *begin;
    if(b!=NULL){
        while(b->next!=NULL){
            sum+=b->data;
            b=b->next;
        }
        sum+=b->data;
    }
    return sum;
}

DList * dlist_find(DList ** begin, DList ** end, int n)
{
    DList * b = *begin;
    while(b->data!=n){
        b=b->next;
    }
    return b;
}

void dlist_ins_after(DList ** begin, DList ** end, DList * q, int n)
{
    DList * b = *begin;
    while(b!=q){
        b=b->next;
    }
    DList * c = b->next;
    b->next = (DList *)malloc(sizeof(DList));
    if(c!=NULL){
        c->prev = b->next;
        b->next->next=c;
    }else{
        b->next->next=NULL;
    }
    b->next->prev=b;
    b->next->data=n;
}

void dlist_erase(DList ** begin, DList ** end, DList * q)
{
    DList * b = *begin;
    while(b!=q){
        b=b->next;
    }
    if(b->next==NULL || b->prev==NULL){
        if(b->next==NULL && b->prev!=NULL){
            b->prev->next=NULL;
            *end = b->prev;
            free(b);
        }
        if(b->next!=NULL && b->prev==NULL){
            b->next->prev=NULL;
            *begin = b->next;
            free(b);
        }
        if(b->next==NULL && b->prev==NULL){
            b->prev->next=NULL;
            *end = NULL;
            *begin = NULL;
            free(b);
        }
    }else{
        b->next->prev=b->prev;
        b->prev->next=b->next;
    }
}

/********************************* PROGRAM END ********************************/