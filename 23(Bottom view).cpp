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
void leaf(Node *root){
	if(root==NULL)
	return ;
	queue<Node *>q;
	q.push(root);
	
	while(q.size()){
		Node *current=q.front();
		q.pop();
		if(current->left!=NULL){
			q.push(current->left);
			if(current->left->left==NULL && current->left->right==NULL){
				cout<<current->data<<" ";
			}
		}
		if(current->right!=NULL){
			q.push(current->right);
		}
	}
	
}
int main(){
	struct Node *root         = push(20); 
    root->left                = push(9); 
    root->right               = push(49); 
    root->right->left         = push(23); 
    root->right->right        = push(52); 
    root->right->right->left  = push(50); 
    root->left->left          = push(5); 
    root->left->right         = push(12); 
    root->left->right->right  = push(12); 
    leaf(root);
}
