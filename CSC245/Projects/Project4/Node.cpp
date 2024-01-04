//#include <string>
#include "Node.h"
#include <iostream>
using namespace std;



Node::Node()
{
//cout<<"Default Constructor";
Location="";
Distance=0;

}
Node::Node(string Loc)
{
    Location= Loc;
    Distance=0;    
}
Node:: Node( string Loc, int d)
{
    Location= Loc;
    Distance=d;
}

bool Node:: isEmpty() const
{
    return Links.empty();
}

bool Node:: isLinked(const Node & x) const
{
    if (!Links.empty())
    {
        for(int i=0; i<Links.size(); i++)
            {
                if((Links[i].Location).compare(x.Location))
                    return true;
            }
        return false;
    }
    return false;

}

void Node:: pushLocation(string x, int dist)
{

    
    //n.Distance=dist;

    Links.push_back(Node(x,dist));

}

void Node:: printLinks()
{

    for(int i=0; i<Links.size(); i++)
        {
            cout<< Links[i].Location<< "   "<< Links[i].Distance<<endl;
        }

}

Node Node::findMin()
{

    int minIndex=-1;

    if(!Links.empty())
    {
        for(int i=0; i<Links.size(); i++)
        {
            if(Links[i].getWeight()>minIndex)
                minIndex=i;
        }
        return Links[minIndex];
    }
    
    cout<<"Vertex has no linked Nodes";
    

}







