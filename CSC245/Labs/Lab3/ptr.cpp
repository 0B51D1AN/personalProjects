#include <iostream>
#include <string.h>
#include <ctype.h>
#include <cstring>
using namespace std;
struct RecType
{
    int age;
    float weight;
    char gender;


};


int main()
{

int num=5;

int *intPtr= new int;

intPtr=&num;



cout << *intPtr * 10;






RecType *recPtr= new RecType; 

recPtr-> age=25, recPtr-> weight=190, recPtr-> gender='M';

recPtr->age+=5;


cout <<(recPtr->age)<<" "<<(recPtr->weight)<<" "<<(recPtr->gender)<<'\n';

delete recPtr;


recPtr=NULL;

char *strPtr= new char[50];



strcpy (strPtr,"Operating Systems");
cout<< strPtr<<'\n';

int a=0;
for(int i=0; i<strlen(strPtr); i++)
{
char *charPtr= new char;
*charPtr=strPtr[i];
if (islower(*charPtr))
a++;


}
cout << a<<'\n';


strPtr= strPtr+10;

cout<< strPtr<< " ";

strPtr=strPtr-10;

cout<< strPtr<< " ";

delete strPtr;





return 0;
}

