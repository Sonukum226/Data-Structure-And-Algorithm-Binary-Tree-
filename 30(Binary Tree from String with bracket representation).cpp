#include<iostream>
#include<string>
#include<stack>
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
	if(root==NULL)
	return ;
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}
int findindex(string str,int st,int e){
	if(st>e)
	return -1;
	stack<char> s;
	for (int i = st; i <= e; i++) { 
  
        // if open parenthesis, push it 
        if (str[i] == '(') 
            s.push(str[i]); 
        // if close parenthesis 
        else if (str[i] == ')') { 
            if (s.top() == '(') { 
                s.pop(); 
  
                // if stack is empty, this is  
                // the required index 
                if (s.empty()) 
                    return i; 
            } 
        } 
    } 
    return -1; 
} 

Node *tree(string str,int s,int e){
	//bae case
	if(s>e)
	return NULL;
	Node *root=push(str[s]-'0');
	int index=-1;
	if(s+1<=e && str[s+1]=='(')
    index=findindex(str,s+1,e);
	if(index != -1){
	root->left=tree(str,s+2,index-1);
	root->right=tree(str,index+2,e-1);
	}
	return root;
}
int main(){
	string str= "4(2(3)(1))(6(5))";
	Node *root=tree(str,0,str.length()-1);	
	print(root);
}
