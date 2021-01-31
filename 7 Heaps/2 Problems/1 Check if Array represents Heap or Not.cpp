#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
bool check(vector<int> &a,int n)
{
	for(int i=n/2-1;i>=0;i--)// n/2-1 is the lase Node that has at least one children
	{
		int l=i*2+1;
		int r=i*2+2;
		
		if(l<n && a[i] < a[l])
		return false;
		
		if(r<n && a[i] <a[r])
		return false;
	}
	return true;
}
signed main()
{
	vector<int> a={90,15,10,7,12,2};
	int n=a.size();
	
	if(check(a,n))
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	
	return 0;
}
