#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
void PrintSteppingNumber(int n,int m)
{
	queue<int> q;
	
	if(!n)
	cout<<0<<" ";
	for(int i=1;i<10;i++)
	q.push(i);
	
	while(1)
	{
		int x=q.front(); q.pop();
		
		if(x>=n && x<=m)
		cout<<x<<" ";
		
		if(x>m)
		return;
		
		int y=x%10;
		
		if(y!=0)
		q.push(x*10+y-1);
		
		if(y!=9)
		q.push(x*10+y+1);
	}
}
signed main()
{
	int n=21,m=200;
	
	PrintSteppingNumber(n,m);
		
	return 0;
}
