#include "std_lib_facilities.h"

double uniform(default_random_engine &engine, double lowerbound, double upperbound){
    uniform_real_distribution<double> uniform(lowerbound, upperbound);
    return uniform(engine);
}

int main()
{
    double X[8] = {0.0, 0.0, 0.0, 0.8, 1.0, 1.0, 1.0, 0.2};
    double Y[8] = {0.0, 0.8, 1.0, 1.0, 1.0, 0.2, 0.0, 0.0};
    random_device seed;
    default_random_engine engine(seed());
    double old_dist = 10, old_x=0, old_y=0;
    for(int i =0; i<1000000; i++){
        double x = uniform(engine, 0, 1);
        double y = uniform(engine, 0, 1);
        double dist = 0;
        for(int j=0; j<8;j++){dist = dist + sqrt(((X[j]-x)*(X[j]-x))+((Y[j]-y)*(Y[j]-y)));}
        if(dist < old_dist){old_dist = dist; old_x = x; old_y=y;}
    }
    cout<<"The optimal location is at (x,y)=("<<old_x<<","<<old_y<<")";
    return 0;
}
