#include<bits/stdc++.h>
using namespace std;
int SubStringSum(string s,int n)
{
	int sum = 0 , temp = 1;
	
	for(int i=n-1;i>=0;i--)
	sum += (i+1) * ( (s[i]-48) * temp * 10 / 9 ) , temp *= 10;
	
	return sum;
}
signed main()
{
	string s = "1234";
	
	cout<< SubStringSum(s,s.length()) <<endl;
    
	return 0;
}
