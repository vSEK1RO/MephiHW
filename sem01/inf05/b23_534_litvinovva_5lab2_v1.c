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
#include <limits.h>
#include <stdlib.h>
#include <inttypes.h>

void throwException(int code){
    switch (code){
    case 1: printf("endless\n"); exit(1);
    case 2: printf("overflow\n"); exit(2);
    default: break;
    }
}

//unsigned long int c=0;

unsigned long int recFunc(unsigned long int n, unsigned long int m){
    //c++;
    if(n==2 || m==2)throwException(1);
    if(n!=1 && m!=1 && n>UINT32_MAX/m)throwException(2);
    if((n==1 || m==1) && n>UINT32_MAX-m)throwException(2);
    //printf("%u\t%u\t%u\n",c,n,m);
    if((n*m)%2==1){
        if(n+m>n*m){
            return n+m;
        }else{
            return n*m;
        }
    }else{
        unsigned long int f1=recFunc((n*m)/2,m);
        unsigned long int f2=recFunc((n*m)/2,n);
        if(f1>UINT32_MAX-f2){
            throwException(2);
            return 0;
        }else{
            return f1+f2;
        }
    }
}

int main(){
    unsigned long int n,m;
    scanf("%u\n%u",&n,&m);
    printf("%u\n",recFunc(n,m));
}