//Depth First Traversals:
//(a) Inorder (Left, Root, Right) : 4 2 5 1 3
//(b) Preorder (Root, Left, Right) : 1 2 4 5 3  ->normally
//(c) Postorder (Left, Right, Root) : 4 5 2 3 1
#include<iostream>
#include<queue>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
};
void printinorder(Node *root){
	if(root==NULL){
		return;
	}
	
	printinorder(root->left);
	cout<<root->data<<" ";
	printinorder(root->right);
	
}
void print_preorder(Node *root){
		if(root==NULL){
		return;
	}
	
	print_preorder(root->right);
	cout<<root->data<<" ";
	print_preorder(root->left);
	
}
void print_postorder(Node *root){
		if(root==NULL){
		return;
	}
	
	print_postorder(root->left);
	print_postorder(root->right);
	cout<<root->data<<" ";

}
void inorder(Node *root,int n){
    static int count=0;
	if(root==NULL)
	return ;
	
	if(count<=n){
	inorder(root->left,n);
	count++;
	if(count==n)
	cout<<root->data<<" ";
     
     inorder(root->right,n);
 }
	
}
Node *push(int data){
	Node *temp=new Node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
int main(){
	Node *root=push(1);
	root->left=push(2);
	root->right=push(3);
	root->left->left=push(4);
	root->left->right=push(5);
	root->right->left=push(6);
	root->right->right=push(7);
	cout<<"Inorder::";
	printinorder(root);
	cout<<endl;
	cout<<"Preorder::";
	print_preorder(root);
	cout<<endl;
	cout<<"Postorder::";
	print_postorder(root);
	
	cout<<endl<<"Nth Node of inorder::";
	int n=3;
	inorder(root,n);
}

