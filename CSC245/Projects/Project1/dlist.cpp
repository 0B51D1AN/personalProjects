#include <cstddef> 
#include <iostream>
#include <new>
using namespace std;

template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType>*	next;
	NodeType<ItemType>*	back;
};

template <class ItemType>		
DList<ItemType>::DList()		// Class constructor
{
    length = 0;
    head = NULL;
}


////////////////////////////////////////////////////////////////
template <class ItemType>
DList<ItemType>::~DList()		
{

        cout<<"Why am I being called??"<<endl;
	// Post: List is empty; All items have been deallocated.
       /* 
        NodeType<ItemType>* tempPtr=last();

        while(tempPtr->back!=NULL)
        {
                tempPtr->next=NULL;
                
        }
        
        delete tempPtr;
*/

}

////////////////////////////////////////////////////////////////
template <class ItemType>
void DList<ItemType>::makeEmpty()
{
    // Post: List is empty; all items have been deallocated.
        /*
        NodeType<ItemType>* tempPtr=last();

        while(tempPtr->back!=NULL)
        {
                tempPtr->next=NULL;
                
        }
        */
        delete head;



}
////////////////////////////////////////////////////////////////

template <class ItemType>
void DList<ItemType>::deleteItem (ItemType item)	
{
	//  Pre :  item to be deleted is passed in via parameter 
        // Post :  item is deleted if it exists in list 
        NodeType<ItemType>* tempPtr= location(item);

        deleteLocation(tempPtr);
        


}


////////////////////////////////////////////////////////////////
template <class ItemType>
bool DList<ItemType>::inList (ItemType item) const
{
	//  Pre :  item to be located is passed in via parameter 
        // Post :  function returns bool value if item is found 

        NodeType<ItemType>* tempPtr=head;

        while (tempPtr->info!=item)
        {
                if(tempPtr->next==NULL)
                        return false;
                
                tempPtr=tempPtr->next;

        }

        return true;


}





////////////////////////////////////////////////////////////////
template <class ItemType>
bool DList<ItemType>::isEmpty() const		
{
	// Post : function returns true if list is empty, false otherwise
        if(head==NULL)
        {
                //cout<<"True\n";
                return true;
        }
        else
        {
                //cout<<"False\n";
                return false;
        }
}





////////////////////////////////////////////////////////////////
template <class ItemType>
void DList<ItemType>::print() const	
{
	// Pre  : List is not empty 
	// Post : Items in List have been printed to screen
        NodeType<ItemType>* tempPtr=head;

        cout<<"List:  ";

        if(length==1)
        {
                cout<<"| "<<head->info<<" |"<<endl;
        }
        else
        {
                cout<<"| ";
                while(tempPtr->next!=NULL)
                {       
                        cout<<tempPtr->info<<" | ";
                        tempPtr=tempPtr->next;
                }
                cout<<tempPtr->info<<" |\n\n"<<endl;
                
        }

}







////////////////////////////////////////////////////////////////	
template <class ItemType>
void DList<ItemType>::insertHead(ItemType item)	
{
	//  Pre : item to be inserted is passed in via parameter
        // Post : item is inserted at head of list;  Former first node is 
        //        linked back to this new one via double link;
        //        Length incremented;  Special case handled if list is empty 


        // ALLOCATE MEMORY FOR NEW ITEM

        NodeType<ItemType>* tempNode= new NodeType<ItemType>;
        

        if(isEmpty()==true)
        {
                head=tempNode;
                head->info=item;
                length++;
                cout<< "Item placed at the front of the list: "<<head->info<<endl;
        }
        else
        {
               head->back=tempNode; 
               tempNode->info=item;
               tempNode->next=head;
               head=tempNode;
               length++;
               cout<< "Item placed at the front of the list: "<< head->info<<endl;
        }
}




