#include<bits/stdc++.h>
using namespace std;
void Partition(int N)
{
	int sum = N * (N + 1) / 2;
	
	int s1 = sum/2;
	
	vector<int> S1 , S2;
	
	for(int i = N ; i >= 1 ; i--)
	{
		if(s1 >= i)
		{
			s1 -= i;
			
			S1.push_back(i);
		}
		else
		S2.push_back(i);
	}
	for(auto i:S1)
	cout<< i << " ";
	cout<< endl;
	
	for(auto i:S2)
	cout<< i << " ";
	cout<< endl;
}
signed main()
{
	int N = 7;
	
	Partition(N);
    
    return 0;
}
