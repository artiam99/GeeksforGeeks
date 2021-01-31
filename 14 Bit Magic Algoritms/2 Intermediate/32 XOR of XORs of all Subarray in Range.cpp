#include<bits/stdc++.h> 
using namespace std;
void PreProcess(vector<int> &a,int n,int XOR_ALT[])
{
	XOR_ALT[0] = a[0] , XOR_ALT[1] = a[1];
	
	for(int i = 2 ; i < n ; i++)
	XOR_ALT[i] = XOR_ALT[i-2] ^ a[i];
}
void AnsQueries(vector<int> &a,int n,vector<pair<int,int>> &Q,int q)
{
	int XOR_ALT[n];
	
	PreProcess(a,n,XOR_ALT);
	
	for(int i = 0 ; i < q ; i++)
	{
		int l = Q[i].first - 1 , r = Q[i].second - 1;
		
		if((r - l + 1) % 2 == 0)  cout << 0 << endl;  // All Array elements apper even number of times  ... N * 1 + (N-1) * 2 + ... + (N-(N-1)) * N  .. Sum of all Subarray Formula
		
		else  cout << (XOR_ALT[r] ^ ((l < 2) ? 0 : XOR_ALT[l-2])) << endl;  // Only elements in Odd index appear
	}
}
int main() 
{
	vector<int> a = {1, 2, 3, 4, 5};
	int n = a.size();
	
	vector<pair<int,int>> Q = {{1 , 2} , {1 , 3} , {2 , 4}};
	int q = Q.size();
	
	AnsQueries(a,n,Q,q);
	
	return 0;
}

