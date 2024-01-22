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
#include <stdlib.h>

int solve(int a, int b, int c, int d, double * x, double * y){
    int i = (a+b)==0;
    int j = (c-a*d)==0;
    int n = c/(double)(a)-(double)(d)<1e-4;
    int m = c/(double)(b)-(double)(-d)<1e-4;
    if(i){
        if(j){
            if(n&&m){
                return 3;
            }else{
                return 2;
            }
        }else{
            return 1;
        }
    }else{
        *y=(c-a*d)/(double)(a+b);
        *x=d+*y;
        return 0;
    }
}

int main(){
    int a,b,c,d;
    double x,y;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int flag = solve(a,b,c,d,&x,&y);
    if(!flag){
        if(x<y){
            printf("%d\n%.6lf\n%.6lf\n",flag,x,y);
        }else{
            printf("%d\n%.6lf\n%.6lf\n",flag,y,x);
        }
    }else{
        printf("%d\n",flag);
    }
}