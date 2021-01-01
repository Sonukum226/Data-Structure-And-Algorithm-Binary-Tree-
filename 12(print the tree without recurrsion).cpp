#include<iostream>
#include<stack>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
};
Node *push(int data)
{
	Node *temp=new Node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
//1) Create an empty stack S.
//2) Initialize current node as root
//3) Push the current node to S and set current = current->left until current is NULL
//4) If current is NULL and stack is not empty then 
//     a) Pop the top item from stack.
//     b) Print the popped item, set current = popped_item->right 
//     c) Go to step 3.
//5) If current is NULL and stack is empty then we are done.
void print(Node *root){
	stack<Node *> st;
	Node *current=root;
	while(current!=NULL || !st.empty()){
		while(current!=NULL){
			st.push(current);
			current=current->left;
		}
		current=st.top();
		st.pop();
		cout<<current->data<<" ";
		current=current->right;
	}
}
int main(){
	Node *root=push(1);
	root->left=push(2);
	root->right=push(3);
	root->left->left  = push(4); 
    root->left->right = push(5); 
	print(root);
}
