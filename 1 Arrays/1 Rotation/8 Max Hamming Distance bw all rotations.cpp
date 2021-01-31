#include <bits/stdc++.h>
using namespace std;

int Max_Hamming_Dist(vector<int> &a , int n)
{
	vector<int> b(2*n);
    
    for(int i = 0 ; i < n ; i++)
    b[i] = a[i];
    
    for(int i = 0 ; i < n ; i++)
    b[i+n] = a[i];
    
    int mx = std::numeric_limits<int>::min();
    
    for(int i = 0 ; i < n ; i++)
    {
    	int c = 0;
    	
    	for(int j = i ; j < i + n ; j++)
    	if(b[j] != a[j-i])
    	c++;
		
		mx = max(mx , c);
	}
	
	return mx;
}

int main()
{
    vector<int> a = {0, 2, 2, 4, 8};
    int n = a.size();
    
    cout << Max_Hamming_Dist(a , n) << endl;
	
	return 0;
}
