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
int sumrirghtleaf(Node *root){
	stack<Node *> st;
	st.push(root);
	int res=0;
	while(!st.empty()){
		Node *current=st.top();
		st.pop();
		if(current->right!=NULL){
			st.push(current->right);
			if(current->right->left==NULL && current->right->right==NULL){
				res+=current->right->data;
			}
		}
		if(current->left!=NULL)
		st.push(current->left);
	}
	return res;
}
int main(){
	struct Node *root  = push(1); 
	root->left=push(2);
	root->left->left = push(4); 
	root->left->right = push(5); 
	root->left->left->right = push(2); 
	root->right = push(3); 
	root->right->right = push(8); 
	root->right->right->left = push(6); 
	root->right->right->right     = push(7); 
    cout << "Sum of right leaves is "
         <<sumrirghtleaf(root); 
    return 0; 
}
