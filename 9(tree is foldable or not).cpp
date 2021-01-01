#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
};
bool isfoldable_1(Node *n1,Node *n2); //prototype function
bool isfoldable(Node *root){
	if(root==NULL)
	true;
	isfoldable_1(root->left,root->right);
}
bool isfoldable_1(Node *n1,Node *n2){
	if(n1==NULL && n2==NULL)
	return true;
	if(n1==NULL || n2==NULL)
	return false;
	return	isfoldable_1(n1->left,n2->right) && isfoldable_1(n1->right,n2->left);
}
Node *push(int data){
	Node *temp=new Node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
int main(){
	Node* root = push(1); 
    root->left = push(2); 
    root->right = push(3); 
    //root->left->left=push(3);
    root->left->right = push(4); 
    root->right->left = push(5); 
    
    if (isfoldable(root) == true) { 
        cout << "tree is foldable"; 
    } 
    else { 
        cout << "tree is not foldable"; 
    } 
    return 0;
}
