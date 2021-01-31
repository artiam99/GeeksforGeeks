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
	vector<int> ht(n,-1);
	
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
			if(ht[p]!=-1)
			{
				h+=ht[p];
				break;
			}
			p=a[p];
			h++;
		}
		
		mx=max(h,mx);
		
		p=i;
		while(p!=-1)
		{
			if(ht[p]==-1)
			ht[p]=h--;
			else 
			break;
			p=a[p];
		}
	}
	return mx;
}
signed main()
{
    vector<int> parent1={-1, 0, 0, 0, 3, 1, 1, 2};
    vector<int> parent2={-1, 0, 1, 2, 3};

    cout<<height(parent1,parent1.size())<<endl;
    cout<<height(parent2,parent2.size())<<endl;

    return 0;
}
