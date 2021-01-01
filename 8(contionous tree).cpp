////contionous tree
#include<bits/stdc++.h> 
using namespace std; 
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct Node 
{ 
    int data; 
    struct Node* left, * right; 
}; 
  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct Node* newNode(int data) 
{ 
    struct Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return(node); 
} 
  

bool treeContinuous(struct Node *ptr) 
{ 
    
    if (ptr == NULL) 
        return true; 
  
   
    if (ptr->left == NULL && ptr->right == NULL) 
        return true; 
  
     
    if (ptr->left == NULL) 
       return (abs(ptr->data - ptr->right->data) == 1) && 
              treeContinuous(ptr->right); 
  

    if (ptr->right == NULL) 
       return (abs(ptr->data - ptr->left->data) == 1) && 
              treeContinuous(ptr->left); 
  
    
    return  abs(ptr->data - ptr->left->data)==1 && 
            abs(ptr->data - ptr->right->data)==1 && 
            treeContinuous(ptr->left) && 
            treeContinuous(ptr->right); 
} 
  
int main() 
{ 
    struct Node *root = newNode(3); 
    root->left        = newNode(2); 
    root->right       = newNode(4); 
    root->left->left  = newNode(1); 
    root->left->right = newNode(3); 
    root->right->right = newNode(5); 
    treeContinuous(root)?  cout << "Yes" : cout << "No"; 
    return 0; 
} 

//#include<bits/stdc++.h>
//
//using namespace std;
//struct Node{
//	int data;
//	Node *left,*right;
//};
//struct Node *push(int data){
//	Node *temp=new Node;
//	temp->data=data;
//	temp->left=NULL;
//	temp->right=NULL;
//	return temp;
//}
//bool continuous(Node *root){
//	if(root==NULL)
//	return true;
//	if(root->left==NULL && root->right==NULL)
//	return true;
//	
//	if(root->left==NULL)
//	return abs(root->data - root->right->data)==1 && continuous(root->right);
//		
//	if(root->right=NULL)
//	return abs(root->data - root->left->data)==1 && continuous(root->left);
//		
//return abs(root->data - root->left->data)==1 && 
//	   abs(root->data - root->right->data)==1 && 
//	   continuous(root->left)&& 
//	   continuous(root->right);
//}
//int main(){
//	struct Node *root = push(3); 
//    root->left        = push(2); 
//    root->right       = push(4); 
//    root->left->left  = push(1); 
//    root->left->right = push(3); 
//    root->right->right = push(5); 
//    continuous(root)?  cout << "Yes" : cout << "No"; 
//    return 0;
//}
