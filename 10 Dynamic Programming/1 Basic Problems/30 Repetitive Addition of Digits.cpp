#include<bits/stdc++.h>
using namespace std;
int AddDigit(int n)
{
	return ( (n) ? ( (n%9) ? n%9 : 9 ) : 0);// https://harikad.wordpress.com/2019/12/17/sum-the-digits-recursively-till-you-love-math/
}
signed main()
{
	int n=98; // 9+8 = 17 --> 1+7 = 8 (Ans)
	
	cout<< AddDigit(n) <<endl; 
	    
	return 0;
}
