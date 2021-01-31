#include<bits/stdc++.h> 
using namespace std;
long long Sum_of_AND_Pair(vector<long long> &a,int n)
{
	long long bit[64];  memset(bit,0,sizeof(bit));
        
    long long sum = 0;
    
    long long one = 1;
    
    for(int i = 0 ; i < 64 ; i++)
    {   
        for(int j = 0 ; j < n ; j++)
        if(((one << i) & a[j]))
        bit[i]++;
    
        sum += (one << i) * ((bit[i] * (bit[i] - 1)) >> 1);
    }
    return sum;
}
int main() 
{ 
	vector<long long> a = {5, 10, 15};
	int n = a.size();
	
	cout << Sum_of_AND_Pair(a,n) << endl;
	
	return 0; 
} 

