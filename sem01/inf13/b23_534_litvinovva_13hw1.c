/************************** Sat Dec 16 22:38:36 2023 **************************/
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
/*                        Work with list implementation                       */
/*                                                                            */
/******************************* INCLUDES START *******************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 42 7 23 19 5 80 74 6 n
// 19
// 38
/********************************* CODE START *********************************/

typedef struct List{
    int data;
    struct List * next;
} List;

void list_print(List ** a);
void list_push_back(List ** a, int n);
void list_pop_back(List ** a);
void list_push_front(List ** a, int n);
void list_pop_front(List ** a);
List * list_find_addr(List ** a, int n);
void list_insert_after(List ** a, List * n, int q);

int main(){
    List * l = (List *)malloc(sizeof(List));
    l->next=NULL;
    char buff[256];
    while(strcmp(buff,"n")!=0){
        scanf("%s",buff);
        if(strcmp(buff,"n")!=0){
            list_push_front(&l,atoi(buff));
        }
    }
    int a,b;
    scanf("%d %d",&a,&b);
    list_insert_after(&l,list_find_addr(&l,a),b);
    list_print(&l);
}

/**************************** IMPLEMENTATIONS START ***************************/

void list_print(List ** a)
{
    List * b = *a;
    while(b->next!=NULL){
        printf("%4d",b->data);
        b=b->next;
    }
    printf("\n");
}

void list_push_back(List ** a, int n)
{
    List * b = *a;
    while(b->next!=NULL){
        b=b->next;
    }
    b->next = (List *)malloc(sizeof(List));
    b->next->data = n;
    b->next->next = NULL;
}

void list_pop_back(List ** a)
{
    List * b = *a, * c;
    while(b->next!=NULL){
        b=b->next;
        if(b->next==NULL){
            break;
        }
        c=b;
    }
    free(b);
    c->next==NULL;
}

void list_push_front(List ** a, int n)
{
    List * b = (List *)malloc(sizeof(List));
    b->next = *a;
    b->data = n;
    *a = b;
}

void list_pop_front(List ** a)
{
    List * b = *a;
    *a = b->next;
    free(b);
}

List * list_find_addr(List ** a, int n)
{
    List * b = *a;
    while(b->data!=n && b->next!=NULL){
        b=b->next;
    }
    return b;
}

void list_insert_after(List ** a, List * n, int q)
{
    if(n->next!=NULL){
        List * c = (List *)malloc(sizeof(List));
        c->next=n->next;
        c->data=q;
        n->next=c;
    }
}

/********************************* PROGRAM END ********************************/