#include<iostream>
#include<stack>
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
int sumofleafnode(Node *root){
	stack<Node *>st;//created a stack	
	st.push(root);//push the root in stack
	int sum=0;
	while(!st.empty()){//loop will count till stack is not empty
	Node *current=st.top();//current node
	st.pop();//delete the top most
	if(current->left!=NULL){ //if current->left is null then  
		st.push(current->left); 
		if(current->left->left==NULL &&current->left->right==NULL){
			sum=sum+current->left->data;
		}
		
	}	
	if(current->right!=NULL){
		st.push(current->right);
	}
	}
	return sum;
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
    cout << "Sum of left leaves is "
         << sumofleafnode(root); 
    return 0; 
}
