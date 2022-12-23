#include "std_lib_facilities.h"

int isExactPowerOfTwo(int num){
    int count = 0;
    while(num != 1){
        if((num % 2) != 0){cout<<"No, its not a power of 2."<<endl; break;}
        else{
            if(num == 2){cout<<"Yes, Its a exact power of 2."<<endl; break;}
            int new_num = num/2;
            num = new_num;
            count++;
        }
    }
    return count;
};

int main()
{
    int power;
    power = isExactPowerOfTwo(75);
    cout<<"The power is "<<power;
    return 0;
}
