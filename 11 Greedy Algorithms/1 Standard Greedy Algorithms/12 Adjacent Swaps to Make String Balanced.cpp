#include <bits/stdc++.h>
using namespace std;
int Min_Swaps(string &s,int n)
{
	int op = 0 , cnt = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(s[i] == '[')  op++;
		
		else
		{
			if(op == 0)
			{
				int j = i+1;
				
				while(j < n && s[j] != '[')
				j++;
				
				if(s[j] == '[')
				{
					s[j] = ']';
				
					cnt += j-i;
				
					op++;	
				}
			}
			else  op--;
		}
	}
	return cnt;
}
int main()
{
	string s = "]][[";
	int n = s.length();
	
	cout<< Min_Swaps(s,n) <<endl;
	
	return 0;
}
