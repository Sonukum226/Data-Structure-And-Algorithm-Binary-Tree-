//Expression Tree
//Expression tree is a binary tree in which each internal node corresponds to operator and each leaf node corresponds to operand so for example expression 
//tree for 3 + ((5+9)*2) would be:
//
//Inorder traversal of expression tree produces infix version of given postfix expression (same with preorder traversal it gives prefix expression)
#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
struct Node{
 char data;
 Node *left,*right;
};
bool isoperator(char c){
	if(c=='+' || c=='*' || c=='-' || c=='/'|| c=='^')
	return true;
	else
	return false;
}
void inorder(Node *root){
	if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}
 Node *push(int data){
 	Node *temp=new Node;
 	temp->data=data;
 	temp->left=NULL;
 	temp->right=NULL;
 	return temp;
 }
 Node *construct_tree(char postfix[]){
 	int l=strlen(postfix);
 	stack<Node *> st;
 	Node *t,*t1,*t2;
 	for(int i=0;i<l;i++){
 		if(!isoperator(postfix[i])){
 			t=push(postfix[i]);
 			cout<<t->data<<" ";
 			st.push(t);		   //   ab+ef*g*-
		 }
		 else{
		 	t=push(postfix[i]);
		 	t1=st.top();
		 	st.pop();
		 	t2=st.top();
		 	st.pop();
		 	t->right=t1;
		 	t->left=t2;
		
		st.push(t);
		 }
	 }
	 t=st.top();
	 st.pop();
	 return t;
 }
 int main(){
 	 char postfix[] = "ab+ef*g*-"; 
    Node* r = construct_tree(postfix); 
    cout<<"infix expression is \n"; 
    
    inorder(r); 
    return 0; 

 }
