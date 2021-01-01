//Binaery tree
#include<iostream>
using namespace std;

struct Binary{
	int data;
	Binary *left,*right;
	Binary(int data):data{data},left{nullptr},right{nullptr}{}
};

void print_dfs(Binary *root){
	if(root ==nullptr)
	return;
	cout<<root->data<<" ";
	print_dfs(root->left);
	print_dfs(root->right);
}
int main(){
	//nodes consruction
	Binary *root=new Binary(1);
	Binary *left=new Binary(5);
	Binary *right=new Binary(4);
	Binary *left_left=new Binary(6);
	Binary *left_right=new Binary(8);
	Binary *right_left=new Binary(12);
	Binary *right_right=new Binary(20);
	
	//connecting tree
	root->left=left;
	root->right=right;
	left->left=left_left;
	 left->right=left_right;
	right->left=right_left;
	right->right=right_right;
	//printing
	print_dfs(root);
	
}
