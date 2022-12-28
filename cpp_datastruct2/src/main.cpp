#include "std_lib_facilities.h"
#include "LinkedNode.h"
int main()
{
    LinkedNode<double> node1(10, nullptr, nullptr);
    LinkedNode<double> node2(12, &node1, nullptr);
    LinkedNode<double> node3(14, &node2, nullptr);
    LinkedNode<double> node4(16, &node3, nullptr);
    LinkedNode<double> node5(18, &node4, nullptr);

    //printing the same element using get value and prev pointer from next node
    cout<<node2.getValue()<<endl;
    cout<< node3.getPrev()->getValue() <<endl;
    return 0;
}
