#include<bits/stdc++.h> 
using namespace std;
bool Check(vector<int> &a,int n)
{
	for(int i = 0 ; i < 31 ; i++)
	{
		int ans = (~0 ^ INT_MIN);
		
		for(int j = 0 ; j < n ; j++)
		if(a[j] & (1 << i))
		ans &= a[j];
		
		if((ans & (ans -1)) == 0)  return true;
	}
	return false;
}
int main() 
{
	vector<int> a = {20, 13, 15, 7, 13};
	int n = a.size();
	
	if(Check(a,n))  cout << "YES" << endl;
	
	else  cout << "NO" << endl;
	
	return 0;
}

