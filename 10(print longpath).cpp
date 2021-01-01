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

vector<int> printlongpath(Node *root){
	if(root==NULL){
	vector<int> temp={};
	return temp;
	}
	cout<<root->data;
	vector<int> left=printlongpath(root->left);
	vector<int> right=printlongpath(root->right);
	
	
	if(left.size()>right.size()){
		left.push_back(root->data);
	}
	else{
		right.push_back(root->data);
	}
	
	return (left.size()>right.size() ? left :right);
}


int main(){
	 Node *root=push(1);
	 root->left=push(2);
	 root->right=push(3);
	 root->left->left=push(4);
	 root->left->right=push(5);
	 root->left->right->right=push(6);
	 
	 vector<int> out=printlongpath(root);
	 int n=out.size();
	 cout<<out[n-1];
	 int sum=0;
	 for(int i=n-2;i>=0;i--){
	 	cout<<"->"<<out[i];
	 	sum+=out[i];
	 }
	 sum=sum+out[n-1];
	 cout<<endl<<sum;
}

