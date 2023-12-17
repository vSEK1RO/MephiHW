/************************** Thu Dec 14 10:57:10 2023 **************************/
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
/*                      Work with stack implementation                        */
/*                                                                            */
/******************************* INCLUDES START *******************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 42 7 23 19 5 80 74 6 n
/********************************* CODE START *********************************/

typedef struct Stack{
    int data;
    struct Stack * prev;
} Stack;

void stack_print(Stack ** a);
void stack_push_back(Stack ** a, int n);
void stack_pop_back(Stack ** a);
int stack_sum(Stack ** a);

int main(){
    Stack * top = (Stack *)malloc(sizeof(Stack));
    top->prev=NULL;
    char buff[256];
    while(strcmp(buff,"n")!=0){
        scanf("%s",buff);
        if(strcmp(buff,"n")!=0){
            stack_push_back(&top,atoi(buff));
        }
    }
    stack_pop_back(&top);
    stack_pop_back(&top);
    stack_print(&top);
    printf("%d\n",stack_sum(&top));
}

/**************************** IMPLEMENTATIONS START ***************************/

void stack_print(Stack ** a)
{
    Stack * b = *a;
    while(b->prev!=NULL){
        printf("%4d",b->data);
        b=b->prev;
    }
    printf("\n");
}

void stack_push_back(Stack ** a, int n)
{
    Stack * b = (Stack *)malloc(sizeof(Stack));
    b->prev = *a;
    b->data = n;
    *a=b;
}

void stack_pop_back(Stack ** a)
{
    Stack * b = *a;
    *a=b->prev;
    free(b);
}

int stack_sum(Stack ** a)
{
    int sum=0;
    Stack * b = *a;
    while(b->prev!=NULL){
        sum+=b->data;
        b=b->prev;
    }
    return sum;
}

/********************************* PROGRAM END ********************************/