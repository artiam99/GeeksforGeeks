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
void postorderuntill(int pre[],int n,int &i,int l,int r,int &k)
{
	if(l>r || i==n || pre[i]<l || pre[i]>r)
	return;
	int val=pre[i++];
	
	postorderuntill(pre,n,i,l,val-1,k);
	postorderuntill(pre,n,i,val+1,r,k);
	
	pre[k++]=val;
}
void postorder(int pre[],int n)
{
	int i=0,k=0;
	postorderuntill(pre,n,i,INT_MIN,INT_MAX,k);
}
signed main()
{
	int pre[] = {40, 30, 35, 80, 100};
    int n = sizeof(pre) / sizeof(pre[0]);
	
	postorder(pre, n);
	
	for(int i=0;i<n;i++)
	cout<<pre[i]<<" ";
	cout<<endl;
    
    return 0;
}
