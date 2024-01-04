#include <queue>
#include <iostream>
#include <vector>
#include <functional>
#include <string>

using namespace std;


template<class Comparable>
void pushName(priority_queue<string> & stack, Comparable & name);

void printStack(priority_queue <string> & stack);

int main()
{

    priority_queue<string> pq; 

    //string names[] ={ "Jenny","Jared","Johnny","Jordan","Jimmy","Janet","John","Jerry","Jessica","June" };

    string name="";    

    for(int i=0; i<10; i++)
    {
        cout<<"Please enter a name: "; 
        cin>>name;
        pushName(pq, name);
        //cout<<pq.top();
    }

    printStack(pq);

    return 0;
}

template <class Comparable>
void pushName(priority_queue <string> &stack, Comparable & name)
{

    stack.push(name);
    //cout<<stack.top();

}

void printStack(priority_queue <string> &stack)
{

    
    cout<<"Printing..."<<endl;

    if(stack.empty())
        cout<<"empty";

    while(!stack.empty())
    {
        
        cout<<stack.top()<<endl;
        stack.pop();

    }

}