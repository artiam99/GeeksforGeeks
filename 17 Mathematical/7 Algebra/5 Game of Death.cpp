#include <bits/stdc++.h> 
using namespace std; 

int josephus(int n , int k)
{
    int p = 0;
    
    for(int i = 2 ; i <= n ; i++)
    p = (k + p) % i;
    
	return p + 1;
}

int main()
{
	int N = 50 , K = 10;
	
	cout << josephus(N , K) << endl;
	
	return 0;
}

