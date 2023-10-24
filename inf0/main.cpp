#include <stdio.h>
using namespace std;
void f1(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",a/b);
}
void f2(){
    float a,b;
    scanf("%f %f",&a,&b);
    printf("%.3f",a/b);
}
void f3(){
    float a=123.45, b=9.876, c=45.6;
    printf("alpha\t=\t%.2f\nbeta\t=\t%.3f\ngamma\t=\t%.1f\n",a,b,c);
}
void f4(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(a>b){
        printf("%d",a);
    }
    if(a<b){
        printf("%d",b);
    }
}
void f5(){
    int a;
    scanf("%d",&a);
    if(a%2==0 and a>0){
        printf("%d - Четное и положительное",a);
    }
}
void f6(){
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
int main(){
    int key;
    while(true){
        printf("select prj\n");
        scanf("%d",&key);
        if(key==1)f1();
        if(key==2)f2();
        if(key==3)f3();
        if(key==4)f4();
        if(key==5)f5();
        if(key==6)f6();
        if(key==0)break;
    }
}
