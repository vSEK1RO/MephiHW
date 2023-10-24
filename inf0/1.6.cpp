#include <stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(a%b==0){
        printf("%d",a/b);
    }
    if(b%a==0){
        printf("%d",b/a);
    }
    if(a%b!=0 && b%a!=0){
        printf("%d",a+b);
    }
}