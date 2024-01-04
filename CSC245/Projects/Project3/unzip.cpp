#include <iostream>
#include <fstream> 
#include <string>
#include <stdlib.h>
#include <cstring>
using namespace std;



///////////////////////////////////////////////
// Make array of keys to insert binary values/ ascii equivalent
struct key
{
    string bEncoding;
    char   ascEncoding;

    key(string b, char a)
    {
        bEncoding=b;
        ascEncoding=a;
    }

};

//////////////////////////////////////////////


int main(int argc, char *argv[])
{

char c;
string File= argv[1];

ifstream inFile( argv[1] );

     if(File.substr(File.size()-4, 4)==".zip")
        {
            
            char ascii[3];
            string b;
            int temp=0;

            // get size for key[]
            inFile.get(c);
            int len= c-'0';
            

            key* chain[len];

        // Place keys in [] and fill them with corresponding values

            if(inFile.good())
            {
                for(int i=0; i<len; i++)
                {
                    
                    while(c!=' ')
                    {
                        
                        inFile.get(c);
                        ascii[temp]=c;
                        temp++;
                    }
                    temp=0;
                    

                    while(c!='\n')
                    {
                        inFile.get(c);
                        b.push_back(c);
                    }
                    
                   char z= (char) atoi(ascii);
                   //cout << z;

                    chain[i]=new key(b,z);
                   // cout<<chain[i]->ascEncoding<<endl;
                    //cout<<chain[i]->bEncoding<<endl;
                    b="";
                }

                // KEY HAS NOW BEEN GENERATED
            }

    //RUN REST OF FILE USE KEY TO GENERATE OUTPUTFILE
    File=File.substr(0, File.size()-4);
    ofstream outFile(File.c_str());

    string stream;

            

        while(inFile)
        {
            inFile>> c;
            stream+= c;
            
            //cout<<c;

            for(int i=0; i<len; i++)
            {
                if(strcmp(chain[i]->bEncoding.c_str(), stream.c_str())==0)
                {
                    cout<<chain[i]->ascEncoding;
                    outFile<<(chain[i]->ascEncoding);
                    //cout<<stream;
                    stream="";
                    //break;
                }
                //cout<<"no";  
            }       
        }
        //cout<<'\n'<<stream<<endl; 
        inFile.close();
        
        outFile.close();
        


            cout<< "\nFile has been unzipped";
        }
    else   
        cout<< "File has already been unzipped or is unsupported";


    return 0;
}

