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
int sumtree(Node *root){
	if(root==NULL)
	return 0;
	int old=root->data;
	root->data=sumtree(root->left)+sumtree(root->right);
	return root->data+old;
}
void inorder(Node *root){
	if(root==NULL)
	return ;
	inorder(root->left);
	cout<<" "<<root->data<" ";
	inorder(root->right);
}
int main(){
	Node *root=NULL;
	int x;
	root=push(10);
	root->left=push(-2);
	root->right=push(6);
	root->left->left=push(8);
	root->left->right=push(-4);
	root->right->left=push(7);
	root->right->right=push(5);
	sumtree(root);
	inorder(root);
}
