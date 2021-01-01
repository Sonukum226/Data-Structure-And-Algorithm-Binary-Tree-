#include<bits/stdc++.h>
using namespace std;
struct Node{
	char data;
	Node *left,*right;
};
Node *push(int data){
	Node *temp=new Node;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
int search(char a[],int st,int end,char value){
	for(int i=st;i<=end;i++){
		if(a[i]==value)
		return i;
	}
}
Node *buildtree(char in[],char pre[],int inst,int inend){
	static int preindex=0;
	cout<<preindex<<" ";
	if(inst>inend)
	return NULL;
	Node *tnode=push(pre[preindex++]);
	if(inst==inend)  // If only root is there 
	return tnode;
	int index=search(in,inst,inend,tnode->data);
	tnode->left=buildtree(in,pre,inst,index-1);
	tnode->right=buildtree(in,pre,index+1,inend);
	return tnode;
}
void printinorder(Node *root){
	if(root==NULL)
	return;
	printinorder(root->left);
	cout<<root->data<<" ";
	printinorder(root->right);
}
int main(){
	char in[]={'D','B','E','A','F','C'};
	char pre[]={'A','B','D','E','C','F'};
	int len=sizeof(in)/sizeof(in[0]);
	Node *root=buildtree(in,pre,0,len-1);
	cout<<"Inorder traversal of the constructed tree is\n";
	printinorder(root);
}
