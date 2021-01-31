#include<bits/stdc++.h>
using namespace std;

void Next_Permutation(vector<int> &a , int n)
{
	if (n < 2) return;
	
    int i = n - 1;
    
    while (--i >= 0 && a[i] >= a[i+1])
	{}
    
    if(i == -1)
    {
        reverse(a.begin(),a.end());
     
	    return;
    }
    
    int j = i;
    
	while (++j < a.size() && a[j] > a[i])
	{}

	swap(a[j-1] , a[i]);
    
    reverse(a.begin() + i + 1 , a.end());
}

signed main()
{
	vector<int> a = {1, 5, 2, 4, 3};
	int n = a.size();
	
	Next_Permutation(a , n);
	
	for(auto i : a)
	cout << i << " ";
	cout << endl;
	
	return 0;
}
