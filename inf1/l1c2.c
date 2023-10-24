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
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(b>a && a>c || c>a && a>b){
        printf("%d\n",a);
    }
    if(a>b && b>c || c>b && b>a){
        printf("%d\n",b);
    }
    if(a>c && c>b || b>c && c>a){
        printf("%d\n",c);
    }
    if(a==b && a!=c){
        if(c>a){
            printf("%d=%d<%d\n",a,b,c);
        }else{
            printf("%d=%d>%d\n",a,b,c);
        }
    }
    if(a==c && c!=b){
        if(b>c){
            printf("%d=%d<%d\n",a,c,b);
        }else{
            printf("%d=%d>%d\n",a,c,b);
        }
    }
    if(b==c && a!=b){
        if(a>b){
            printf("%d=%d<%d\n",b,c,a);
        }else{
            printf("%d=%d>%d\n",b,c,a);
        }
    }
    if(a==b && a==c){
        printf("%d=%d=%d\n",a,b,c);
    }
}