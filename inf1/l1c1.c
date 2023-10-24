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
long long pow(long long a, int p){
    long long res=1;
    for(int i=0;i<p;i++){
        res*=a;
    }
    return res;
}
long long getNumLen(long long a){
    long long len=0;
    while(a!=0){
        a/=10;
        len+=1;
    }
    return len;
}
int main(){
    int a,mult=1;
    scanf("%d",&a);
    a*=a;
    for(int i=0;i<getNumLen(a);i++){
        mult*=(a/pow(10,i))%10;
    }
    printf("%d\n",a/mult);
}