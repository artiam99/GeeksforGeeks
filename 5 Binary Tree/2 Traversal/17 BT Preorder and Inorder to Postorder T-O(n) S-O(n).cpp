#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
void postorder(vector<int> &pre,int &preind,vector<int> &in,map<int,int> &m,int lin,int rin,vector<int> &post)
{
	if(lin>rin)
	return;
	
	int i=m[pre[preind++]];
	
	postorder(pre,preind,in,m,lin,i-1,post);
	
	postorder(pre,preind,in,m,i+1,rin,post);
	
	post.push_back(in[i]);
}
signed main()
{
	vector<int> pre={1,2,4,5,3,6};vector<int> in={4,2,5,1,3,6};vector<int> post;
	int n=pre.size();
	
	map<int,int> m;  for(int i=0;i<n;i++)  m[in[i]]=i;
	
	cout<<"Preorder : ";  for(auto i:pre)  cout<<i<<" ";  cout<<endl;
	
	cout<<"Inorder : ";  for(auto i:in)  cout<<i<<" ";  cout<<endl;
	
	int preind=0;// if preorder to anytind is given use this method
	postorder(pre,preind,in,m,0,n-1,post);
	
	cout<<"Postorder : ";  for(auto i:post)  cout<<i<<" ";  cout<<endl;
	
	return 0;
}


