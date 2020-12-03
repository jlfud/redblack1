#include <iostream>
#include <cstring>

using namespace std;

struct node{
  int color;
  int data;
  node* left = NULL;
  node* right = NULL; 
};
class tree{
 public:
  tree();
  ~tree();
  void add(int);
 private:
  node* root = NULL; 
};
