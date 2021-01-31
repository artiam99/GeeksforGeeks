#include<bits/stdc++.h>
using namespace std;
#define NA -1

void Merge(int mPlusN[] , int n1 , int N[] , int n2)
{
	int n = n2 , m = n1 - n2;
	
	int i = 0 , j = n + m - 1 , k;
	
    for(int i = m + n - 1 ; i >= 0 ; i--)
    {
    	if(mPlusN[i] != -1)
   	    {
   	    	mPlusN[j] = mPlusN[i];
   	    	
			j--;
		}
    }
   
    i = n , j = 0 , k = 0;
   
    while(k < n + m)
    {
   	    if(i < m + n && mPlusN[i] <= N[j] || j == n)
   	    mPlusN[k++] = mPlusN[i++];
   	    
		else
		mPlusN[k++] = N[j++];
    }
   
    for(int i = 0 ; i < n + m ; i++)
    cout << mPlusN[i] << " ";
    cout << endl;
}

int main()
{
	int mPlusN[] = {2, 8, NA, NA, NA, 13, NA, 15, 20}; 
    int n1 = sizeof(mPlusN) / sizeof(mPlusN[0]);
    
	int N[] = {5, 7, 9, 25};
	int n2 = sizeof(N) / sizeof(N[0]); 
    
    Merge(mPlusN , n1 , N , n2);
   
	return 0;
}
