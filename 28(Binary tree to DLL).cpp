#include<iostream>
#include<queue>
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
void DLL(Node *root,Node **head){
	if(root==NULL)
	return ;
	static Node *prev=NULL;
	DLL(root->left,head);
	if(prev==NULL){
		*head=root;
	}
	else{
		root->left=prev;
		prev->right=root;
	}
	prev=root;
	DLL(root->right,head);
}
void print(Node *head){
	while(head){
		cout<<head->data<<" ";
		head=head->right;
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
	Node *head=NULL;
	DLL(root,&head);
	print(head);
}
