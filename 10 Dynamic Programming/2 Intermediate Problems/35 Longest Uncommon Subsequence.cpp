#include<bits/stdc++.h>
using namespace std;
int LUSS(string s1,string s2)
{
	if(s1.compare(s2) == 0)  return -1;
	
	return max(s1.length() , s2.length());
}
signed main()
{
	string s1 = "babab";
	
	string s2 = "babba";
	
	cout<< LUSS(s1,s2) <<endl;
    
	return 0;
}
