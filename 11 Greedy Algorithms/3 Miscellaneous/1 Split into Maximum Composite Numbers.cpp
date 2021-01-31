#include<bits/stdc++.h>
using namespace std;
int Split(int N)
{
	if(N < 4)  return -1;
	
	if(N % 4 == 0)  return N / 4;
	
	if(N %4 == 1)
	{
		if(N - 9 >= 4 || N - 9 == 0)  return 1 + (N-9)/4;
		
		return -1;
	}
	
	if(N % 4 == 2)
	{
		if(N - 6 >= 4 || N - 6 == 0)  return 1 + (N-6)/4;
		
		return -1;
	}
	
	if(N % 4 == 3)
	{
		if(N - 15 >= 4 || N - 15 == 0)  return 2 + (N-15)/4;
		
		return -1;
	}
}
int main()
{
	int N = 90;
	
	cout<< Split(N) << endl;
}
