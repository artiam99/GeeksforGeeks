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
bool check(vector<int> &a,int n)
{
	int l=intmin;
	int r=intmax;
	for(int i=1;i<n;i++)
	{
		if(a[i]<l || a[i]>r)
		return false;
		
		if(a[i] > a[i-1] )
		l=a[i-1]+1;
		
		else
		r=a[i-1]-1;
	}
	return true;
}
signed main()
{
	vector<int> a={500, 200, 90, 250, 100};
	int n=a.size();
	
	if(check(a,n))
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	
	return 0;
}
