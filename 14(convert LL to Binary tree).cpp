#include<iostream>
#include<queue>
using namespace std;
struct lNode{
	int data;
	lNode *next;
};
struct bNode{
	int data;
	bNode *left,*right;
};
void push(lNode **head,int data){
	lNode *temp=new lNode;
	temp->data=data;
	temp->next=*head;
	*head=temp;
}
bNode *newbnode(int data){
	bNode *temp=new bNode;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
void convertlist2binary(lNode *head,bNode* &root){   // main concept
	queue<bNode *>q;
	root=newbnode(head->data);
	q.push(root);
	head=head->next;
	while(head){
		bNode *parent=q.front();
		q.pop();
		bNode *left=NULL;
		bNode *right=NULL;
		left=newbnode(head->data);
		q.push(left);
		head=head->next;
		if(head){
			right=newbnode(head->data);
			q.push(right);
			head=head->next;
		}
		parent->left=left;
		parent->right=right;
	}
}
void traversetree(bNode *root){
	if(root){
	cout<<root->data<<" ";
	traversetree(root->left);
	traversetree(root->right);
} 
}
void printlist(lNode *head){
	while(head){
		cout<<head->data<<" ";
		head=head->next;
	}
}
int main(){
	lNode *head=NULL;
	bNode *root;
	push(&head,36);
	push(&head,30);
	push(&head,25);
	push(&head,15);
	push(&head,12);
	push(&head,10);
	convertlist2binary(head,root);
	cout<<"List::";
	printlist(head);
	cout<<endl<<"Tree::";
	traversetree(root);
	
}
