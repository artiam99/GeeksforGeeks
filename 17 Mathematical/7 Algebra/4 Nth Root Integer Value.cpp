#include <bits/stdc++.h> 
using namespace std; 

int nthRoot(int A, int N) 
{
	float p = ((log10(A)) / N);
	
	float q = ceil(pow(10 , p));
	
	float u = floor(pow(10 , p));
	
	int r = pow(q , N);
	
	int s = pow(u , N);
	
	if(r == A)  return q;
	
	if(s == A)  return u;
	
	if(r < A)  return q;
	
	return u;
}

int main()
{
	int N = 4 , A = 82;

	int nthRootValue = nthRoot(A , N);

	cout << "Nth root is " << nthRootValue << endl;
	
	return 0;
}

