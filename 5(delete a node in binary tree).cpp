#include <bits/stdc++.h> 
using namespace std; 
  
/* A binary tree node has key, pointer to left  
child and a pointer to right child */
struct Node { 
    int key; 
    struct Node *left, *right; 
}; 
  
/* function to create a new node of tree and  
return pointer */
struct Node* newNode(int key) 
{ 
    struct Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}; 
  
/* Inorder traversal of a binary tree*/
void inorder(struct Node* temp) 
{ 
    if (!temp) 
        return; 
    inorder(temp->left); 
    cout << temp->key << " "; 
    inorder(temp->right); 
} 
  
/* function to delete the given deepest node  
(d_node) in binary tree */
void deletDeepest(struct Node* root, 
                  struct Node* d_node) 
{ 
    queue<struct Node*> q; 
    q.push(root); 
  
    // Do level order traversal until last node 
    struct Node* temp; 
    while (!q.empty()) { 
        temp = q.front(); 
        q.pop(); 
        if (temp == d_node) { 
            temp = NULL; 
            delete (d_node); 
            return; 
        } 
        if (temp->right) { 
            if (temp->right == d_node) { 
                temp->right = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp->right); 
        } 
  
        if (temp->left) { 
            if (temp->left == d_node) { 
                temp->left = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp->left); 
        } 
    } 
} 
  
/* function to delete element in binary tree */
Node* deletion(struct Node* root, int key) 
{ 
    if (root == NULL) 
        return NULL; 
  
    if (root->left == NULL && root->right == NULL) { 
        if (root->key == key) 
            return NULL; 
        else
            return root; 
    } 
  
    queue<struct Node*> q; 
    q.push(root); 
  
    struct Node* temp; 
    struct Node* key_node = NULL; 
  
    // Do level order traversal to find deepest 
    // node(temp) and node to be deleted (key_node) 
    while (!q.empty()) { 
        temp = q.front(); 
        q.pop(); 
  
        if (temp->key == key) 
            key_node = temp; 
  
        if (temp->left) 
            q.push(temp->left); 
  
        if (temp->right) 
            q.push(temp->right); 
    } 
  
    if (key_node != NULL) { 
        int x = temp->key; 
        deletDeepest(root, temp); 
        key_node->key = x; 
    } 
    return root; 
} 
// Driver code 
int main() 
{ 
    struct Node* root = newNode(10); 
    root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->left->right = newNode(12); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8); 
  
    cout << "Inorder traversal before deletion : "; 
    inorder(root); 
  
    int key = 11; 
    root = deletion(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after deletion : "; 
    inorder(root); 
    return 0; 
} 
//#include<iostream>
//#include<queue>
//using namespace std;
//struct Node{
//	int data;
//	Node *left,*right;
//};
//   struct Node *push(int data){
//	Node* temp=new Node;
//	temp->data=data;
//	temp->left=NULL;
//	temp->right=NULL;
//	return temp;
//}
//void print(Node *root){
//	if(!root)
//		return ;
//	
//	cout<<root->data<<" ";
//	print(root->left);
//	print(root->right);
//}
//void dltdeepest(Node *root,Node *del){
//	queue<struct Node *> q;
//	q.push(root);
//	Node *temp;
//	while(!q.empty()){
//		temp=q.front();
//		q.pop();
//		if(temp==del){
//		temp=NULL;
//		delete(del);
//		return;
//	}
//		if(temp->right){
//			if(temp->right==del)
//			temp->right=NULL;
//			delete(del);
//			return;
//			}
//			else{
//				q.push(temp->right);
//			}
//		if(temp->left){
//			if(temp->left==del)
//			temp->left=NULL;
//			delete(del);
//			return;
//		}
//		else{
//			q.push(temp->left);
//		}	
//			
//		}
//	}
//
//Node *deletion(Node *root,int k){
//	if(root==NULL)
//	return NULL;
//	if(root->left==NULL && root->right==NULL){
//		if(root->data==k)
//		return NULL ;
//		else
//		return root;
//	}
//	queue<struct Node*> q;
//	q.push(root);
//	struct Node *temp;
//	struct Node *key_node=NULL;
//	while(!q.empty()){
//		temp=q.front();
//		q.pop();
//		if(temp->data==k)
//		key_node=temp;
//		
//		if(temp->left)
//			q.push(temp->left);
//			
//		
//		if(temp->right)
//			q.push(temp->right);
//		
//	}
//	if(key_node!=NULL){
//		int x=temp->data;
//		dltdeepest(root,temp);
//		key_node->data=x;
//	}
//	return root;
//}
//
//
//
//int main(){
//	struct Node *root=push(10);
//	root->left= push(20);
//	root->right= push(30);
//	root->left->left= push(40);
//	root->left->right= push(50);
//	root->right->left= push(60);
//	root->right->right= push(70);
//	print(root);
//	root=deletion(root,50);
//	cout<<endl;
//	print(root);
//	return 0;
//}
