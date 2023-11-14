/************************** Mon Nov 13 22:15:46 2023 **************************/
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

#include "../clib/src/numsys.h"
#include "../clib/src/string.h"
#include "../clib/src/array.h"
#include "../clib/src/ptrarr.h"
#include <limits.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/********************************* CODE START *********************************/

int getRand(int, int);
void setRandFileData(const char *);
int ** getFileData(const char *);
int ** getIOData();
int * getDigitCount(int ** a);
void printHist(int * a);
int * getMaxArray(int ** a);

int main()
{
    srand(time(NULL));
    int ** inputData;
/****************************** RANDOM FILE DATA ******************************/
    // setRandFileData("test7hw1.txt");
    // inputData = getFileData("test7hw1.txt");

    // printf("Generated ptr array:\n");
    // for(int i=0;i<ptrarr_len_int(inputData);i++){
    //     printf("%4d",i+1);
    //     for(int j=0;j<arr_len_int(inputData[i]);j++){
    //         printf("%4d",inputData[i][j]);
    //     }
    //    printf("\n");
    // }
/******************************************************************************/
    inputData = getIOData();
    /*
23432 9 134520 958 134520 38
9832 107450 74635 4 2883
15 69291 89641 10 134520
85 124743 4 8217 61578 4 173
    */

    int * maxArray = getMaxArray(inputData);
    int marrlen = arr_len_int(maxArray);
    for(int i=0;i<marrlen;i++)printf(i!=marrlen-1?"%d ":"%d\n",maxArray[i]+1);

    int * digitCount = getDigitCount(inputData);
    //for(int i=0;i<10;i++)printf("%d ",digitCount[i]);
    printf("\n");
    printHist(digitCount);

    for(int i=0;i<ptrarr_len_int(inputData);i++){
        arr_del_int(inputData[i]);
    }
    return 0;
}

/**************************** IMPLEMENTATIONS START ***************************/

int getRand(int l, int r)
{
    return rand()%(r-l)+l;
}

void setRandFileData(const char * path)
{
    FILE * file = fopen(path,"w");
    int a=getRand(1,30), b;
    char * str = str_init(0);
    char * buff;
    for(int i=0;i<a;i++){
        b=getRand(1,20);
        for(int j=0;j<b;j++){
            buff = numsys_ntos(getRand(1,1000),10);
            if(j!=b-1)str_pub(&buff,' ');
            str_insStr(&str,buff,str_len(str));
            //printf("|%s|%s|\n",buff,str);
            str_del(buff);
        }
        str_pub(&str,'\n');
        fputs(str,file);
        str_erase(&str,0,str_len(str));
    }
    str_del(str);
    fclose(file);
}

int ** getFileData(const char * path)
{
    FILE * file;
    if((file = fopen(path,"r")) == NULL){
        printf("File didn't find");
    }
    int ** a = ptrarr_init_int(1);
    a[0]=arr_init_int(0);
    char * buffStr = str_init(0);
    int buff;
    while((buff=getc(file))!=EOF){
        if(!isspace(buff)){
            str_pub(&buffStr,buff);
        }
        if(isspace(buff) && buff!='\n'){
            arr_pub_int(a+ptrarr_len_int(a)-1,numsys_ston(buffStr,10));
            str_erase(&buffStr,0,str_len(buffStr));
        }
        if(isspace(buff) && buff=='\n'){
            arr_pub_int(a+ptrarr_len_int(a)-1,numsys_ston(buffStr,10));
            ptrarr_pub_int(&a, arr_init_int(0));
            str_erase(&buffStr,0,str_len(buffStr));
        }
    }
    ptrarr_pob_int(&a);
    str_del(buffStr);
    fclose(file);
    return a;
}

int ** getIOData()
{
    int ** a = ptrarr_init_int(1);
    a[0]=arr_init_int(0);
    char * buffStr = str_init(0);
    char buff, lastBuff='\n';
    while((buff=getchar())!=lastBuff || buff!='\n'){
        if(!isspace(buff)){
            str_pub(&buffStr,buff);
        }
        if(isspace(buff) && buff!='\n'){
            arr_pub_int(a+ptrarr_len_int(a)-1,numsys_ston(buffStr,10));
            str_erase(&buffStr,0,str_len(buffStr));
        }
        if(isspace(buff) && buff=='\n'){
            arr_pub_int(a+ptrarr_len_int(a)-1,numsys_ston(buffStr,10));
            ptrarr_pub_int(&a, arr_init_int(0));
            str_erase(&buffStr,0,str_len(buffStr));
        }
        lastBuff = buff;
    }
    ptrarr_pob_int(&a);
    str_del(buffStr);
    return a;
}

int * getDigitCount(int ** a)
{
    int * arr = arr_init_int(10);
    char * buff;
    for(int i=0;i<ptrarr_len_int(a);i++){
        for(int j=0;j<arr_len_int(a[i]);j++){
            buff = numsys_ntos(a[i][j],10);
            for(int k=0;k<10;k++){
                arr[k]+=str_count(buff,numsys_dtoc(k));
            }
            str_del(buff);
        }
    }
    return arr;
}

void printHist(int * a)
{
    for(int i=0;i<arr_len_int(a);i++){
        printf("%d ",i);
        for(int j=0;j<(a[i]%3==2?a[i]/3+1:a[i]/3);j++){
            printf("*");
        }
        printf(" %d\n",a[i]);
    }
}

int * getMaxArray(int ** a)
{
    int * arr = arr_init_int(0);
    int * maxArr = arr_init_int(0);
    int max;
    for(int i=0;i<ptrarr_len_int(a);i++){
        max=INT_MIN;
        for(int j=0;j<arr_len_int(a[i]);j++){
            if(a[i][j]>max)max=a[i][j];
        }
        arr_pub_int(&maxArr,max);
    }
    max=INT_MIN;
    for(int i=0;i<arr_len_int(maxArr);i++){
        if(maxArr[i]>max)max=maxArr[i];
    }
    for(int i=1;i<=arr_count_int(maxArr,max);i++){
        arr_pub_int(&arr,arr_find_int(maxArr,max,i));
    }
    arr_del_int(maxArr);
    return arr;
}

/********************************* PROGRAM END ********************************/