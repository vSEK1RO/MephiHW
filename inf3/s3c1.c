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
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    double buffKohen=0.0,f,fcor,cor=0.0,scor=0.0;
    for(int i=1;i<=n;i++){
        f=1.0/(i*(i+3.0));
        fcor=f-cor;
        scor=buffKohen+fcor;
        cor=(scor-buffKohen)-fcor;
        buffKohen=scor;
    }
    printf("%.8lf\n%.8lf\n%.8lf\n",11/18.0,buffKohen,11/18.0-buffKohen>0?11/18.0-buffKohen:11/buffKohen-18.0);
}
