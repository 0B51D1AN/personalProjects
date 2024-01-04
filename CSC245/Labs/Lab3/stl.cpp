#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <string.h>

using namespace std;

void compare(stack<string> s1, stack<string> s2);

void Initialize(vector<int> &container);

void Print(vector<int> &container);

void Reverse(vector<int> &container);

void Sort(vector<int> &container);

int main()
{

    stack<string> s1, s2;

    s1.push("Hello there");

    s1.push("General Kenobi");

    s2.push("Hello there");

    s2.push("General Kenobi");


    compare(s1,s2);

    cout<<'\n';

    

    vector<int> hold;


    Initialize(hold);

    Print(hold);

    Reverse(hold);

    Print(hold);

    Sort(hold);

    Print(hold);


    return 0;
}



void compare(stack<string> s1, stack<string> s2)
{

if(s1==s2)
    cout<<"s1==s2\n";
if(s1<s2)
    cout<< "s1< s2\n";
if(s1>s2)
    cout<< "s1>s2\n";

}

void Initialize(vector<int> &container)
{
int ans;

cout<<"Please enter 5 integers: \n";
int count=0;

while (count!=5)
{
    cin>>ans;
    container.push_back(ans);

    //cout<< ans<<'\n';
    count++;
}
}


void Print(vector<int> &container)
{

for(int i=0; i<container.size(); i++)
{
cout<< container.at(i)<<" ";
}
cout<<endl;
}

void Reverse(vector<int> &container)
{

vector<int> temp (container.size());

for(int i=container.size()-1, a=0; i>=0; i--, a++)
{
temp.at(a)=container.at(i);    
}

container.swap(temp);

}

void Sort(vector<int> &container)
{

    sort(container.begin(), container.end());
        
}






