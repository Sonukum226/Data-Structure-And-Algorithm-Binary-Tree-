#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *left ,*right;
};
Node *push(int data){
	Node *temp=new Node;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
int height(Node *root){
	if(root==NULL){
		return 0;
	}
	int left=height(root->left);
	int right=height(root->right);
	cout<<right<<" ";
	if(left>right){
		return left+1;
	}
	else {
		return right+1;
	}
}
int main(){
	Node *root=push(1);
	root->left=push(2);
	root->right=push(3);
	root->left->left  = push(4); 
    root->left->right = push(5);
    root->right->right=push(6);
    root->right->right->right=push(8);    
    cout<<height(root);
} 
