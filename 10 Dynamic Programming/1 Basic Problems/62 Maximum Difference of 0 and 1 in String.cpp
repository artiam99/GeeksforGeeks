#include<bits/stdc++.h>
using namespace std;
int MaxDiff(string s)
{
	int max_curr = ((s[0] - 48) ? -1 : 1);
	int max_sofar = max_curr;
	
	for(int i=0;i<s.length();i++)
	{
		max_curr = max(max_curr + ((s[i] - 48) ? -1 : 1) , ((s[i] - 48) ? -1 : 1));
		
		max_sofar = max(max_curr , max_sofar);
	}
	return max_sofar;
}
signed main()
{
	string s = "11000010001";
	
	cout<< MaxDiff(s) <<endl;
    
	return 0;
}
