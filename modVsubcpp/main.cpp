#include <iostream>
#include <chrono>

int main() {

    std::cout << "Is--even?"<< std::endl;

    //repeated subtraction
    int num = 10;
    auto start = std::chrono::high_resolution_clock::now();
    while(num > 2)num = num - 2;
    if(num==2)std::cout<<"Even!"<<std::endl;
    else std::cout<<"Not even!"<<std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(end - start);
    std::cout<< duration.count()<<std::endl;

    //modulus method
    int num1 = 10;
    auto start1 = std::chrono::high_resolution_clock::now();
    if(num1%2 == 0)std::cout<<"Even!"<<std::endl;
    else std::cout<<"Not even!"<<std::endl;
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = duration_cast<std::chrono::microseconds>(end1 - start1);
    std::cout<< duration1.count();
    return 0;


}
