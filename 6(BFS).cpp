//bfs or level order traversal
#include<iostream>
#include<queue>
using namespace std;
struct Node{
	int data;
Node *lest,*right;
};
void levelorder(Node *root){
	if(root==NULL)
	return;
	queue<Node *>q;
	q.push(root);
	while(!q.empty()){
		Node *temp=q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->lest!=NULL)
		q.push(temp->lest);
		
		if(temp->right)
		q.push(temp->right);
	}
	
}
 Node* push(int data){
 Node *temp=new Node;
 temp->data=data;
 temp->lest=NULL;
 temp->right=NULL;
 return temp;
}
int main(){
	Node *root=push(1);
	root->lest=push(2);
	root->right=push(3);
	root->lest->lest=push(4);
	root->lest->right=push(5);
	root->right->lest=push(6);
	root->right->right=push(7);
	levelorder(root);
}

