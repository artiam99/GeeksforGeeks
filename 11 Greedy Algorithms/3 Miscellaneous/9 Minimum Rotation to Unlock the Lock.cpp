#include<bits/stdc++.h>
using namespace std;
int Min_Rot(vector<int> &a,vector<int> &b,int n)
{
	int rot = 0;
	
	for(int i = 0 ; i < n ; i++)
	rot += min(max(a[i],b[i]) - min(a[i],b[i]) , 10 + min(a[i],b[i]) - max(a[i],b[i]));
	
	return rot;
}
signed main()
{
	vector<int> a = {8, 6, 4};
	vector<int> b = {2, 3, 7};
	int n = a.size();
	
	cout<< Min_Rot(a,b,n) <<endl;
    
    return 0;
}
