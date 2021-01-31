#include<bits/stdc++.h>
using namespace std;
bool Rec(bool a[],int ans[],int n)
{
	int j = 0;
	for(; j < 2*n ; j++)
	if(ans[j] == -1)
	break;
	
	if(j == 2*n)
	{
		for(int i = 0 ; i < 2*n ; i++)
		cout<< ans[i] << " ";
		
		return true;
	}
	
	for(int i = 1 ; i <= n ; i++)
	if(a[i] && j + i + 1 < 2*n && ans[j + i + 1] == -1)
	{
		ans[j] = ans[j + i + 1] = i;
		
		a[i] = false;
		
		if(Rec(a,ans,n))
		return true;
		
		a[i] = true;
		
		ans[j] = ans[j + i + 1] = -1;
	}
	
	return false;
}
void Fill(int n)
{
	int ans[2*n];  memset(ans,-1,sizeof(ans));
	
	bool a[n+1];  memset(a,true,sizeof(a));
	
	Rec(a,ans,n);
}
signed main()
{
	int N = 11;
	
	Fill(N);

	return 0;
}
