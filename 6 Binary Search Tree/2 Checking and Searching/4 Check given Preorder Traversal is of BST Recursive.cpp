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
void checkuntill(int pre[],int n,int l,int r,int &i)
{
	if(l>r || i==n || pre[i]<l || pre[i]>r)
	return;
	
	int val=pre[i++];
	checkuntill(pre,n,l,val-1,i);
	checkuntill(pre,n,val+1,r,i);
}
bool check(int pre[],int n)
{
	int i=0;
	checkuntill(pre,n,INT_MIN,INT_MAX,i);
	
	return (i==n);
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
