#include<bits/stdc++.h>
using namespace std;
int Min_Cost(vector<int> &a,int n)
{
	return (n-1) * *min_element(a.begin(),a.end());
}
signed main()
{
	vector<int> a = {4, 3, 2, 6};
	int n = a.size();
	
	cout<< Min_Cost(a,n) << endl;
    
    return 0;
}
