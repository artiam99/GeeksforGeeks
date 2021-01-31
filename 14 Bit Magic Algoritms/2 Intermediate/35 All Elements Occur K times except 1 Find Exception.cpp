#include<bits/stdc++.h> 
using namespace std;
int Find(vector<int> &a,int n,int k)
{
	int bit[32];  memset(bit,0,sizeof(bit));
	
	for(int i = 0 ; i < 32 ; i++)
	for(int j = 0 ; j < n ; j++)
	if((a[j] & (1 << i)))
	bit[i]++;
	
	int res = 0;
	
	for(int i = 0 ; i < 32 ; i++)
	res += (bit[i] % k) * (1 << i);
	
	return res;
}
int main() 
{
	vector<int> a = {7, 7, 6, 7, 5, 6, 6};
	int n = a.size();
	int k = 3;
	
	cout << Find(a,n,k) << endl;
	
	return 0;
}

