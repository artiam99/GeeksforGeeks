#include<bits/stdc++.h>
using namespace std;
void Rec(vector<int> &a,int n,int i,vector<int> &a1,vector<int> &a2,vector<int> &ans1,vector<int> &ans2,int &mn)
{
	if(i == n)
	{
		if(abs(a1.size() - a2.size()) < 2)
		{
			int sum1 = accumulate(a1.begin(),a1.end(),0);
			int sum2 = accumulate(a2.begin(),a2.end(),0);
			
			if(abs(sum1-sum2) < mn)
			{
				mn = abs(sum1-sum2);
				
				ans1 = a1;
				
				ans2 = a2;
			}
		}
		return;
	}
	
	a1.push_back(a[i]);
	Rec(a,n,i+1,a1,a2,ans1,ans2,mn);
	a1.pop_back();
	
	a2.push_back(a[i]);
	Rec(a,n,i+1,a1,a2,ans1,ans2,mn);
	a2.pop_back();
	
}
void TugofWar(vector<int> &a,int n)
{
	vector<int> a1 , a2 , ans1 , ans2;
	
	int mn = INT_MAX;
	
	Rec(a,n,0,a1,a2,ans1,ans2,mn);
	
	for(auto i:ans1)
	cout<< i << " ";
	cout<< endl << endl;
	
	for(auto i:ans2)
	cout<< i << " ";
	cout<< endl << endl;
	
	cout<< "Diff : " << mn << endl;
}
signed main()
{
	vector<int> a = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
	int n = a.size();
	
	TugofWar(a,n);
	
	return 0;
}
