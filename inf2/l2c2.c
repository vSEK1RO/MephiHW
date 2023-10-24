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
    long int pellNum_1=1,pellNum_2=2,buff;
    int n,i;
    scanf("%d",&n);
    printf("%3d  %d\n%3d  %d\n",1,1,2,2);
    for(i=3;i<=n;i++){
        buff=pellNum_2;
        pellNum_2 = pellNum_2*2 + pellNum_1;
        pellNum_1=buff;
        printf("%3d  %d\n",i,pellNum_2);
    }
    printf("\n");
    while(pellNum_2>0){
        buff=pellNum_2;
        pellNum_2 = pellNum_2*2 + pellNum_1;
        pellNum_1=buff;
        i++;
    }
    printf("%3d  %d\n%3d  %d\n%3d  %d\n",i-4,pellNum_1-(pellNum_2-pellNum_1*2)*2,i-3,pellNum_2-pellNum_1*2,i-2,pellNum_1);
}