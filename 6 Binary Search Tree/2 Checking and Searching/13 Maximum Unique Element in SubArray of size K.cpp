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
void find_max(int a[],int n,int k)
{
	unordered_map<int,int> m;
	set<int> s;
	
	for(int i=0;i<=n;i++)
	{
		if(i>=k)
		{
			if(s.size())
			cout<<*s.rbegin()<<" ";
			
			else
			cout<<-1<<" ";			
			
			if(i==n)
			break;
			
			m[a[i-k]]--;
			
			if(m[a[i-k]]==0 && s.find(a[i-k])!=s.end())
			s.erase(a[i-k]);
			
			else if(m[a[i-k]]==1)
			s.insert(a[i-k]);
		}
		m[a[i]]++;
		
		if(m[a[i]]>1 && s.find(a[i])!=s.end())
		s.erase(a[i]);
		
		else if(m[a[i]]==1)
		s.insert(a[i]);
	}
}
signed main()
{
	int a[] = {1, 2, 2, 3, 3};
    int n = sizeof(a) / sizeof(a[0]);
    
	int k = 3;
    
	find_max(a, n, k);
    
	return 0;
}
