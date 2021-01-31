#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
void pretopost(vector<int> &a,int l,int r)
{
	if(l>=r)
    return;
    int c=a[l];
    for(int j=l;j<r;j++)
    a[j]=a[j+1];
    a[r]=c;
    int i=l;
    while(a[i]<a[r]&&i<r)
    i++;
    pretopost(a,l,i-1);
    pretopost(a,i,r-1);
}
signed main()
{
	vector<int> pre={40,30,35,80,100};
	int n=pre.size();
	cout<<"Preorder : ";
	for(auto i:pre)
	cout<<i<<" ";cout<<endl;
	pretopost(pre,0,n-1);
	cout<<"Postorder : ";
	for(auto i:pre)
	cout<<i<<" ";cout<<endl;
	return 0;
}
