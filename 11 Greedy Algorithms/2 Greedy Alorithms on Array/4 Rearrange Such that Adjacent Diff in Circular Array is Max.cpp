#include<bits/stdc++.h>
using namespace std;
int Max_Sum(vector<int> &a,int n)
{
	sort(a.begin(),a.end());
	    
    vector<int> b(n);
    
    int l = 0 , r = n-1;
    
    int i = 0;
    while(l<=r)
    {
        if(l != r)
        b[i++] = a[l++];
        b[i++] = a[r--];
    }
    int sum = 0;
    
    for(int j = 0 ; j < n ; j++)
    sum += abs(b[j]-b[(j+1)%n]);
    
    return sum;
}
signed main()
{
	vector<int> a = {4, 2, 1, 8};
	int n = a.size();
	
	cout<< Max_Sum(a,n) << endl;
	
	return 0;
}
