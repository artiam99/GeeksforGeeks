#include<bits/stdc++.h>
using namespace std;
int Pref_Sum(int *BIT , int ind)
{
	int sum = 0 , i = ind + 1;
	
	while(i != 0)
	{
		sum += BIT[i];
		
		i &= (i - 1);
	}
	
	return sum;
}
void Update(int *BIT , int n , int ind , int x , int ai)
{	
	int diff = x - ai;
	
	int i = ind + 1;
	
	while(i <= n)
	{
		BIT[i] += diff;
		
		i += (i & -i);
	}
}
int* Construct(vector<int> &a , int n)
{
	int *BIT = new int[n+1];
	
	memset(BIT , 0 , sizeof(int) * (n+1));
	
	for(int i = 0 ; i < n ; i++)
	Update(BIT , n , i , a[i] , 0);
	
	return BIT;
}
signed main()
{
    vector<int> a = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};  // Binary index tree can strore only prefix sum nothing else
    int n = a.size();
    
    int *BIT = Construct(a , n);
    
    cout << Pref_Sum(BIT , 5) << endl;
    
    Update(BIT , n , 3 , 6 , a[3]);
    
    cout << Pref_Sum(BIT , 5) << endl;
    
    return 0;
}
