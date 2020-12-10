#include <iostream>
#include <cstring>
#include "tree.h"

using namespace std; 

tree::tree(){

}
tree::~tree(){

}
void tree::insert(int num){
  node* n = new node();
  n->data = num;
  if(root == NULL){
    n->isred = false;
    root = n;
    return; 
  }
  node* current = root;
  node* p = current; 
  while(current != NULL){
    p = current; //p is the parent of the null node
    if(n->data < current->data){
      current = current->left;
    }
    else{
      current = current->right; 
    }
  }
  n->parent = p;
  if(n->data < n->parent->data){
    n->parent->left = n; 
  }
  else{
    n->parent->right = n; 
  }
  this->build(n); 
}
void tree::display(node* current){
  if(current != NULL){
    display(current->left);
    if(current==root){
      cout << current->data << "(B) "; 
    }
    else{
      if(current->isred){
	cout << current->data << "(R, " << current->parent->data << ") "; 
      }
      else{
	cout << current->data << "(B, " << current->parent->data << ") "; 
      }
    }
    display(current->right);
  }
}
void tree::leftrotate(node* x){
  node* y = x->right;
  x->right = y->left;
  if(y->left != NULL){
    y->left->parent = x;
  }
  y->parent = x->parent;
  if(x->parent == NULL){
    this->root = y;
  }
  else{
    if(x = x->parent->left){
      x->parent->left = y; 
    }
    else{
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }
}
void tree::rightrotate(node* x){

}
void tree::build(node* n){

}
node* tree::getRoot(){
  return root; 
}
