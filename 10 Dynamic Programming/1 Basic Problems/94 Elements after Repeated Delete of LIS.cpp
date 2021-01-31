#include<bits/stdc++.h>
using namespace std;
vector<int>findlis(vector<int> &a,int n)
{
	vector<vector<int>> l(n);
	
	l[0].push_back(a[0]);
	
	int i,j;
	
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		if(a[i]>a[j])
		l[i]=l[j];

		l[i].push_back(a[i]);
	}
	
	int sz=0;
	
	vector<vector<int> >::iterator it;
	
	vector<int>ans;
	
	for(it=l.begin();it!=l.end();it++)
	{
		vector<int>vec=*it;
		if(vec.size()>sz)
		{
			ans=vec;
			sz=vec.size();
		}
	}
	
	return ans;
}
void Minimize(vector<int> &a,int n)
{
	vector<int>lis;
	
	int i;

	do
	{
		lis=findlis(a,a.size());
		
		if(lis.size()<2)
		break;
		
		for(i=0;i<a.size() && lis.size();i++)
		if(a[i]==lis[0])
		{
			a.erase(a.begin()+i);
			i--;
			lis.erase(lis.begin());
		}
		
	}while(a.size());
	
	for(i=0;i<a.size();i++)
	cout<<a[i]<<" ";
	
	if(a.size()==0)
	cout<<-1;
	
	cout<<endl;
}
signed main()
{
	vector<int> a = {1, 2, 5, 3, 6, 4, 1};
	int n = a.size();
	
	Minimize(a,n);
	
	return 0;
}