////////////////////////////////////////////////////////////////
template <class ItemType>
void DList<ItemType>::appendTail(ItemType item)
{
	//  Pre :  item to be inserted is passed in via parameter
        // Post :  item is added to tail of list; Former last node
        //         is linked to this new one via double link 
        NodeType<ItemType>* tempNode= new NodeType<ItemType>;
        

        if(isEmpty()==true)
        {
              head=tempNode;
              head->info=item;
              length++;
              cout<< "Item placed at the back of the list: "<<head->info<<endl; 
        }
        else
        {
                NodeType<ItemType>* lastPtr=last();
                lastPtr->next=tempNode;
                tempNode->info=item;
                tempNode->back=lastPtr;  
                length++;    
                cout<< "Item placed at the back of the list: "<<last()->info<<endl;        

        }





}
////////////////////////////////////////////////////////////////
template <class ItemType>
int DList<ItemType>::lengthIs() const	
{
	// Post : Function returns current length of list  
        return length;
}
////////////////////////////////////////////////////////////////
template <class ItemType>
NodeType<ItemType>* DList<ItemType>::location(ItemType item) const	
{
	//  Pre : item to be located is passed in via parameter 
        // Post : function returns address of item being searched for --
        //        if not found, NULL is returned  
        
        NodeType<ItemType>* tempPtr=head;

        while(tempPtr->next != NULL)
        {
                if(tempPtr->info==item)
                        return tempPtr;
                else
                        tempPtr=tempPtr->next;
        }

        return NULL;


	
}
////////////////////////////////////////////////////////////////
template <class ItemType>
NodeType<ItemType>* DList<ItemType>::last() const	
{
	// Post : Function returns location of current last item in list
        NodeType<ItemType> *ptrlast= head;

        while (ptrlast->next != NULL)
        {
                ptrlast=ptrlast->next;

        }

	return ptrlast;

}
////////////////////////////////////////////////////////////////
template <class ItemType>
void DList<ItemType>::deleteLocation (NodeType<ItemType>* delPtr)	
{

	//  Pre : Item to be deleted exits in list and its location
        //        is passed in via parameter
                   
	// Post : Location passed in is removed from list;  Length
        //        is decremented, and location is deallocated 

        // Special Cases Handled for Deleting Only One Item in List,
        // The Head Item of List, and the Tail Item of List
        
        NodeType<ItemType>* tempPtr= delPtr;
        NodeType<ItemType>* lastPtr=last();

       if(delPtr=head)
       { 

                if(head->next==NULL)
                {     
                        cout<<"Yes"<<endl;
                        head=NULL;
                        delete tempPtr;
                        length=0;
                }
                else
                {
                        cout<<"No"<<endl;
                        head=head->next;
                        delPtr->next=NULL;
                        delPtr->back=NULL;
                        head->back=NULL;
                        delete delPtr;
                        length--;
                }
       }
       cout<<lastPtr->info<<endl;
       if(delPtr=last())
       {

                lastPtr=lastPtr->back;
                lastPtr->next=NULL;
                lastPtr->back=NULL;
                delete delPtr;
                length--;
       }    
      
        /*       

        if(tempPtr->info==head->info) 
        {
                cout<<"First"<<endl;
                if(head->next==NULL)
                {
                        delete tempPtr;
                        length=0;
                }
                else
                {
                        head=head->next;
                        tempPtr->next=NULL;
                        head->back=NULL;
                        delete tempPtr;
                        length--;
                }

        }
        if(tempPtr==last())
        {
                cout<<"Last"<<endl;
                (tempPtr->back)->next=NULL;
                tempPtr->back=NULL;
                delete delPtr;
                length--;

        }
        else
        {
                cout<<"Mid"<<endl;
                tempPtr=delPtr->back;
                tempPtr->next=delPtr->next;
                delPtr->next->back=tempPtr;
                delete delPtr;
                length--;
        }
        
        */


        /*

        if(tempPtr=head)
        {
                if(head->next!=NULL)
                {
                        cout<<"No"<<endl;
                        head=head->next;
                        tempPtr->next=NULL;
                        head->back=NULL;
                        
                        delete tempPtr;
                        length--;
                       
                       
                }
                else
                {
                       cout<<"Yes"<<endl;
                       //head=NULL;
                       delete head;
                       length--;
                }
        }
        if(tempPtr=last())
        {
                //cout<<"Yes"<<endl;
                tempPtr=tempPtr->back;
                tempPtr->next=NULL;
                tempPtr->back=NULL;
                delete tempPtr;
                length--;
        }
        else 
        {
                //cout<<"No"<<endl;
                tempPtr->back->next=tempPtr->next;
                tempPtr->next->back=tempPtr->back;
                delete tempPtr;
                length--;                
        }
        
        */

}
