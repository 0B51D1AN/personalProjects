
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>


using namespace std;

int maxElemLength(const vector<int> & v);
int GetDigit(int number, int k);
vector<queue<int> > ItemsToQueues(const vector<int> & L, int k);
vector <int> QueuesToArray(vector<queue<int> > & QA, int numVals);
void RadixSort(vector<int>& L, int numDigits);
void PrintVector(const vector<int> & L);


int main()
{
    vector<int> test;
    // Test array with elements:
    // 380, 95, 345, 382, 260, 100, 492


    test.push_back(380);
    test.push_back(95);
    test.push_back(345);
    test.push_back(382);
    test.push_back(260);
    test.push_back(100);
    test.push_back(492);

    //PrintVector(test);
    
    //cout<< maxElemLength(test);

    //cout<< 10^(3+1);
    
    RadixSort(test, maxElemLength(test));

    PrintVector(test);


    //cout<< GetDigit(467,2);
    
    
    return 0;
}

int maxElemLength(const vector<int> & v)
{

// Search through value then return number of digits
int ans=v[0];
int digits=0;

    for(int i=0; i<v.size(); i++)
        {
            if(v[i]>ans)
                ans=v[i];            
        }
    
    

    while(ans!=0)
    {
        ans/=10;
        digits++;
    }

    return digits;

}

int GetDigit(int number, int k)
{
   int temp= number%((int)pow((double)10,(double)(k+1)));
    //cout<<temp<<endl;

        for(int digitNum=1; digitNum<=10; digitNum++) 
        {
            if(temp<(digitNum*(pow((double)10,(double)k))))
                {
                    //return digitNum-1;
                    return digitNum-1; 
                    break;
                }
        }      
    //return 0;

}

vector<queue<int> > ItemsToQueues(const vector<int> & L, int k)
{
    vector<queue<int> > QtoA(10);
    int temp;

        for(int i=0; i<L.size(); i++)
        {
            temp=GetDigit(L[i],k);
            QtoA[temp].push(L[i]);
        }

    return QtoA;


}

vector <int> QueuesToArray(vector<queue<int> > & QA, int numVals)
{
    vector <int> QtoA(0);

    for(int i=0; i<QA.size(); i++)
    {
        while(!QA[i].empty())
        {
            QtoA.push_back((int)QA[i].front());
            QA[i].pop();
        }

    }

    return QtoA;

}




void RadixSort(vector<int>& L, int numDigits)
{
    vector<queue<int> > QA(10);
    for(int k=0; k<numDigits; k++)
    {
        QA = ItemsToQueues(L,k);
        L=QueuesToArray(QA, L.size());

    }


}


void PrintVector(const vector<int> & L)
{
    for(int i=0; i<L.size(); i++)
    {
        cout<<L[i]<<" ";
    }

}
