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
    int x,y;
    scanf("%d %d",&x,&y);
    int upperBox=0,lowerTriangle=0,intoCircle=0;
    if(pow(x,2)+pow(y,2)<=pow(300,2)){
        intoCircle=1;
    }   
    if(x>=-150 && x<=150 && y>=150 ||
       x<=-150 && y>=0 ||
       x>=150 && y>=0){
        upperBox=1; 
    }
    if(y<=x && y<=-x && y<=-150){
        lowerTriangle=1;
    }
    if(upperBox&&intoCircle || lowerTriangle&&intoCircle){
        printf("inside\n");
    }else{
        printf("outside\n");
    }
}