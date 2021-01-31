#include<bits/stdc++.h>
using namespace std;

void Seive(bool p[] , int sz)
{
    memset(p,true,sizeof(p));
    
    for(int i = 2 ; i * i < sz ; i++)
    if(p[i])
    {
        for(int j = i * i ; j < sz ; j += i)
        p[j] = false; 
    }
}

int Numbers_with_N_Divisors(int a , int b , int N) // No of Divisors , d = (e1 + 1) * (e2 + 1) * .. * (en + 1)  where e1 , e2 , .. , en are exponents of prime factors
{
	int sz = sqrt(b) + 1;
	
	bool p[sz];
	
	Seive(p , sz);
	
	vector<int> v;
	
	for(int i = 2 ; i * i <= b ; i++)
	if(p[i])
	v.push_back(i);
	
	int cnt = 0;
	
	for(int i = a ; i <= b ; i++)
	{
		int n = i , j = 0 , d = 1;
		
		for(int k = v[j] ; k * k <= n ; k = v[++j])
		{
			int e = 0;
			
			while(n % k == 0)
			{
				e++;
				
				n /= k;
			}
			
			d *= (e + 1);
			
			if(j == v.size() - 1)
			break;
		}
		
		if(n > 1)
		d *= 2;
		
		if(d == N)
		cnt++;
	}
	
	return cnt;
}

signed main()
{	
	int a = 1 , b = 7 , N = 2;
	
	cout << Numbers_with_N_Divisors(a , b , N) << endl;
}

