#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
double Probability(int m,int n,int i,int j,int N,int cnt)
{
	if(i < 0 || i > m || j <0 || j > n)
	return 0.0;
	
	if(cnt==N)
	return 1.0;
	
	double prob=0;
	
	prob += Probability( m, n, i-1, j, N, cnt+1 ) * 0.25;
	
	prob += Probability( m, n, i+1, j, N, cnt+1 ) * 0.25;
	
	prob += Probability( m, n, i, j-1, N, cnt+1 ) * 0.25;
	
	prob += Probability( m, n, i, j+1, N, cnt+1 ) * 0.25;
	
	return prob;
}
signed main()
{
	int m=5,n=5;
	pair<int,int> p={1,1};
	int N=2;
	
	cout<<Probability(m,n,p.first,p.second,N,0)<<endl;
}
