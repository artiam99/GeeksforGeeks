#include<bits/stdc++.h>
using namespace std;
int Signum(int n)
{
	if(!n)  return 0;
	
	return ((n > 0) ? 1 : -1);
}
int LZZS(vector<int> &a,int n)
{
	int lastsign = 0;
	int length = 1;
	
	for(int i=1;i<n;i++)
	{
		int sign = Signum(a[i]-a[i-1]);
		
		if(sign != lastsign && sign != 0)
		{
			lastsign = sign;
			
			length++;
		}
	}
	return length;
}
signed main()
{
	vector<int> a = { 10, 22, 9, 33, 21, 50, 41, 60, 80 };
    int n = a.size();
    
    cout<< LZZS(a,n) <<endl;
  
    return 0;
}
