#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

#include <stdio.h>
#include <string.h>


using namespace std;

int maxElemLength(const vector<string> & v);
int GetDigit(string word, int k);
vector<queue<string> > ItemsToQueues(const vector<string> & L, int k);
vector <string> QueuesToArray(vector<queue<string> > & QA, int numVals);
void RadixSort(vector<string>& L, int numDigits);
void PrintVector(const vector<string> & L);


int main()
{
    vector<string> test;
    test.push_back("zebra");
    // "apple", "orange", "can", "candy", "a", "top", "pumpkin", "today", "parade"};
    test.push_back("apple");
    test.push_back("orange");
    test.push_back("can");
    test.push_back("candy");
    test.push_back("a");
    test.push_back("top");
    test.push_back("pumpkin");
    test.push_back("today");
    test.push_back("parade");

    //cout<< GetDigit("a",0);


    //PrintVector(test);

    //cout<< maxElemLength(test);

    //cout << GetDigit(test[0], 2);

    //ItemsToQueues(test, 1);

   RadixSort(test, 1);

    //int result= strcmp("abracadabra", "a");

   // cout<<result;

    PrintVector(test);



    return 0;
}

int maxElemLength(const vector<string> & v)
{

int charNum=0;


    for(int i=0; i<v.size(); i++)
        {
            if(charNum<v[i].size())
                charNum=v[i].size();            
        }

    return charNum;

}

int GetDigit(string word, int k)
{

    return  word[k];

}



vector<queue<string> > ItemsToQueues(const vector<string> & L, int k)
{
    vector<queue<string> > QtoA(128);
    int temp;

        //insert words initially inside respective queues

        for(int i=0; i<L.size(); i++)
        {
            temp=GetDigit(L[i],k);
            if(temp!=0)  
                temp=temp-97;

            QtoA[temp].push(L[i]);
        }

        //sort queues by 

    return QtoA;
}



vector <string> QueuesToArray(vector<queue<string> > & QA, int numVals)
{
    vector <string> QtoA;
    string temp;
    //int comp=0;

    for(int i=0; i<QA.size(); i++)
    {
        while(!QA[i].empty())
        {
            
            temp= QA[i].front();
            QA[i].pop();

           if(!QA[i].empty())
           {
                if(temp.compare(QA[i].front()) <0)
                    QA[i].push(temp);
                else
                {
                QtoA.push_back(QA[i].front());
                QA[i].push(temp);
                QA[i].pop();
                }
           }
           else
            QtoA.push_back(temp);
        }

    }

    return QtoA;

}




void RadixSort(vector<string>& L, int numDigits)
{
    vector<queue<string> > QA(128);
    for(int k=0; k<numDigits; k++)
    {
        QA = ItemsToQueues(L,k);
        L=QueuesToArray(QA, L.size());

    }


}


void PrintVector(const vector<string> & L)
{
    for(int i=0; i<L.size(); i++)
    {
        cout<<L[i]<<" ";
    }

}

