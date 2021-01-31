#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
void inorderindexpair(vector<int> &a,int n,vector<pair<int,int>> &in,int ind)
{
	static int i=0;
	
	if(ind>=n)
	return;
	
	inorderindexpair(a,n,in,ind*2+1);
	
	in.push_back({a[ind],i++});
	
	inorderindexpair(a,n,in,ind*2+2);
}
int Number_of_swap(vector<pair<int,int>> &in,int n)
{
	int c=0;
	
	sort(in.begin(),in.end());
	
	for(int i=0;i<n;i++)
	{
		if(in[i].second==i)
		continue;
		
		swap(in[i].second,in[in[i].second].second);
		i--;
		
		c++;
	}
	return c;
}
signed main()
{
	vector<int> a={5,6,7,8,9,10,11};
	int n=a.size();
	
	vector<pair<int,int>> in;
	inorderindexpair(a,n,in,0);
	
	cout<<Number_of_swap(in,n);
	
	
	return 0;
}
