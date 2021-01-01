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
int sum(Node *root){
	if(root==NULL)
	return 0;
	return sum(root->left)+root->data + sum(root->right);
}

bool issumtree(Node *root){
	int ls,rs;
	if(root ==NULL || root->left==NULL && root->right==NULL){
		return 1;
	}
	ls=sum(root->left);
	rs=sum(root->right);
	if(root->data==ls+rs && issumtree(root->left) && issumtree(root->right))
	return 1;
return 0;
}
int main(){
	Node *root=push(26);
	root->left=push(10);
	root->right=push(3);
	root->left->left=push(4);
	root->left->right=push(6);
	root->right->right=push(3);
	
	if(issumtree){
		cout<<"Sum tree";
	}
	else{
		cout<<"Not sum tree";
	}
}
