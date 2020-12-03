#include <iostream>
#include <cstring>
#include "tree.h"
using namespace std;

int main(){
  char in[80];
  int intin; 
  tree* t = new tree();
  
  cout << "red black tree part 1: add, read, print, quit" << endl;
  while(true){
    cout << "command: " << endl;
    cin >> in;
    if(strcmp(in, "add")==0){
      cout << "value to input: " << endl;
      cin >> intin; 
      t->add(intin); 
    }
    else if(strcmp(in, "read")==0){

    }
    else if(strcmp(in, "print")==0){

    }
    else if(strcmp(in, "quit")==0){
      return 0;
    }
    else{
      cout << "invalid command. " << endl;
    }
  }
}
