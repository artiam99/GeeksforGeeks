#include <bits/stdc++.h>
using namespace std;
int Max_Time(vector<int> &M,vector<int> &H,int n)
{
	sort(M.begin(),M.end());
	sort(H.begin(),H.end());
	
	int mx = INT_MIN;
	
	for(int i = 0 ; i < n ; i++)
	mx = max(mx , abs(M[i]-H[i]));
	
	return mx;
}
int main()
{
	vector<int> M = {1, 4, 8};
	vector<int> H = {0, 6, 15};
	int n = M.size();
	
	cout<< Max_Time(M,H,n) <<endl;
	
	return 0;
}
