#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
};
Node *push(int data){
	Node *temp=new Node;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
void printleaves(Node *root){ 
	if(root==NULL)
	return ;
	printleaves(root->left);
	if(root->left==NULL && root->right==NULL){
		cout<<root->data<<" ";
	}
	printleaves(root->right);
}
void printleft(Node *root){
	if(root==NULL)
	return ;
	if(root->left){
	cout<<root->data<<" ";
	printleft(root->left);
}
else if(root->right){
	cout<<root->data<<" ";
	printleft(root->right);
}
	
}
void printright(Node *root){
	if(root==NULL)
	return ;
	if(root->right){
		cout<<root->data<<" ";
		printright(root->right);
	}
	else if(root->left){
		cout<<root->data<<" ";
		printright(root->left);
	}
}
void printboundry(Node *root){
	if(root==NULL)
	return ;
	cout<<root->data<<" ";
	printleft(root->left);
	printleaves(root->left);
	printleaves(root->right);
	printright(root->right);
}
int main(){
	Node *root=push(20);
	root->left=push(8);
	root->left->left=push(4);
	root->left->right=push(12);
	root->left->right->left=push(10);
	root->left->right->right=push(14);
	root->right=push(22);
	root->right->right=push(25);
	
	printboundry(root);
}
