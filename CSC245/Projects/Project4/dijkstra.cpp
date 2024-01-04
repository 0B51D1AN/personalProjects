//#include "graph.h"
#include <iostream>
#include <fstream>
#include "Node.h"
#include <string>
#include <vector>
#include <stdlib.h> 
#include <cstring>
//#include "dGraph.cpp"

using namespace std;
///////////////////////////////////////////
// FUNCTIONS
//void printGraph(Graph<string> &Map());
void sortFile(char* input);
string next(ifstream & file);
void generateGraph();
bool contains(string ans);
void dijkstra(string Vertex);
//////////////////////////////////////////

//////////////////////////////////////////
// VARIABLES
// Holds all vertices with linked nodes
vector<Node> Vertices;

/////////////////////////////////////////

/***********************************************************************************************************/
int main(int argc, char *argv[])
{

  
   // char ans[30];


    system("clear");
//      READ FILE
    if(argv[1]!=NULL)
    {
        
        string s= argv[1];
        if(s.substr(s.size()-4, 4)!=".dat")
            cout<<"Incorrect filetype entered, please try again with a '.dat' file: \n";
        else
        {    
           sortFile(argv[1]); 

            cout<<"             Graph has been built for these "<<Vertices.size()<<" Cities:\n";
            for(int i=0; i<Vertices.size(); i++) 
                {
                    
                    cout<< Vertices[i].getName()<<"     ";
                    //cout<<"\n";

                }  
                cout<<"\n\nPlease enter a starting City: \n";            
                generateGraph();

        }
    }
    else
        cout<< "No '.dat' file was input, please try again: \n";


}

/***********************************************************************************************************/


//FUNCTIONS


void sortFile(char*input)
{

    //Declare new nodes with corresponding vertices and weights  
    //place data into node struct which holds
        // - Node   - Linked Nodes  - Distance to linked nodes
    ifstream File(input);
    string temp;
    int num;
    bool found=false;

while(File)
{
        found=false;
        temp= next(File);
        //cout<<"TEMP: "<<temp<<endl;
       
            for(int i=0; i<Vertices.size(); i++)
            {   

                //If Node already initialized, push city into Links with distance
                if(Vertices[i].getName().compare(temp)==0)
                {
                    //cout<<"ITEM FOUND IN VERTICES: "<<temp<<endl;
                    temp=next(File);
                    num= atoi(next(File).c_str());
                   // cout<<"NODE PUSHED: "<<temp<<"  "<<num<<endl;
                    Vertices[i].pushLocation(temp, num);
                    //Vertices[i].printLinks();
                    found=true;
                    break;
                }
                
            }
            if(found==false)
            {              
                Vertices.push_back(Node(temp));
                temp=next(File);
                num= atoi(next(File).c_str());
                //cout<<temp<<"  "<<num<<endl;
                Vertices.back().pushLocation(temp, num);
                //c.out<<Vertices.back().getName()<<endl;
            }    
}         

}

string next(ifstream & file)
{       
    string data;
    char c;        
        
            while(c!=';' && c!='\n' && file) 
            {    
                   
                    file.get(c);
                
                    if(c!=';' && c!='\n')
                        data.push_back(c);
            }
       // cout<<data;
        return data;

}


void generateGraph()
{
    char ans[30];
    string temp;    

        cin.getline(ans,30);
        temp=ans;
        if(contains(temp))
        {
            cout<<"Item Found\nGenerating Graph...\n";//build graph
            dijkstra(temp);
        }
        else   
        {
            cout<<"Vertex not found, please try again:\n";
            generateGraph();
        }
        
}


bool contains(string ans)
{
    for(int i=0; i<Vertices.size(); i++)
            {
                if(ans.compare(Vertices[i].getName())==0)
                {
                    return true;
                }

            }

    return false;
}


void dijkstra(string Vertex)
{
    
    string temp=Vertex;
    dGraph Map(Vertices);           

    Map.start(Vertex);

    for(int i=0; i<Vertices.size()-1; i++)
        temp=Map.nextNode(temp);


    Map.printGraph();



}
