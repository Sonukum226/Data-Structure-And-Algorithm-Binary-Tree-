//Trees: Unlike Arrays, Linked Lists, Stack and queues, which are linear data structures, trees are hierarchical data structures.
//Tree Vocabulary: The topmost node is called root of the tree. The elements that are directly under an element are called its children. The element directly above something is called its parent. For example, ‘a’ is a child of ‘f’, and ‘f’ is the parent of ‘a’. Finally, elements with no children are called leaves.
//
//      tree
//      ----
//       j    <-- root
//     /   \
//    f      k  
//  /   \      \
// a     h      z    <-- leaves 
//Why Trees?
//1. One reason to use trees might be because you want to store information that naturally forms a hierarchy. For example, the file system on a computer:
//
//file system
//-----------
//     /    <-- root
//  /      \
//...       home
//      /          \
//   ugrad        course
//    /       /      |     \
//  ...      cs101  cs112  cs113  
//2. Trees (with some ordering e.g., BST) provide moderate access/search (quicker than Linked List and slower than arrays).
//3. Trees provide moderate insertion/deletion (quicker than Arrays and slower than Unordered Linked Lists).
//4. Like Linked Lists and unlike Arrays, Trees don’t have an upper limit on number of nodes as nodes are linked using pointers.
//
//Main applications of trees include:
//1. Manipulate hierarchical data.
//2. Make information easy to search (see tree traversal).
//3. Manipulate sorted lists of data.
//4. As a workflow for compositing digital images for visual effects.
//5. Router algorithms
//6. Form of a multi-stage decision-making (see business chess).
//
//Binary Tree: A tree whose elements have at most 2 children is called a binary tree. Since each element in a binary tree can have only 2 children, we typically name them the left and right child.
//
//Binary Tree Representation in C++: A tree is represented by a pointer to the topmost node in tree. If the tree is empty, then value of root is NULL.
//A Tree node contains following parts.
//1. Data
//2. Pointer to left child
//3. Pointer to right child






//code here
#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
};
struct Node *node(int data){
	Node *temp=new Node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
}
void print(Node *root){
	if(root==nullptr)
		return;
	
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}
int main(){
	Node *root=node(1);
	root->left=node(2);
	root->right=node(3);
	root->left->left=node(4);
	root->left->right=node(5);
	
	root->right->left=node(6);
	root->right->right=node(7);
	print(root);
}
