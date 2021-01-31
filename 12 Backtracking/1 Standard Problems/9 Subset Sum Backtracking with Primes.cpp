#include<bits/stdc++.h>
using namespace std;
void Rec(vector<int> &a,int i,int S,int N,int sum,vector<int> &ans)
{
	if(sum == S && ans.size() == N)
	{
		for(auto i : ans)
		cout<< i << " ";
		
		cout<< endl;
		
		return;
	}
	
	if(sum > S || i == a.size())  return;
	
	ans.push_back(a[i]);
	Rec(a , i + 1 , S , N , sum + a[i] , ans);
	ans.pop_back();
	
	Rec(a , i + 1 , S , N , sum , ans);
}
void SubsetSum(int N,int P,int S)
{
	vector<int> a;
	
	bool Num[S+1];  memset(Num,true,sizeof(Num));
	
	Num[0] = Num[1] = false;
	
	for(int i = 2 ; i <= S ; i++)  // Seive of Eratosthenes ... O(N Log Log N)
	if(Num[i])
	{
		if(i > P)
		a.push_back(i);
		
		for(int j = 2 ; i * j <= S ; j++)
		Num[i*j] = false;
	}
	
	vector<int> ans;
	
	Rec(a,0,S,N,0,ans);
}
signed main()
{
	int N = 4, P = 3, S = 54;
	
	SubsetSum(N,P,S);
	
	return 0;
}
