#include<bits/stdc++.h>
using namespace std;

int Nth_Fibo(int N)
{
	return round(pow(((1 + sqrt(5)) / 2) , N) / sqrt(5));
}

signed main()
{
	int N = 8;
	
	cout << Nth_Fibo(N) << endl;
	
	return 0;
}
