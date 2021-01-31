#include<bits/stdc++.h>
using namespace std;
#define int long long
void check(vector<int> &deg,int n)
{
	int sum=accumulate(deg.begin(),deg.end(),0);
	
	if(sum == 2*(n-1))
	cout<<"Tree"<<endl;
	else
	cout<<"Graph"<<endl;
}
signed main()
{
	vector<int> deg= {2,3,1,1,1};
	int n=deg.size();
	
	check(deg,n);
	
	deg={2,2,2};
	n=deg.size();
	
	check(deg,n);
	
	return 0;
}
