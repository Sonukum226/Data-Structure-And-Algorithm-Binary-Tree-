#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> vec;
void dfs(int val){
	cout<<val<<" ";
	for(const int &node:vec[val]){
		dfs(node); //function recurrision
	}
}
int main(){
	int u,v,n,e;
	cin>>n>>e;
	vec.resize(n+1);
	while(e--){
		cin>>u>>v;
		vec[u].push_back(v);
	}
	dfs(1);
}
