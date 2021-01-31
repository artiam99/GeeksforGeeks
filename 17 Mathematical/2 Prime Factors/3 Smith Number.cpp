#include<bits/stdc++.h>
using namespace std;
#define Max 100001

int spf[Max];

void Fill_spf()
{
    for(int i = 0 ; i < Max ; i++)
    spf[i] = i;
    
    for(int i = 2 ; i * i < Max ; i++)
    if(spf[i] == i)
    {
        for(int j = i * i ; j < Max ; j += i)
        if(spf[j] == j)
        spf[j] = i;
    }
}
int Digit_Sum(int n)
{
    int sum = 0;
    
    while(n)
    {
        sum += n % 10;
        
        n /= 10;
    }
    
    return sum;
}

int Factor_Digit_Sum(int n)
{
    if(n == 1)
    return 1;
    
    int sum = 0;
    
    while(n != 1)
    {
        sum += Digit_Sum(spf[n]);
        
        n /= spf[n];
    }
    
    return sum;
}

void Is_Smith(int n)
{	
	if(spf[n] != n && Digit_Sum(n) == Factor_Digit_Sum(n))
	cout << n << " is Smith Number" << endl;
	
	else
	cout << n << " is not Smith Number" <<endl;
}

signed main()
{	
	Fill_spf();
	
	Is_Smith(4);
	
	Is_Smith(6);
	
	Is_Smith(666);
	
	Is_Smith(13);
	
	return 0;
}
