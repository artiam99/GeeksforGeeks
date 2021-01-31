#include<bits/stdc++.h>
using namespace std;

/*

lcm(a , b , c) = lcm(a , lcm(b , c))

lcm(a , 1) = a;

*/

int gcd(int a , int b)
{
	if(a < b)  return gcd(b , a);
	
	if(b == 0)  return a;
	
	return gcd(b , a % b);
}

int lcm(int a , int b)
{
	int g = gcd(a , b);
	
	return ((a * b) / g);
}

int main()
{
	vector<int> a = {12 , 3 , 5};
	int n = a.size();
	
	int ans = 1;
	
	for(int i = 0 ; i < n ; i++)
	ans = lcm(ans , a[i]);
	
	cout << ans << endl;
		
	return 0;
}

