#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
int k;
void pretopost(vector<int> &a,int n,int min_lim,int max_lim,int &preind)
{
	if( preind == n || (a[preind] < min_lim || a[preind] > max_lim) )
	return;

	int val=a[preind++];

    pretopost(a,n,min_lim,val,preind);

    pretopost(a,n,val,max_lim,preind);

    a[k++]=val;
}
signed main()
{
	k=0;
	vector<int> pre={40,30,35,80,100};
	int n=pre.size();
	
	cout<<"Preorder : ";  for(auto i:pre)  cout<<i<<" ";  cout<<endl;
	
	int preind=0;
	pretopost(pre,n,intmin,intmax,preind);
	
	cout<<"Postorder : ";  for(auto i:pre)  cout<<i<<" ";  cout<<endl;
	return 0;
}
