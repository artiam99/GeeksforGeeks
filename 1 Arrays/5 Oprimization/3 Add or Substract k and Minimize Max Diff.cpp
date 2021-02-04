#include<bits/stdc++.h>
using namespace std;

int Max_Diff(vector<int> &a , int n , int k)
{
	sort(a.begin() , a.end());
        
    int res = a[n - 1] - a[0];
    
    int small = a[0] + k , big = a[n - 1] - k;
    
    for(int i = 0 ; i < n - 1 ; i++)
    {
        int add = max(a[i] + k , big);
        
        int sub = min(a[i + 1] - k , small);
        
        res = min(res , add - sub);
    }
    
    return res;
}

int main()
{
	vector<int> a = {1, 5, 8, 10};
	int n = a.size();
	int k = 2;
	
	cout << Max_Diff(a , n , k) << endl;
	
	return 0;
}
