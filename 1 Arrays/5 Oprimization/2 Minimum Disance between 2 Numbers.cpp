#include<bits/stdc++.h>
using namespace std;

long long Min_Dist(long long arr[] , long long n , long long x , long long y)
{
    long long p = -1 , s = 100001;
   
    for(long long i = 0 ; i < n ; i++)
    {
        if(arr[i] == x || arr[i] == y)
        {
            if(p != -1 && arr[p] != arr[i])
            s = min(s , i - p);
            
			p=i;
        }
    }
    
    if(s == 100001)
    s = -1;
    
    return s;
}
int main()
{
	long long a[] = {1, 2, 3, 4, 6, 3, 6, 2};
	long long n = 4;
	
	cout << Min_Dist(a , n , 1 , 2) << endl;
	
	return 0;
}
