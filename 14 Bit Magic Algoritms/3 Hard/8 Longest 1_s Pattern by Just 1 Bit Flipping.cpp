#include<bits/stdc++.h> 
using namespace std;
int Longest_Ones(int n)
{
	int curr1 = 0 , curr2 = 0 , mx = 0;
	
	bool flag = true;
	
	while(1)
	{
		if(n & 1)  curr1++ , curr2++;
		
		else
		{			
			curr1 = curr2 + 1;
			
			curr2 = 0;
		}
		
		mx = max(mx , curr1);
		
		n >>= 1;
		
		if(!flag)  break;
		
		if(!n)  flag = false;  // One More bit after N ends
	}
	return mx;
}
int main() 
{
	int n = 1775;
	
	cout << Longest_Ones(n) << endl;
	
	return 0;
}

