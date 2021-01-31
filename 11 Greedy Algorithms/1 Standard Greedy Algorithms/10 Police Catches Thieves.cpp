#include <bits/stdc++.h>
using namespace std;
int Thieves_Caught(vector<char> &a,int n,int k)
{
	vector<int> P , T;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(a[i] == 'P')  P.push_back(i);
		
		else  T.push_back(i);
	}
	
	int ip = 0 , it = 0 , ans = 0;
	
	while(ip < P.size() && it < T.size())
	{
		if(T[it] < P[ip])
		{
			if(P[ip]-T[it] <= k)
			{
				ans++;  it++;  ip++;
			}
			else  it++;
		}
		else
		{
			if(T[it]-P[ip] <= k)
			{
				ans++;  it++;  ip++;
			}
			else  ip++;
		}
	}
	return ans;
}
int main()
{
	vector<char> a = {'P','P','T','T','P','T','P'};
	int n = a.size();
	int k = 2;
	
	cout<< Thieves_Caught(a,n,k) <<endl;
	
	return 0;
}
