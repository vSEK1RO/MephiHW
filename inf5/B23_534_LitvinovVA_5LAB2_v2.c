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
#define uli unsigned long int

int c=0;

int recFunc(uli n, uli m, uli * res){
    c++;
    if(n*m%2==1){
        if(n+m>n*m){
            if(n>UINT32_MAX-m || *res>UINT32_MAX-(n+m))return 2;
            *res += n+m;
            return 0;
        }else{
            if(n>UINT32_MAX/m || *res>UINT32_MAX-(n*m))return 2;
            *res += n*m;
            return 0;
        }
    }else{
        if(n/2>UINT32_MAX/m || n==0 || m==0)return 2;
        if(c>10)return 1;
        if(n*m/2==n || n*m/2==m)return 1;
        int f=recFunc(n,n*m/2,res);
        if(f)return f;
        f=recFunc(m,n*m/2,res);
        if(f)return f;
        return 0;
    }
}

void scan(){
    uli n,m,res=0;
    int flag;
    scanf("%lu\n%lu",&n,&m);
    flag = recFunc(n,m,&res);
    if(flag==0)printf("%lu\n",res);
    if(flag==1)printf("endless\n");
    if(flag==2)printf("overflow\n");
}

void test(){
    uli n,m,res=0;
    int flag;
    for(n=1;n<60;n++){
        for(m=1;m<60;m++){
        res=0;
        flag = recFunc(n,m,&res);
        if(flag==0)printf("%lu\t%lu\t%lu\n",n,m,res);
        if(flag==1)printf("%lu\t%lu\tendless\n",n,m);
        if(flag==2)printf("%lu\t%lu\toverflow\n",n,m);
        }
    }
}

int main(){
    scan();
    //test();
}