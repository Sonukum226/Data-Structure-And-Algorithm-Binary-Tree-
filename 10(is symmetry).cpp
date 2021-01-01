//is symmetrical
#include<iostream>
using namespace std;
struct Node{
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
bool ismirror(Node *n1,Node *n2){
	if(n1==NULL && n2==NULL)
	return true;
	if(n1 && n2 && n1->data==n2->data)
	return ismirror(n1->left,n2->right) &&  ismirror(n1->right,n2->left);
	return false;
}
bool issymmetry(Node *root){
	if(root==NULL)
	return true;
	ismirror(root,root);
}
int main(){
	 Node *root        = push(1); 
    root->left         = push(2); 
    root->right        = push(2); 
    root->left->left   = push(3); 
    root->left->right  = push(4); 
    root->right->left  = push(4); 
    root->right->right = push(3); 
  
    cout << issymmetry(root); 
    return 0; 
}
