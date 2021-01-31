#include<bits/stdc++.h>
using namespace std;
int Evaluate(vector<int> &a,int n,int x)
{
	int ans = 0;
	
	for(int i = n - 1 ; i >= 0 ; i--)
	{
		ans *= x;
		
		ans += a[i];
	}
	
	return ans;
}
int main()
{
	vector<int> a = {1, 0, 3, 2}; // 1 * x ^ 0 + 0 * x ^ 1 + 3 * x ^ 2 + 2 * x ^ 3
	int n = a.size();
	
	int x = 10;
	
	cout << Evaluate(a,n,x) << endl;
 
    return 0;
}
