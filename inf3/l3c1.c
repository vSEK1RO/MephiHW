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

int main(){

    double buff=34641014.000529;
    double buffKohen=34641014.011676;
    double f,fcor,cor=0.0,scor=0.0;
    for(long long int i=2e7;i<=2e8;i++){
        if(i%(int)2e7==0 && i!=0){
            printf("%9d",i);
            printf("%18.4lf%18.4lf%10.4lf\n",buff,buffKohen,buff-buffKohen);
        }
        buff+=sqrt((2+3*pow(i+1,2))/(4+pow(i+1,2)));
        f=sqrt((2+3*pow(i+1,2))/(4+pow(i+1,2)));
        fcor=f-cor;
        scor=buffKohen+fcor;
        cor=(scor-buffKohen)-fcor;
        buffKohen=scor;
    }
}