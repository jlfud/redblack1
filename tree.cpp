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
void tree::leftrotate(node* n){
  node* nn = n->right;
  node* p = n->parent; 
  if(nn == NULL){
    return;
  }
  n->right = nn->left;
  nn->left = n;
  n->parent = nn;
  if(n->right != NULL){
    n->right->parent = n; 
  }
  if(p != NULL){
    if(n == p->left){
      p->left = nn; 
    }
    else if(n == p->right){
      p->right = nn; 
    }
  }
  else{
    root = p;
  }
  nn->parent = p;
}
void tree::rightrotate(node* n){
  node* nn = n->left;
  node* p = n->parent;
  if(nn == NULL){
    return;
  }
  n->left = nn->right;
  nn->right = n;
  n->parent = nn;

  if(n->left != NULL){
    n->left->parent = n;
  }
  if(p != NULL){
    if(n == p->left){
      p->left = nn; 
    }
    else if(n == p->right){
      p->right = nn; 
    }
  }
  else{
    root = p;
  }
  nn->parent = p; 
}
void tree::build(node* n){
  //case 1 taken care of in insert
  //case 2
  if(!n->parent->isred){
    return;
  }
  node* uncle = new node();
  if(n->parent->parent->left == n->parent){
    uncle = n->parent->parent->right;
  }
  else{
    uncle = n->parent->parent->left;
  }
  if(uncle != NULL && n->parent != NULL){
    //case 3
    if(n->parent->isred && uncle->isred){
      uncle->isred = false; 
      n->parent->isred = false;
      n->parent->parent->isred = true;
      if(n->parent->parent != root){
	if(n->parent->parent->parent->parent != NULL){
	   this->build(n->parent->parent);
	}
      }
      else{
	return;
      }
    }
  } 
  node* p = n->parent;
  node* g = n->parent->parent;
  if(n == p->right && p == g->left){
    leftrotate(p);
    n = n->left;
  } 
  else if(n == p->left && p == g->right){
    rightrotate(p);
    n = n->right; 
  }
  p = n->parent;
  g = p->parent;
  if(n == p->left){
    rightrotate(g); 
  }
  else{
    leftrotate(g);
  }
  p->isred = false;
  g->isred = true;
}
node* tree::getRoot(){
  return root; 
}
