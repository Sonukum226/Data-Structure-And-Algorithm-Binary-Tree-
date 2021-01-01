#include<iostream>
#include<vector>
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
void print(const vector<int> & v,int n){
	for(int j=n;j<v.size();j++)
		cout<<v[j]<<" ";
	   cout<<endl;
}
void printkpathutil(Node *root,vector<int> & path,int k){
	if(root==NULL)
	return;
	path.push_back(root->data);
	printkpathutil(root->left,path,k);
	printkpathutil(root->right,path,k);
	int f=0;
	for(int j=path.size()-1;j>=0;j--){
		f+=path[j];
		if(f==k)
		print(path,j);
	}
	path.pop_back();
}
void printkpath(Node *root,int k){
   vector<int> path;
   printkpathutil(root,path,k);	
  }
int main(){
	Node *root=push(1);
	root->left=push(3);
	root->left->left=push(2);
	root->left->right=push(1);
	root->right=push(-1);
	root->right->left=push(4);
	root->right->left->left=push(1);
	root->right->left->right=push(2);
	root->right->right=push(5);
	root->right->right->right=push(5);
	
	int k=5;
	printkpath(root,k);
	
	
}
