#include "std_lib_facilities.h"
void ElementWiseProduct(int a[4], int b[4], int c[4]){
    for(int i = 0; i < 4; i++)c[i] = a[i] * b[i];
}
int main() {
    int a[4], b[4], c[4];
    for (int i = 0; i < 4; i++) {
        a[i] = i + 1;
        b[i] = i + 1;
    }
    ElementWiseProduct(a,b,c);
    //print a
    cout<<"a=[";
    for(int i=0;i<4;i++)
    {
        cout<<a[i];if(i!=3)cout<<",";
    }
    cout<<"]\n";
    //print b
    cout<<"b=[";
    for(int i=0;i<4;i++)
    {
        cout<<b[i];if(i!=3)cout<<",";
    }
    cout<<"]\n";
    //print c
    cout<<"c=[";
    for(int i=0;i<4;i++)
    {
        cout<<c[i];if(i!=3)cout<<",";
    }
    cout<<"]";
    return 0;
}
