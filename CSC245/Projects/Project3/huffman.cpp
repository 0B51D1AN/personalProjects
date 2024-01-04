#include "huffman.h"
#include <iostream>
using namespace std;

HuffmanTree:: HuffmanTree()
	: numChars(0), built(false) { // Leave in stack format use 2i, 2i+1 to find child   i/2 for parent
    }

void HuffmanTree:: insert(char ch, int weight) { //formatted for character nodes, use different childType for T nodes
    HNode newNode = {ch, weight, -1, -1}; 
    built = false;
    nodes.push_back(newNode);
    numChars++;

}

bool HuffmanTree:: inTree(char ch) {

    if(lookUp(ch)!=-1)
        return true;

}

int HuffmanTree:: GetFrequency(char ch) {

    for(int i=1; i<nodes.size(); i++)
        {
            if(ch==nodes[i].ch)
                return nodes[i].weight;
        }
    return 0;

}

int HuffmanTree:: GetFrequency(int i) {

    return nodes[i].weight;
}

int HuffmanTree:: lookUp(char ch) {

    //possibly more efficient recursive method later?
    
    for(int i=1; i<nodes.size(); i++)
    {
        if(ch=nodes[i].ch)
            {
                return i;
            }
    }

}

string HuffmanTree:: GetCode(char ch) {

    return GetCode(lookUp(ch));

}


string HuffmanTree:: GetCode(int i) {

    
    if (nodes[i].parent == 0)
        return "";
    else
        return (GetCode(nodes[i].parent) + (char)(nodes[i].childType+'0'));


}

void HuffmanTree:: PrintTable() {

cout<<"\n Index   Char    Weight  Parent  ChildType\n";

for (int i=0; i<nodes.size(); i++)
{
    cout<<"     "<< i<<"     "<<nodes[i].ch<< "         "<< nodes[i].weight<< "       "<< nodes[i].parent<< "       "<< nodes[i].childType<<endl;
}

}

int HuffmanTree:: numNodes() {

return 2*nodes.size()-1;

}

void HuffmanTree:: build() {

        //find smallest values then add them
        //create new HNode T and add node to the back of the array       

vector<HNode>formatted;
HNode temp;


// Sort values greatest to smallest, use .back() to collect and add smallest values
// re-sort after reinserting 



    while(!built)
    {
        
        while(nodes[0].ch!='\0')
        {
            //Find 2 smallest values
            while(formatted.size()!=2)
            {
                //Find Smallest Character
                for(int i=0; i<nodes.size()-1; i++)
                {  
                    temp= nodes[0];
                    
                    if(nodes[i+1].weight<=temp.weight)
                        temp=nodes[i+1];
                }
                //Remove from nodes to find second smallest
                formatted.push_back(temp);
            }

            //Add their weight and create new TNode with added weight and insert back into array
            HNode tNode={'\0', (formatted[0].weight+formatted[1].weight), -1, 0};
            nodes.push_back(formatted[0]);
            nodes.push_back(formatted[1]);
            //nodes.insert(tNode, )
            formatted.clear();
        }

        built =true;
    }


}





