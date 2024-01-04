
#include <fstream>
#include <cctype>
#include <iostream>
#include <ctype.h>
#include <stdio.h>
using namespace std;

#include <string>
#include "stack.h" 

struct AdviceNode
{
  string QorA;      // a question or an answer
  AdviceNode * yes;   // yes branch
  AdviceNode * no;    // no branch

  AdviceNode(const string & s);  // constructor
};

AdviceNode::AdviceNode(const string & s)
: QorA(s),
  yes(NULL),
  no(NULL)
{}

void ReadTree(istream & in, AdviceNode * & T);

bool IsQuestionNode(AdviceNode * T);
// precondition:  T is not NULL
// postcondition: returns true if T points to a question node;
//                otherwise returns false

void GiveAdvice(AdviceNode * T);
// precondition: T is not NULL

bool TracePath(AdviceNode * T, const string & movie,
               Stack<string> & pathStack);
// precondition:  T is not NULL

void ShowPath(const Stack<string> & pathStack);

int main()
{
  string fname;
  cout << "\nEnter filename of advice knowledge base: ";
  cin  >> fname; cin.ignore();

  ifstream treeIn(fname.c_str());

  AdviceNode * T;
  ReadTree(treeIn, T);

  GiveAdvice(T);

  string movie;
  Stack<string> path;


  //while(movie != "q"){
    cout << "\nEnter the name of a movie from tree to see path (q to quit): ";
    getline(cin, movie);
    cout<<"Wat";
    if(movie != "q"){
      path.makeEmpty();
      cout<<"yes";
      TracePath(T, movie, path);
      ShowPath(path);
    }
  //}


  return 0;
}

void ReadTree(istream & in, AdviceNode * & T)
{
  string QA;

  getline(in, QA);
  T = new AdviceNode(QA);
  if(QA[QA.length()-1] != '?'){
    T->yes = NULL;
    T->no  = NULL;
  }
  else{
    ReadTree(in, T->yes);
    ReadTree(in, T->no);
  }
}

bool IsQuestionNode(AdviceNode * T)
// precondition:  T is not NULL
// postcondition: returns true f T points to a question node;
//                otherwise returns false
{
  return (T->QorA[(T->QorA).length()-1] == '?');
}

void GiveAdvice(AdviceNode * T)
{
// 1)  Check to see if T is a Question Node.
// 2)  If it is, print T -> QorA and Input a 'Y' or 'N' (in any case).
//     If 'Y', recursively go left (T -> yes).  Otherwise, recursively go right.
// 3)  If the node is not a Question Node, it is a leaf and answer node.  So, just print T -> QorA.
    string ans;

    cout<<T->QorA;
    
    if(IsQuestionNode(T))
      {
        
        getline(cin, ans);

        if(ans=="Y")
          return GiveAdvice(T->yes);
        if(ans=="N")
          return GiveAdvice(T->no);

          
      }
      




}



bool TracePath(AdviceNode * T, const string & movie,
               Stack<string> & pathStack)
{
    pathStack.push(T->QorA);

    if(IsQuestionNode(T))
    {
        cout<<"wow";
        return TracePath(T->no, movie, pathStack);
        return TracePath(T->yes, movie, pathStack);
    }
    else
    {
      if(T->yes->QorA==movie || T->no->QorA==movie)
        {
        pathStack.push(T->QorA);
        return true;
        }
    }
    return false;

}



void ShowPath(const Stack<string> & pathStack)
{
  Stack<string> path(pathStack);

  while(!path.isEmpty()){
    cout << path.top() << endl;
    path.pop();
  }
}
