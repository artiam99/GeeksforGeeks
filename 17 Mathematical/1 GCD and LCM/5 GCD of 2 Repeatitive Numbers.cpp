#include<bits/stdc++.h>
using namespace std;

string GCD(int n , int x , int y)
{
	int cnt = __gcd(x , y);  // A , B Two Numbers GCD(A , B) = GCD(A - q * B , B)  where q * B <= A
	
	string s = to_string(n) , ans;
	
	for(int i = 0 ; i < cnt ; i++)
	ans += s;
	
	if(!ans.size())
	ans += '0';
	
	return ans;
}

int main()
{
	int n = 3 , x = 12 , y = 36;
	
	cout << GCD(n , x , y) << endl;
		
	return 0;
}

