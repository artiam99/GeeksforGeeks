#include<bits/stdc++.h>
using namespace std;
void Zeck(int N)
{
	vector<int> fib;
	
	fib.push_back(0);
	fib.push_back(1);
	
	while(fib[fib.size()-1] + fib[fib.size()-2] <= N)
	fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
	
	int i = fib.size()-1;
	
	while(N != 0)
	{
		if(fib[i] <= N)
		cout<< fib[i] << " " , N -= fib[i--];
		
		else i--;
	}
}
signed main()
{
	int N = 64;
	
	Zeck(N);
    
    return 0;
}
