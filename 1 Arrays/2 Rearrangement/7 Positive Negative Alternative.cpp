#include <bits/stdc++.h> 
using namespace std;

void Pos_Neg_Alt(int a[] , int n)
{
	int pos = 0 , neg = 1;
	
	while(pos < n && neg < n)
	{
		while(a[neg] < 0 && neg < n)
		neg += 2;
		
		while(a[pos] >= 0 && pos < n)
		pos += 2;
		
		if(pos < n && neg < n)
		swap(a[pos] , a[neg]);
		
		else
		break;
	}
	
	for (int i = 0 ; i < n ; i++) 
	cout << a[i] << " ";
}

int main() 
{
	int a[] = {-10, 20, 30, 40, -50, 60, 70, -80, -90, 100, 110}; //order is changing
	int n = sizeof(a) / sizeof(a[0]);
	
	Pos_Neg_Alt(a , n);
	
	return 0; 
}
