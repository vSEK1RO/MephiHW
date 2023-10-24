#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int x[3],y[3];
    for(int i=0;i<3;i++){
        cin>>x[i]>>y[i];
    }
    float S,a[3],p;
    a[0]=sqrt(pow(x[0]-x[1],2)+pow(y[0]-y[1],2));
    a[1]=sqrt(pow(x[1]-x[2],2)+pow(y[1]-y[2],2));
    a[2]=sqrt(pow(x[2]-x[0],2)+pow(y[2]-y[0],2));
    p=(a[0]+a[1]+a[2])/2;
    S=sqrt(p*(p-a[0])*(p-a[1])*(p-a[2]));
    cout<<"\nh lenght:\n";
    for(int i=0;i<3;i++){
        printf("%.2f\n",S/a[i]*2);
    }
    cout<<"\nsquare:\n"<<S;
}