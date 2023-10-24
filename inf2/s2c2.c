//                          _      _       __   _        _       
//  _ __ ___    ___  _ __  | |__  (_)     / /  (_)  ___ (_) ___  
// | '_ ` _ \  / _ \| '_ \ | '_ \ | |    / /   | | / __|| |/ __| 
// | | | | | ||  __/| |_) || | | || |   / /    | || (__ | |\__ \ 
// |_| |_| |_| \___|| .__/ |_| |_||_|  /_/     |_| \___||_||___/ 
//                  |_|                                          
//
//              Created by Vlad Litvinov Б23-534
//

#include <stdio.h>
#include <math.h>
#include <limits.h>

int main(){
    int k,n=0;
    long int sum,buff,last=0;
    char flag;
    scanf("%d",&k);
    while(1){
        n++;
        sum=0;
        for(int i=1;i<=k;i++){
            buff=1;
            for(int j=0;j<n;j++){
                if(buff<LONG_MAX/(3*i-2)){
                    buff*=(3*i-2);
                }else{
                    flag='*';
                    goto skip;
                }
            }
            if(sum<LONG_MAX-buff){
                sum+=buff;
            }else{
                flag='+';
                goto skip;
            }
        }
        last=sum;
    }
    skip:printf("%d\n%d\n%c\n",last,n-1,flag);
}