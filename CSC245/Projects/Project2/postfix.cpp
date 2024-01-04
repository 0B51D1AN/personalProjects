#include "stack.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool isValid(char* ans);
void printManual();
void doMath(char* ans);
bool checkInt(char ans);
bool checkOp(char ans);
char * substr(char * ans, int pos, int length);



int main()
{
    char ans[256];
    int i=0;
    char exit;

    
    

    try         //pull string
    {
        printManual();
        cin.getline(ans,256,';');

    isValid(ans);

    doMath(ans);        

    }catch(const char* msg){//catch exceptions
        cerr<<msg<<endl;
    }

    //cout<< "Would you like to go again?(Y/N)"<<endl;
    //cin>>exit;



    
    //Print all commands to terminal
    
    return 0;

}




bool isValid(char* ans)
{
//Returns true if character(s) are found in the list of valid entries 
//Returns false otherwise
int i=0;
char table[]= " 1234567890_-+*/ " ;
size_t sizeAns= strlen(ans);

i=strspn(ans,table);

if(i!=sizeAns)
{
    throw "Invalid character has been input. Quitting now";
    return false;
}
else
{
    cout<<"Input: "<<ans<<endl;   
    return true;
}
//throw exception invalid token
}


void doMath(char* ans)
{
// When no exception has been thrown, doMath pops last 2 values in stack +operator and does operation. THROW OPERATOR EXCEPTIONS HERE
stack <int>Math(10);
//char temp[256];
int front=0;
int back=0;
size_t sizeAns=strlen(ans);


while(front<sizeAns)
{
    // CHECK NEGATIVE
    if(ans[front]=='_')
    {
        back=front+1;
        while(checkInt(ans[back])==true)
        {
            back++;
            //cout<<back<<endl;
        }
        //strncpy(temp, ans, back-front);
        //temp=substr(ans, front+1, back-front);
        
        Math.push(-atoi(substr(ans, front+1, back-front)));
        
        cout<<"Token: "<<Math.top()<<"  Push: "<<Math.top()<<endl;
        //memset(temp,0,sizeof(temp));
        front=back;
        
    }
    
    // CHECK INT
    if(checkInt(ans[front]))
    {
        back=front;
        while(checkInt(ans[back]))
        {
            back++;
            //cout<<back<<endl;
        }
        Math.push(atoi(substr(ans, front, back-front)));
        
        cout<<"Token: "<<Math.top()<<"  Push: "<<Math.top()<<endl;
        //memset(temp,0,sizeof(temp));
        front=back;
        
        //cout<<temp;
    }

    //CHECK SPACE
    if(ans[front]==' ')
        front++;


    //CHECK OPERATOR
    if(checkOp(ans[front]))
    {
        //int product=0;
        
        int a=Math.topAndPop();
        if(Math.isEmpty())
            throw "Stack empty!";

        int b=Math.topAndPop();

        // IF +
        if(ans[front]=='+')
        {
            
            cout<< "Found + operator    Pop: "<<a<<" Pop:"<<b<<endl;
            Math.push(a+b);
            //product=0;
            front++;   
        }

        // IF -
        if(ans[front]=='-')
        {
            //product= Math.topAndPop()-Math.topAndPop();
            
            cout<< "Pop: "<<a<<" Pop:"<<b<<endl;
            Math.push(a-b);
           // product=0;
            front++;   
        }

        //IF /
        if(ans[front]=='/')
        {
            
            
            if(b==0)
                throw "Division by Zero! Now exitting";
            
            cout<< "Pop: "<<a<<" Pop:"<<b<<endl;
            Math.push(a/b);
            //product=0;
            front++;   
        }

        // IF *
        if(ans[front]=='*')
        {
            //product= Math.topAndPop()*Math.topAndPop();
            cout<< "Pop: "<<a<<" Pop:"<<b<<endl;
            Math.push(a*b);
           // product=0;
            front++;   
        }

    }


}
//pop final number left in stack
cout<<"Final Result: "<< Math.topAndPop()<<endl;

//throw exception invalid operation (divide by 0)
}


char * substr(char * ans, int pos, int length)
{
    char* temp= new char[length+1];
    int a=0;
    for(int i=pos; i<length; i++)
    {
        temp[a]=ans[i];
        a++;

    }
    //temp[length]=0;
    return temp;


}

bool checkInt(char ans)
{
    int x=0;
    char intTable[]="1234567890";

    for(int i=0;i<sizeof(intTable); i++)
    {
        if(ans==intTable[i])
            x++;

    }

    if(x>0)
        return true;
    else   
        return false;

}

bool checkOp(char ans)
{
    int x=0;
    char opTable[]="+-/*";

    for(int i=0;i<sizeof(opTable); i++)
    {
        if(ans==opTable[i])
            x++;

    }

    if(x>0)
        return true;
    else   
        return false;

    

}

void printManual()
{
    cout<<"__________ POSTFIX EVALUATOR __________\n";
    cout<<"Please enter integers and valid operators\n";
    cout<<"Your RPN Expression: ";
    //clearscreen? curses.h?
    
    
}

