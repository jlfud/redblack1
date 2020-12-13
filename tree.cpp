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
void tree::rightrotate(node* y){
  node* x = y->left;
  y->left = x->right;
  if(x->right != NULL){
    x->right->parent = x;
  }
  x->parent = y->parent;
  if(y->parent == NULL){
    this->root = x; 
  }
  else{
    if(y = y->parent->right){
      y->parent->right = x; 
    }
    else{
      y->parent->left = x; 
    }
    x->right = y;
    y->parent = x; 
  }
  
}
void tree::build(node* n){
  //case 1 taken care of in insert
  if(!n->parent->isred){
    return;
  }
  else if(n->parent->right != NULL && n->parent->left != NULL){
    node* uncle = new node();
    if(n->parent->left == n){
      //n is the left node
      uncle = n->parent->right; 
    }
    else{
      uncle = n->parent->left;
    }
    if(n->isred && uncle->isred){
      cout << "3" << endl;
      uncle->isred = false; 
      n->parent->isred = false;
      n->parent->parent->isred = true;
      this->build(n->parent->parent);
    }
    //on case 4
    if(!uncle->isred){
      cout << "4/5" << endl;
      if(!(n->parent->right == n && n->parent->parent->left == n->parent) || (!(n->parent->left == n && n->parent->parent->right == n->parent))){
	//case 5
	rightrotate(n->parent);
	bool pred = n->parent->isred;
	n->parent->isred = n->parent->parent->isred;
	n->parent->parent->isred = pred; 
      }
      else{
	leftrotate(n->parent);
      }
    }
  }
}
node* tree::getRoot(){
  return root; 
}
