#include<bits/stdc++.h>
using namespace std;

bool p[10000000];
void Seive()
{
    memset(p,true,sizeof(p));
    
    for(int i = 2 ; i * i < 10000000 ; i++)
    if(p[i])
    {
        for(int j = i * i ; j < 10000000 ; j += i)
        p[j] = false; 
    }
}

int Three_Divisors(int N)
{
	int cnt = 0;
	    
	for(int i = 2 ; i * i <= N ; i++)
	if(p[i])
	cnt++;
	
	return cnt;
}

signed main()
{
	Seive();
	
	int N = 500;
	
	cout << Three_Divisors(N) << endl;
}

