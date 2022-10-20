#include "stack.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
  Stack<int> stck;
  stck.push(21);
    stck.push(4);
  stck.push(3);
    stck.push(2);
      stck.push(23);
cout << stck.size() <<endl;
cout << stck.top() << endl;
stck.pop();
cout << stck.top() << endl;
cout << stck.size()<< endl;



  return 0;
}