#include "bst.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{


    BinarySearchTree<int> T (0);
    T.insert(6);
    T.insert(8);
    T.insert(2);
    T.insert(4);
    T.insert(1);
    T.insert(3);

    T.postOrder();

    cout<< T.Height()<<endl;

    cout<< T.numLeaves()<<endl;

    T.isBalanced();
    T.insert(9);
    T.isBalanced();



}