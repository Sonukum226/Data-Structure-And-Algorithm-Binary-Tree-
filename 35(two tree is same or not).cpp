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

int is_same(Node *r1,Node *r2){
	if(r1==NULL && r2==NULL)
	return 1;
	else if(r1 !=NULL && r2==NULL)
	return 0;
	else if(r1==NULL && r2!=NULL)
	return 0;
	else 
		if(r1->data==r2->data && is_same(r1->left,r2->left) && is_same(r1->right,r2->right))
		return 1;
		else 
		return 0;
	
}

int main(){
	 Node *root        = push(1); 
    root->left         = push(2); 
    root->right        = push(2); 
    root->left->left   = push(3); 
    root->left->right  = push(4); 
    root->right->left  = push(4); 
    root->right->right = push(3); 
    
    
    Node *root_2       = push(1); 
    root_2->left         = push(2); 
    root_2->right        = push(2); 
    root_2->left->left   = push(3); 
    root_2->left->right  = push(4); 
    root_2->right->left  = push(4); 
    root_2->right->right = push(3); 
    
	if(is_same(root,root_2)){
		cout<<"yes";
	}
	else cout<<"No";
}
