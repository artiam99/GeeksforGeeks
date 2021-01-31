#include <bits/stdc++.h>
using namespace std;
double Max_Vol(vector<int> &a,int n,double p)
{
	sort(a.begin(),a.end());
	
	double curr = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		int j = n-i;
		
		curr -= curr*p;
				
		curr += a[i];
	}
	return curr;
}
int main()
{
	vector<int> a = {4, 2, 151, 15, 1, 52, 12};
	int n = a.size();
	
	double p = 0.1;
	
	cout<< Max_Vol(a,n,p) <<endl;
	
	return 0;
}
