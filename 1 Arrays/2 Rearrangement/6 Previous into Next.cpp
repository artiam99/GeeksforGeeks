#include <bits/stdc++.h> 
using namespace std;

void Prev_Next_Multiple(int a[] , int n)
{
	int max = 0;
	
	for(int i = 1 ; i < n ; i++)
	if(a[max] < a[i])
	max = i;
	
	int maxe = a[n-1] + 1;
	
	for(int i = 0 ; i < n ; i++)
	{
		int prev = i - 1;
		int next = i + 1;
		
		if(i == 0)  prev = 0;
		
		else if(i == n-1)  next = n - 1;
		
		a[i] += ((a[prev] % maxe) * (a[next] % maxe)) * maxe;
	}
	
	for(int i = 0 ; i < n ; i++)
	a[i] /= maxe;
	
	for(int i = 0 ; i < n ; i++)
	cout << a[i] << " ";
}

int main() 
{ 
	int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110}; 
	int n = sizeof(a) / sizeof(a[0]);
	
	Prev_Next_Multiple(a , n);
	
	return 0; 
}
