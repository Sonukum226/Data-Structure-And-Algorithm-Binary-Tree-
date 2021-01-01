//Binary tree array implementation
#include<iostream>
using namespace std;
char tree[10];
void root(char key){
	if(tree[1]!='\0') cout<<"Tree has root";
	else{
		tree[1]=key;
	}
	
}
void set_l(char key,int parent){
	if(tree[parent]=='\0')cout<<"\n can't set child at "<<(parent*2)+1<<" ,no parent found";
	else{
		tree[parent*2]=key;
	}
}
void set_r(char key,int parent){
	if(tree[parent]=='\0')cout<<"\ncan't set child at "<<(parent*2)+2<<" ,no parent found";
	else
	tree[parent*2+1]=key;
}
void print(){
	for(int i=0;i<10;i++){
		cout<<tree[i]<<" ";
	}
}
int main(){
	root('A');
	set_l('B',1);
	set_r('C',1);
	set_l('D',2);
	set_r('E',2);
	set_r('F',3);
	print();
	
}
