#include<iostream>
#include<map>
#include<queue>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
	int hd;
};
Node *push(int data){
	Node *tem=new Node;
	tem->data=data;
	tem->left=tem->right=NULL;
	return tem;
}
void topview(Node *root){
	if(root==NULL)
	return ;
	queue <Node*>q;
	map <int,int>m;
	
	int hd=0;
	root->hd=hd;
	q.push(root);
	while(q.size()){
		hd=root->hd;
		
		if(m.count(hd)==0)
		m[hd]=root->data;
		if(root->left){
			root->left->hd=hd-1;
			q.push(root->left);
		}
		if(root->right){
			root->right->hd=hd+1;
			q.push(root->right);
		}
		q.pop();
		root=q.front();
	}
	for(auto i=m.begin();i!=m.end();i++){
		cout<<i->second<<" ";
	}
}
int main(){
	Node* root = push(1); 
    root->left = push(2); 
    root->right = push(3); 
    root->left->right = push(4); 
    root->left->right->right = push(5); 
    root->left->right->right->right = push(6); 
    
    topview(root);
}
