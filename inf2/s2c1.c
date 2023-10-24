//                          _      _       __   _        _       
//  _ __ ___    ___  _ __  | |__  (_)     / /  (_)  ___ (_) ___  
// | '_ ` _ \  / _ \| '_ \ | '_ \ | |    / /   | | / __|| |/ __| 
// | | | | | ||  __/| |_) || | | || |   / /    | || (__ | |\__ \ 
// |_| |_| |_| \___|| .__/ |_| |_||_|  /_/     |_| \___||_||___/ 
//                  |_|                                          
//
//              Created by Vlad Litvinov Б23-534
//

typedef struct{
    long long len;
    int ptr[100];
}Array;
#include <stdio.h>
Array getDividers(int num){
    Array array;
    array.len=0;
    for(int i=2;i<num/2+1;i++){
        if(num%i==0){
            array.len++;
            array.ptr[array.len-1]=i;
        }
    }
    for(int i=1;i<=4;i++){
        array.ptr[array.len-1+i]=-1;
    }
    return array;
}
int main(){
    Array a;
    int flag=0,max=0,maxNum;
    for(int i=190;i<=220;i++){
        a=getDividers(i);
        if(a.len>=max){
            max=a.len;
            maxNum=i;
        }
        printf("%-5d",i);
        flag=0;
        if(a.len!=0){
            for(int j=0;j<(a.len-1)/4+1;j++){
                for(int k=0;k<4;k++){
                    if(a.ptr[j*4+k]!=-1 && a.ptr[j*4+k+1]!=-1){
                        printf("%3d,",a.ptr[j*4+k]);
                    }else if(a.ptr[j*4+k]!=-1 && a.ptr[j*4+k+1]==-1){
                        printf("%3d",a.ptr[j*4+k]);
                        flag=1;
                    }else{
                        printf("    ");
                    }
                }
                if(flag){
                    printf("%6d\n",a.len);
                }else{
                    printf("\n     ");
                }
            }
        }else{
            printf("%21d\n",a.len);
        }
    }
    printf("\n%d\n",maxNum);
}