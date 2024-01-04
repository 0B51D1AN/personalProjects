#include <iostream>
#include "dlist.h"
#include <cstddef>


using namespace std;

void HeadInsert(DList<int>& list1);
void TailInsert(DList<int>& list1);
void AccessItem(DList<int>& list1);
void Delete(DList<int>& list1); 
void PrintList(const DList<int>& list1);
void PrintLength(const DList<int>& list1);
void PrintMenu ();
//void FindMove(DList<int>&list1);

int main()
{

    

    DList<int> list;
    char sel;

    //HeadInsert(list);
    

    do
    {
        PrintMenu ();
        cin >> sel;
        switch (toupper(sel))
        {
            case 'H' : HeadInsert(list); break;
            case 'T' : TailInsert(list); break;
            case 'A' : AccessItem(list); break;
            case 'D' : Delete(list); break;
            case 'P' : PrintList(list); break;
            case 'L' : PrintLength(list); break;
            case 'Q' : cout << "\tExiting Program...\n"; break;
            default : cout << "\tError. Try Again." << endl;
        }
    } while (toupper(sel) != 'Q');





    return 0;
}

//////////////////////////////////////////////////////

void PrintMenu()
{
cout<<"|                                            |\n|                    Menu                    |\n";
cout<<"|                                            |\n";
cout<<"==============================================\n";
cout<<"| Please enter one of the following characters: |\n";
cout<<"| H: Insert item at the front of the list       |\n";
cout<<"| T: Insert item at the back of the list        |\n";
cout<<"| A: Access an item in the list                 |\n";
cout<<"| D: Delete an item in the list                 |\n";
cout<<"| P: Print the list                             |\n";
cout<<"| L: Print the lists's length                   |\n";
cout<<"| Q: Quit the program                           |\n";
cout<<"*******************************************\n\n";


}

//////////////////////////////////////////////////////

void HeadInsert(DList<int>& list1)
{

int ans;

cout<<"Please enter the number you would like to place at the front of the list: \n";
cin>>ans;

list1.insertHead(ans);

}

//////////////////////////////////////////////////////

void TailInsert(DList<int>& list1)
{
int ans;

cout<<"Please enter the number you would like to place at the back of the list: \n";
cin>>ans;
list1.appendTail(ans);

}
//////////////////////////////////////////////////////

void AccessItem(DList<int>& list1)
{
int ans;


PrintList(list1);
if(list1.isEmpty()==false)
{
    cout<<"Please enter the number you would like to access: \n";
    cin>>ans;
    if(list1.inList(ans))
        {
            list1.deleteItem(ans);
            list1.insertHead(ans);
        }
}


}

//////////////////////////////////////////////////////


void Delete(DList<int>& list1)
{
int ans;

PrintList(list1);
if(list1.isEmpty()==false)
{
    
    cout<<"Please enter the number you would like to delete from the list: \n";
    cin>>ans;
    //cout<<list1.inList(ans)<<endl;
    if(list1.inList(ans)==true)
    {
        list1.deleteItem(ans);
        cout<<"Item has been deleted successfully\n";    
    }
    else
        cout<<"The number you entered is not in the list...\n";


}
}
//////////////////////////////////////////////////////

void PrintList(const DList<int>& list1)
{
    if(list1.isEmpty())
        cout<<"There are no items currently in the list...\n";
    else    
        list1.print();


}

//////////////////////////////////////////////////////

void PrintLength(const DList<int>& list1)
{
    cout<<"The Length of the list is currently: "<<list1.lengthIs()<<"\n\n"<<endl;
    
}

