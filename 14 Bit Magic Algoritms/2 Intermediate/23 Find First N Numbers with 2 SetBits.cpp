#include<bits/stdc++.h> 
using namespace std;
void Print(int n)
{
	int i = 1;
	
	int cnt = 0;
	
	while(1)
	{
		bool flag = false;
		
		int j = 0;
		
		while(j < i)
		{
			cout << ((1 << i) + (1 << j)) << " ";
			
			cnt++;
			
			if(cnt == n)
			{
				flag = true;
				
				break;
			}
			
			j++;
		}
		
		if(flag)  break;
		
		i++;
	}
}
int main() 
{
	int n = 20;
	
	Print(n);
	
	return 0;
}

