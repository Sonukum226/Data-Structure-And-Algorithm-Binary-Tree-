#include<iostream>
using namespace std;
struct Node {
	int data;
	Node *left,*right;
};
Node *push(int data){
	Node *temp=new Node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
//1. Initialize current as root 
//2. While current is not NULL
//   If the current does not have left child
//      a) Print current’s data
//      b) Go to the right, i.e., current = current->right
//   Else
//      a) Make current as the right child of the rightmost 
//         node in current's left subtree
//      b) Go to this left child, i.e., current = current->left
      
void print(Node *root){
	Node *current=root;
	while(current){
		if(!current->left){
			cout<<current->data;
			current=current->right;
		}
		else{
			
		}
	}
}
