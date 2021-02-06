#include<bits/stdc++.h>
using namespace std;

void Rearrange(vector<int> &a , int n)
{
	int psi = 0 , ngi = 1;
	
	while(psi < n && ngi < n)
	{
		while(psi < n && a[psi] >= 0)
		psi += 2;
		
		while(ngi < n && a[ngi] < 0)
		ngi += 2;
		
		if(psi < n && ngi < n)
		swap(a[psi] , a[ngi]);
	}
	
	if(psi >= n && ngi < n)  // All even indices have positive elements ... So Push all negative elements to begining form all odd indices
	{
		int ngi2 = ngi;
		
		while(ngi2 < n)
		{
			while(ngi2 < n && a[ngi2] >= 0)
			ngi2 += 2;
			
			if(ngi2 < n)
			swap(a[ngi] , a[ngi2]);
			
			ngi += 2;
		}
	}
	
	if(ngi >= n && psi < n)  // All odd indices have negative elements ... So Push all positive elements to begining form all even indices 
	{
		int psi2 = psi;
		
		while(psi2 < n)
		{
			while(psi2 < n && a[psi2] < 0)
			psi2 += 2;
			
			if(psi2 < n)
			swap(a[psi] , a[psi2]);
			
			psi += 2;
		}
	}
}

signed main()
{
	vector<int> a = {5, 6, -1, 2, 3, -4};
	int n = a.size();
	
	Rearrange(a , n);

	for(auto i : a)
	cout << i << " ";
	cout << endl;

	return 0;
}
