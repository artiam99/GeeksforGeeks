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
bool check(vector<int> &a)
{	
	int n=a.size();
	
	for(int i=0;i<n;i++)
	{
		if(i*2+1<n && a[i]>a[i*2+1])
		return false;
		
		if(i*2+2<n && a[i]>a[i*2+2])
		return false;
	}
	
	return true;
}
signed main()
{
	vector<int> lvl={10,15,14,25,30};// Level Order Traversal is given ....if it's a heap then is's a complete binary tree and Min-Heap so parent is smaller than children
    
    if(check(lvl))
    cout<<"Yes";
    else
    cout<<"No";
    cout<<endl;
	return 0;
}
