#include "std_lib_facilities.h"

/* Practice for implementing inner and outer product of two vector with same length N = 5.
 * The goal of the practice is to gain some familiarity to array Definition.
 * Only require to pass the single test case in the main function.
 *
 * Task:
 *      1. Write a function to calculate the inner product of two vectors, inputs are represented by two arrays.
 *      2. Write a function to calculate the outer product of two vectors, inputs are represented by the same two arrays.
 *      The definition of inner product: https://en.wikipedia.org/wiki/Dot_product
 *      The definition of outer product: https://en.wikipedia.org/wiki/Outer_product
 */

 double innerProduct(const double a[], const double b[], int N){
    double innerProductValue=0;
    for (int i = 0; i < N; i++)
        innerProductValue = innerProductValue + a[i] * b[i];
    return innerProductValue;
}

// input N is the length for both a and b vectors
 void outerProduct(const double a[], const double b[], const int N, double outerProductMatrix[5][5]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            outerProductMatrix[i][j] = a[i] * b[j];
        }
    }
 }

 // helper function to print out the outer product matrix
void printMatrix(double outerProductMatrix[5][5]){
     for (int row = 0; row < 5; row++){
         for (int col = 0; col < 5; col++){
             cout << outerProductMatrix[row][col] << " ";
         }
         cout << endl;
     }
 }

int main()
{
    /* single test case expected Output:
     inner product: 110
     outer product:
     2 4 6 8 10
     4 8 12 16 20
     6 12 18 24 30
     8 16 24 32 40
     10 20 30 40 50
     */

     // length of the array equals to 5 defined as constant integer
     const int N = 5;
     double a[N] = {1,2,3,4,5};
     double b[N] = {2,4,6,8,10};
     double innerProductResult;
     double outerProductResult[N][N] = {};
     // calculate the inner product
     innerProductResult = innerProduct(a, b, N);
     cout << "inner product: "<< innerProductResult << endl;
     // calculate the outer product
     outerProduct(a, b, N, outerProductResult);
     cout << "outer product: " << endl;
     printMatrix(outerProductResult);
     return 0;
}
