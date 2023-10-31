//#include "../clib/src/title.h"
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
//#endclude "../clib/src/title.h"
#include <stdio.h>
#include <math.h>
#include <limits.h>

long int flag=0,exept=0;

long int dtot(long int num){
    flag=0;exept=0;
    long int res=0;
    int c=0;
    while(num){
        if(pow(10,c-1)>212222222 || res>21222222-num%3*pow(10,c) || res<-21222222-num%3*pow(10,c)){
            flag=1;
        }
        res+=num%3*pow(10,c);
        c++;
        num/=3;
    }
    return res;
}

long int ttod(long int num){
    flag=0;exept=0;
    long int res=0;
    int c=0;
    while(num){
        if(pow(3,c-1)>LONG_MAX || res>LONG_MAX-num%10*pow(3,c) || res<LONG_MIN-num%10*pow(3,c)){
            flag=1;
        }
        res+=num%10*pow(3,c);
        c++;
        num/=10;
    }
    return res;
}

long int tdsum(long int a, long int b){
    flag=0;exept=0;
    long int _a,_b,_res,res;
    _a = ttod(a);
    _b = ttod(b);
    _res=_a+_b;
    res = dtot(_res);
    if(flag){
        exept=1;
    }
    return res;
}

long int tdsub(long int a, long int b){
    flag=0;exept=0;
    long int _a,_b,_res,res;
    _a = ttod(a);
    _b = ttod(b);
    _res=_a-_b;
    res = dtot(_res);
    if(flag){
        exept=2;
    }
    return res;
}

long int tdmut(long int a, long int b){
    flag=0;exept=0;
    long int _a,_b,_res,res;
    _a = ttod(a);
    _b = ttod(b);
    _res=_a*_b;
    res = dtot(_res);
    if(flag){
        exept=3;
    }
    return res;
}

long int tdpow(long int a, long int b){
    flag=0;exept=0;
    long int _a,_b,_res,res;
    _a = ttod(a);
    _b = ttod(b);
    _res=pow(_a,_b);
    res = dtot(_res);
    if(flag){
        exept=4;
    }
    return res;
}

long int tddiv(long int a, long int b){
    flag=0;exept=0;
    long int _a,_b,_res,res;
    _a = ttod(a);
    _b = ttod(b);
    _res=_a/_b;
    res = dtot(_res);
    if(flag){
        exept=5;
    }
    return res;
}

long int tdmod(long int a, long int b){
    flag=0;exept=0;
    long int _a,_b,_res,res;
    _a = ttod(a);
    _b = ttod(b);
    _res=_a%_b;
    res = dtot(_res);
    if(flag){
        exept=6;
    }
    return res;
}

long int fun1(long int a, long int b){
    flag=0;exept=0;
    long int res,buff;
    res = tdpow(b,2);if(flag){return 0;}
    res = tdmut(a,res);if(flag){return 0;}
    buff = tdsub(b,a);if(flag){return 0;}
    buff = tdmut(a,buff);if(flag){return 0;}
    res = tdsub(res,buff);if(flag){return 0;}
    res = tdsum(res,b);if(flag){return 0;}
    return res;
}

long int fun2(long int a, long int b){
    flag=0;exept=0;
    long int res,buff;
    res = tdpow(a,10);if(flag){return 0;}
    res = tdsum(res,b);if(flag){return 0;}
    res = tddiv(res,b);if(flag){return 0;}
    return res;
}

long int fun3(long int a, long int b){
    flag=0;exept=0;
    long int res,buff;
    res = tdpow(b,10);if(flag){return 0;}
    res = tdsum(res,a);if(flag){return 0;}
    res = tddiv(res,a);if(flag){return 0;}
    return res;
}


int main(){
    long int a,b,res;
    scanf("%ld %ld",&a,&b);
    res=fun1(a,b);
    if(exept==0){
        printf("%ld\n",res);
    }else{
        printf("!%ld\n",exept);
    }
    res=fun2(a,b);
    if(exept==0){
        printf("%ld\n",res);
    }else{
        printf("!%ld\n",exept);
    }
    res=fun3(a,b);
    if(exept==0){
        printf("%ld\n",res);
    }else{
        printf("!%ld\n",exept);
    }
    
}