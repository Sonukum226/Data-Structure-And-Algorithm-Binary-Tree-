#include<iostream>
using namespace std;
struct Node {
	int data;
	Node *left,*right;
};
Node *push(int data){
	Node *temp=new Node;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
int sumofnode(Node *root){
	if(root==NULL)
	return 0;
	return(root->data+sumofnode(root->left)+sumofnode(root->right));
	
}

int main(){
	Node *root=push(10);
	root->left=push(3);
	root->right=push(7);
	root->left->left=push(1);
	root->left->right=push(2);
	root->right->left=push(3);
	root->right->right=push(4);
	int x=sumofnode(root);
	cout<<x;
	return 0;
}
