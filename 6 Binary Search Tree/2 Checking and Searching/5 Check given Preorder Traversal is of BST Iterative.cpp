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

bool check(int pre[],int n)
{
	stack<int> st;
	
	int root=INT_MIN;
	
	for(int i=0;i<n;i++)
	{
		if(root > pre[i])
		return false;
		
		while(st.size() && st.top()<pre[i])
		{
			root=st.top();
			st.pop();
		}
		
		st.push(pre[i]);
	}
	
	return true;
}
signed main()
{
	int pre[] = {40, 30, 35, 80, 100};
    int n = sizeof(pre) / sizeof(pre[0]);
	
	if(check(pre, n))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    
    return 0;
}
