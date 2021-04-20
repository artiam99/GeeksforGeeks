#include<bits/stdc++.h>
using namespace std;

int Minimum_Painters(int a[] , int n , int x)  // Minimum Painters Required to paint the whole wall in x time
{
    int curr = 0 , p = 1;
    
    for(int i = 0 ; i < n ; i++)
    {
        curr += a[i];
        
        if(curr > x)
        {
            curr = a[i];
            
            p++;
        }
    }
    
    return p;
}

int Min_Time(int a[] , int n , int k)
{
	int l = *max_element(a , a + n) , r = accumulate(a , a + n , 0);
        
    if(n <= k)
    return l;
    
    while(l <= r)
    {
        int m = l + (r - l) / 2;

        if(Minimum_Painters(a , n , m) <= k) // K painters can easily paint in lesser time ... so decrement r
        r = m - 1;
        
        else
        l = m + 1;
    }
    
    return l;
}

int main()
{
	int a[] = {12, 34, 67, 90};
	int n = sizeof a / sizeof a[0];
	int k = 2;

	cout << "Minimum Time = " << Min_Time(a , n , k) << endl;
	
	return 0;
}

