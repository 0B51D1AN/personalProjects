
#include <iostream>

using namespace std;

bool sameValue(double *ptr1, double *ptr2);

bool sameAddress(double *ptr1, double *ptr2);

int main()
{

    double *pointer1= new double;
    double *pointer2= new double;

    *pointer1=*pointer2;

    *pointer1= 5.00;

    *pointer2= 6.00;

    cout<<sameValue(pointer1,pointer2)<<'\n';

    
    double *pointer3= new double;
    double *pointer4= new double;
   
    
    double data= 8.00;

    pointer3=&data;
    
    pointer4=&data;
    
    cout<<sameAddress(pointer3,pointer4);




    return 0;
}


bool sameValue(double *ptr1, double *ptr2)
{
    if(*ptr1==*ptr2)
    {
        cout<<"true"<<'\n';
        return true;
    }
    else   
    {
        cout<<"false"<<'\n';
        return false;
    }
}

bool sameAddress(double *ptr1, double *ptr2)
{
    if(ptr1==ptr2)
    {
        cout<<"true"<<'\n';
        return true;
    }
    else
    {    
        cout<<"false"<<'\n';
        return false;
    }

}

//___________________________________________ Memory Leaks and Dangling Pointers_______________________________________________

//1. Neither
//2. Neither
//3. Neither
//4. Neither
//5. Neither
