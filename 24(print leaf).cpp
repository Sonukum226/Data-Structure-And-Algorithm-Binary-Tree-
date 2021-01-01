//this can be a bottom view
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
void printleafnode(Node *root){
	if(root==NULL)
	return ;
	if(root->left==NULL&& root->right==NULL){
		cout<<root->data<<" ";
	}
	if(root->left){
		printleafnode(root->left);
	}
	if(root->right){
		printleafnode(root->right);
	}
}
int main(){
	Node *root=push(1);
	root->left=push(2);
	root->right=push(3);
	root->left->left=push(4);
	root->left->right=push(5);
	root->left->right->left=push(15);
	root->left->right->right=push(14);
	root->right->left=push(6);
	root->right->right=push(7);
	printleafnode(root);
}
