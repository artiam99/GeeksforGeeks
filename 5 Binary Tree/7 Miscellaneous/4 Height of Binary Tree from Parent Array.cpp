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
int height(vector<int> &a,int n)
{
	vector<int> leaf(n);
	iota(leaf.begin(),leaf.end(),0);
	
	for(auto i:a)
	{
		if(i!=-1)
		leaf[i]=-1;
	}
	
	int mx=0;
	for(auto i:leaf)
	{
		int h=0;
		
		int p=i;
		while(p!=-1)
		{
			p=a[p];
			h++;
		}
		mx=max(h,mx);
	}
	return mx;
}
signed main()
{
    vector<int> parent1={1,5,5,2,2,-1,3};
    vector<int> parent2={-1,0,0,1,1,3,5};

    cout<<height(parent1,parent1.size())<<endl;
    cout<<height(parent2,parent2.size())<<endl;

    return 0;
}
