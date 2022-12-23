#include "std_lib_facilities.h"

int main()
{
   ifstream inFile;
   int temp=0, sum=0;
   inFile.open("../../data/findHiddenNumbers.txt");
   if(inFile.fail()){cout<<"Cannot find the file"; return 0;}
   else{cout<<"File successfully opened \n";}
   while(!inFile.eof()){
       inFile>>temp;
       if(inFile.fail())
       {inFile.clear();inFile.ignore(1, '\n');}
       sum = sum + temp;
   }
   inFile.close();
   cout<<"The sum of all hidden numbers is: "<< sum;
   return 0;
}
