
//#include "BinaryHeap.cpp"
#include "BinaryHeap.h"

#include <iostream>

using namespace std;




int main()
{

    BinaryHeap<char> PQ(10);
/*
    char a='A';

    for(int i=0; i<10; i++)
    {
        PQ.insert(a+i);

    }
    
   // PQ.print();    

  */  

    //PQ.deleteMin();
    
    PQ.insert('A');
    PQ.insert('B');
    PQ.insert('C');
    PQ.insert('D');
    PQ.insert('E');
    PQ.insert('F');
    PQ.insert('G');
    PQ.insert('H');
    PQ.insert('I');
    PQ.insert('J');

    cout<< "Left Subtree: ";
    PQ.printLtSubtree(2);
    cout<<"\n";

    cout<<"Height: "<<PQ.Height()<<endl;

    cout<<"Max Heap Value: "<<PQ.findMax()<<endl;

    PQ.PrintLeaves();

    return 0;
}

    
