


using namespace std;
  
    #include <vector>
    #include <string>
    #include <climits>

    

    class Node
    {
        public:
            Node();
            Node(string Loc);
            Node(string Loc, int d);
            
            bool isEmpty() const;
            bool isLinked(const Node & x) const;
            void pushLocation(string x, int dist);
            void printLinks();
            


            const string getName(){return Location; }
            const int getWeight(){return Distance;}
            Node getLink(int i){return Links.at(i);}
            const int getSize(){return Links.size();}
            Node findMin();// return node with smallest weight
            Node & operator = (Node const& n)
            {
                Location=n.Location;
                Distance=n.Distance;
                for(int i=0; i<n.Links.size(); i++)
                {
                    Links.push_back(n.Links[i]);
                }
            }


        private:
            vector<Node> Links;
            string Location;
            int Distance;
            

    };

    class dGraph: public Node
    {

        public: 
            //Input list of Nodes
            dGraph(vector<Node> Graph);
            
            void printGraph();
            void Mark(int index);
            bool isMarked(int index);
            string nextNode(string node);
            int getSize(){return size;}
            void start(string start);
            int findIndex(string vertex);
            void findPaths(Node current);


        private:
            int size;
            //Copy of given Node class vector to check links
            vector<Node> Root;
            //Name of given Nodes
            vector<string> Nodes;
            //Current Weight of traveled nodes
            vector<int> Weights;
            //Visited/unvisited nodes
            vector<bool> Marks;
            //previous Nodes
            vector<string> prevNodes;

    };






