#include<bits/stdc++.h> 
using namespace std;

int Solve(int A[] , int B[] , int C[] , int a , int b , int c)
{
	int i = 0 , j = 0 , k = 0;
	
	int mindiff = INT_MAX;
	
	int a1 , b1 , c1;
	
	while(i < a && j < b && k < c)
	{
		int mx = max(max(A[i] , C[k]) , B[j]);
		
		int mn = min(min(A[i] , B[j]) , C[k]);
		
		int diff = mx - mn;
		
		int x = A[i];
		
		int y = B[j];
		
		int z = C[k];
		
		if(A[i] == mn)
		i++;
		
		else if(B[j] == mn)
		j++;
		
		else
		k++;
		
		if(diff <= mindiff)
		{
			a1 = x;
			
			b1 = y;
			
			c1 = z;
			
			mindiff = diff;
		}
	}
	
	cout << a1 << " " << b1 << " " << c1 << endl;
	
	return mindiff;
}
int main() 
{
	int D[] = {5, 8, 10, 15};
	int E[] = {5, 6, 15, 78, 89};
	int F[] = {8, 9, 9, 10};
	int nD = sizeof(D) / sizeof(D[0]);
	int nE = sizeof(E) / sizeof(E[0]);
	int nF = sizeof(F) / sizeof(F[0]);
	
	cout << Solve(D, E, F, nD, nE, nF) << endl; 
	
	return 0;
}
