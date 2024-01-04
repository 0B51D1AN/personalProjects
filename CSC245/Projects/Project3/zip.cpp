#include <iostream>
#include "huffman.h"
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc, char* argv[])
{
    HuffmanTree Tree= HuffmanTree();

    // GOAL: Read File, Simultaneously entering all characters begin adding frequencies
   
    // START: Read file check argv for --t (Encoding table), --help
    
    string File;

    string help="--help";
    string t="--t";

    //cout<<argv[1];
    if(argv[1]!=NULL)
    {
        if(strcmp(argv[1],help.c_str())!=0 && strcmp(argv[1],t.c_str())!=0)
        {            
                File=argv[1];

                    if(File[File.size()-4]=='.')
                    {
                        cout<< "File is formatted incorrectly";
                        return 0;
                    }
            
        }
        else if (argv[2]!=NULL)
        {
                    File=argv[2];
                    if(File[File.size()-4]=='.')
                        cout<< "File is formatted incorrectly";                    
        }
       
    // NEXT: Begin reading characters and inputting them into hash.
    // Push used chars into temp stack, generate HNode with weight(s) when file has been read

    ifstream inFile( File.c_str());

    char c;

    int charHash[126];

    for (char i=char(0); i<=char(126); i++)
        charHash[i]=0;

    vector <char> temp;

        

        while(inFile)
        {           
            //inFile>> c;
            //cout<<c;
            if((charHash[(int)c]==0)&& (c!=' ') && (c!='\n'))
            {   
                temp.push_back((char)c);
                cout<<c;
                charHash[(int)c]++;
            }
            else if((charHash[(int)c]==0) && (c==' '))
              {  
                temp.push_back('2');
                charHash[(int)c]++;
              }
            else if((charHash[(int)c]==0) && (c=='\n'))
            {
                temp.push_back('1');
                charHash[(int)c]++;
            }
            else
                charHash[(int)c]++;


            inFile>>c;

        }

        //cout<<charHash[0];


        

        

    // NEXT: Begin building Huffman Tree by inserting char values used with corresponding weights


        
        //Tree.insert('\0',-1);

            while(!temp.empty())
            {
                //cout<<temp.back();
                Tree.insert((char)temp.back(), charHash[(int)temp.back()]);
                temp.pop_back();
            }


            //Tree.build();
        

    // All characters have been placed in built Huffman Tree

    // NEXT: Write Table and Binary Encoding of file to .zip file

    // Start output file
    File+=".zip";
    ofstream outFile(File.c_str());
    
    
    

    if(strncmp(argv[1],help.c_str(),help.size())==0)
    {
        system("cat help");
    }
    else if(strncmp(argv[1],t.c_str(),t.size())==0)
    {
        Tree.PrintTable();
    }
    

    }
    else
        cout<<"File does not exist";
    



    return 0;
}
    



