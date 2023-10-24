//#include "clib/src/title.h"
/*                          _      _       __   _        _       
//  _ __ ___    ___  _ __  | |__  (_)     / /  (_)  ___ (_) ___  
// | '_ ` _ \  / _ \| '_ \ | '_ \ | |    / /   | | / __|| |/ __| 
// | | | | | ||  __/| |_) || | | || |   / /    | || (__ | |\__ \ 
// |_| |_| |_| \___|| .__/ |_| |_||_|  /_/     |_| \___||_||___/ 
//                  |_|                                          
//
//              Created by Vlad Litvinov b23-534
//                 https://github.com/vSEK1RO
*/
//#endclude "clib/src/title.h"
#include <stdio.h>

void arrInit(int * arr, int len, int a, int b){
    for(int i=0;i<len;i++){
        arr[i]=a*i-b;
    }
}

void arrPrint(int * arr, int * begin, int * end){
    for(int * i=begin;i<end;i++){
        printf("%5d", i-arr+1);
    }
    printf("\n");
    for(int * i=begin;i<end;i++){
        printf("%5d", *i);
    }
    printf("\n");
}

void arrSwap(int * arr1, int l1, int * arr2, int k){
    int buff;
    for(int i=0;i<k;i++){
        buff=arr2[i];
        arr2[i]=arr1[l1-k+i];
        arr1[l1-k+i]=buff;
    }
}

int main(){
    int a1,b1,a2,b2,k;
    scanf("%d %d\n%d %d\n%d",&a1,&b1,&a2,&b2,&k);
    int m1[14], m2[12];
    arrInit(m1,14,a1,b1);
    arrInit(m2,12,a2,b2);
    arrPrint(m1,m1,m1+14);
    printf("\n"); 
    arrPrint(m2,m2,m2+12);
    printf("\n"); 
    arrSwap(m1,14,m2,k);
    arrSwap(m2,12,m1,k);
    arrSwap(m1,14,m1,k);
    arrPrint(m1,m1,m1+14);
    printf("\n"); 
    arrPrint(m2,m2,m2+12);
}