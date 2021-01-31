#include<bits/stdc++.h> 
using namespace std;
int Count_Pairs(vector<int> &a,int n)
{
	int freq[1025];  memset(freq,0,sizeof(freq));
	
	for(int i = 0 ; i < n ; i++)
	{
		int num = a[i] , digit = 0;
		
		while(num)
		{
			digit |= (1 << (num % 10));
			
			num /= 10;
		}
		
		freq[digit]++;
	}
	
	int ans = 0;
	
	for(int i = 1 ; i < 1025 ; i++)
	{
		ans += ( freq[i] * (freq[i] - 1) ) / 2;
		
		for(int j = i + 1 ; j < 1025 ; j++)
		if(i & j)
		ans += freq[i] * freq[j];
	}
	
	return ans;
}
int main() 
{
	vector<int> a = {10, 12, 24};
	int n = a.size();
	
	cout << Count_Pairs(a,n) << endl;
	
	return 0;
}

