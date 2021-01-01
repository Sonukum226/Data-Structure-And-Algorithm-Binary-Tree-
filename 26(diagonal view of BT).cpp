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

void diagonal(Node *root){
	queue<Node *>q;
	q.push(root);
	Node *cur=0;
	while(!q.empty()){
		if(cur==0){
			cur=q.front();
			q.pop();
		}
		cout<<cur->data<<" ";
		if(cur->left) q.push(cur->left);
		cur=cur->right;
	}
}
int main(){
	Node *root=push(8);
	root->left=push(3);
	root->right=push(10);
	root->left->left=push(1);
	root->left->right=push(6);
	root->right->right=push(14);
	root->right->right->left=push(13);
	root->left->right->left=push(4);
	root->left->right->right=push(7);
	diagonal(root);
}

