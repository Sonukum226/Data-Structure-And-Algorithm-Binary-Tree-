//Remove all nodes which don’t lie in any path with sum>= k
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
void print(Node *root){
	if(root!=NULL){
		print(root->left);
		cout<<root->data<<" ";
		print(root->right);
	}
}
Node *prune(Node *root,int sum){
	if(root==NULL)
	return NULL;
	
	root->left=prune(root->left,sum-root->data);
	root->right=prune(root->right,sum-root->data);
	
	if(root->left==NULL && root->right==NULL){
		if(root->data<sum){
			free(root);
			return NULL;
		}
		
	}
	return root;
}

int main() 
{ 
    int k = 45; 
    struct Node *root = push(1); 
    root->left = push(2); 
    root->right = push(3); 
    root->left->left = push(4); 
    root->left->right = push(5); 
    root->right->left = push(6); 
    root->right->right = push(7); 
    root->left->left->left = push(8); 
    root->left->left->right = push(9); 
    root->left->right->left = push(12); 
    root->right->right->left = push(10); 
    root->right->right->left->right = push(11); 
    root->left->left->right->left = push(13); 
    root->left->left->right->right = push(14); 
    root->left->left->right->right->left = push(15); 
  
    cout << "Tree before truncation\n"; 
    print(root); 
  
    root = prune(root, k); // k is 45 
  
    cout << "\n\nTree after truncation\n"; 
    print(root); 
  
    return 0; 
} 
