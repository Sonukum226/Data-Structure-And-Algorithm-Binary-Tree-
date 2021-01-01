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
bool checkutil(Node *root,int level,int *leaflevel){
	if(root==NULL)
	return true;
	if(root->left==NULL && root->right==NULL){
		if(*leaflevel==0){
		   *leaflevel=level;
			return true;
		}
		return level==*leaflevel;
	}
	return checkutil(root->left,level+1,leaflevel) && checkutil(root->right,level+1,leaflevel);
}
bool check(Node *root){
	int level=0,leaflevel=0;
	return checkutil(root,level,&leaflevel);
}

int main(){
	Node *root=push(12);
	root->left=push(5);
	root->left->left=push(3);
	root->left->right=push(9);
	root->left->left->left=push(1);
	root->left->right->left=push(1);
	
	if(check(root)){
		cout<<"leaves are at same level";
	}
	else cout<<"Leaves are not at same level";
	
	
}
