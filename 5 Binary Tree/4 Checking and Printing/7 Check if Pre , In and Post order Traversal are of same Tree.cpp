#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Node
{
	int data;
	Node* left;
	Node* right;
    Node(int x)
	{
		data=x;
		left=right=NULL;
	}
};
int checkuntill(vector<int> &pre , int &ind , vector<int> &in , int l , int r ,
    unordered_map<int,int> &inm , vector<int> &post , unordered_map<int,int> &postm ,bool &res)
{
	if(l>r)
	return -1;
	
	int root=pre[ind];
	
	int i=inm[pre[ind++]];
	
	int leftchild = checkuntill(pre,ind,in,l,i-1,inm,post,postm,res);
	
	int rightchild = checkuntill(pre,ind,in,i+1,r,inm,post,postm,res);
	
	if((leftchild!=-1 && postm[root]<=postm[leftchild])||(rightchild!=-1 && postm[root]<=postm[rightchild]))
	res=0;
	
	return root;
}
bool check(vector<int> &pre,vector<int> &in,vector<int> &post)
{
	int n=in.size();
	
	unordered_map<int,int> inm;
	for(int i=0;i<n;i++)
	inm[in[i]]=i;
	
	unordered_map<int,int> postm;
	for(int i=0;i<n;i++)
	postm[post[i]]=i;
	
	int ind=0;
	bool res=1;
	checkuntill(pre,ind,in,0,n-1,inm,post,postm,res);
	return res;
}
signed main()
{
	vector<int> pre = {1,2,4,5,3};
    vector<int> in = {4,2,5,1,3};
    vector<int> post = {4,5,2,3,1};
    
    if(check(pre,in,post))
    cout<<"Yes";
    else
    cout<<"No";
    cout<<endl<<endl;
	return 0;
}
