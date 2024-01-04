#include "Node.h"
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

dGraph::dGraph(vector<Node> Graph)
{

    for(int i=0; i<Graph.size(); i++)
    {
        Nodes.push_back(Graph[i].getName());
        //cout<< Nodes[i]<<endl;
    }
    //vector<Node> r(Graph);
    vector<int> w(Graph.size(), INT_MAX);
    vector <bool> m(Graph.size(), false);
    vector <string> pN(Graph.size(),"UNKNOWN");
    
    Root=Graph;
    Weights=w;
    Marks=m;
    prevNodes=pN;
    
    size=Graph.size();


}

void dGraph::printGraph()
{

    cout<<"\nVertices             Distance            Previous\n\n";
    for(int i=0; i<size; i++)
    {
        cout<<Nodes[i]<<"           "<<Weights[i]<<"            "<<prevNodes[i]<<endl;
    }

    //cout<<Root[0].getName();

}


void dGraph:: start(string start)
{
    bool found=false;
    int i=0;
    string temp;
    Node tempNode(" ", 0);


     for(int i=0; i<size; i++)
     {   
        //cout<<i;
        if(Nodes[i].compare(start)==0)
        {
               //cout<<Nodes[i];
               temp=Nodes[i];
               

               //MIGHT NEED THIS
                tempNode=Root[i];
                Root.erase(Root.begin()+i);
                Root.insert(Root.begin(), tempNode);
                //Root[i]=Root[0];
                //Root[0]=tempNode;
                Nodes[i]=Nodes[0];
                Nodes[0]=temp;
                //found=true;
                Weights[0]=0;  
                prevNodes[0]="  N/A";      

        }
     }  

}


void dGraph:: Mark(int index)
{
    Marks[index]=true;
}

bool dGraph:: isMarked(int index)
{
    return Marks[index];
}

string dGraph:: nextNode(string node)
{
    //input of beginning string for dijkstra
    //output of smallest link from given node that has not been visited
    int dist=0;
    int index=0;
    int start=0;
    
    //Find Node Index
    start=findIndex(node);

    dist+=Root[start].findMin().getWeight();
    //UPDATE TO NEW INDEX OF NEXT NODE
    index=findIndex(Root[start].findMin().getName());
    
    if(!isMarked(index))
    {
        //If Not Marked:   
        Mark(index);
        Weights[index]=dist;
        prevNodes[index]=node;
        return nextNode(Nodes[index]);     
    }
    else
     {   
        return Nodes[index];
        
     }

}

void findPaths(Node current)
{
    //Root node is beginning index
    //Root[0].findMin();

    int dist;

    // MOVE FINDMIN() INTO dGRAPH FOR BETTER IMPLEMENTATION
    /*
    if(!isMarked(findIndex(current.findMin().getName())))
        {
            cout<<"yes";
        }

    */

}


int dGraph:: findIndex(string vertex)
{
//Assume Root[0] is beginning
   for(int i=0; i<size; i++)
    {
        if(Nodes[i].compare(vertex)==0)
            return i;
    }
}