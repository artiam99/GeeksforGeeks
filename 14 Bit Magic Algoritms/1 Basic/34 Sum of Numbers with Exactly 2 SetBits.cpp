#include <bits/stdc++.h> 
using namespace std;
int Sum(int n)
{
	int i = 1;
	
	int sum = 0;
	
	while(i)
	{
		int x = (1 << i);
		
		for(int j = 0 ; j < i ; j++)
		{
			int y = x + (1 << j);
			
			if(y > n)  return sum;
			
			sum += y;
		}
		
		i++;
	}
	
	return sum;
}
int main() 
{
	int n = 100;
	
	cout<< Sum(n) << endl;
	
	return 0; 
}
