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
void leftview(Node *root,int level,int *max_level){
	if(root==NULL)
	return ;
	if(level>*max_level){
		cout<<root->data<<" ";
		*max_level=level;
	}
	
	leftview(root->left,level+1,max_level);
	leftview(root->right,level+1,max_level);  //for right view just declare this one before root->left.
}
void printleftview(Node *root){
	int max_level=0;
	leftview(root,1,&max_level);
}
int main(){
	Node *root=push(12);
	root->left=push(10);
	root->right=push(30);
	root->right->left=push(25);
	root->right->right=push(40);
	printleftview(root);
}
