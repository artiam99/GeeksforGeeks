#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
int SmallestBinaryDigitMultiple(int n)
{
	queue<int> q;
	q.push(1);
	
	while(1)
	{
		int x=q.front(); q.pop();
		
		if(x>n && x%n==0)
		return x;
		
		q.push(x*10);
		q.push(x*10+1);
	}
}
signed main()
{
	int n=17;
	
	cout<<SmallestBinaryDigitMultiple(n)<<endl;
		
	return 0;
}
