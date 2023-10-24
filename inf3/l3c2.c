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

double func(double n){
    return 2*pow(n,3)-9*pow(n,2)-60*n+1;
}

int main(){
    double left=-2.0, right=2.0, middle=0, eps=1e-8;    
    while(right-left>1e-8){
        middle=((left+right)/2.0);
        if(func(middle)*func(left)>0){
            left=middle;
        }else{
            right=middle;
        }
    }
    printf("%.8lf\n",middle);
}