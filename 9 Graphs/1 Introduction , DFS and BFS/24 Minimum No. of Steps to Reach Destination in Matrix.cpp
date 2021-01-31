#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
int MinimumStep(int M[4][4],int n)
{
	pair<int,int> s={-1,-1};
	pair<int,int> d={-1,-1};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(M[i][j]==1)
			s={i,j};
			else if(M[i][j]==2)
			d={i,j};
			
			if(s.first!=-1 && d.first!=-1)
		    break;
		}
		if(s.first!=-1 && d.first!=-1)
		break;
	}
	
	queue<pair<int,int>> q;
	q.push(s);
	M[s.first][s.second]=0;
	M[d.first][d.second]=3;
	
	int cnt=0;
	
	while(q.size())
	{
		int size=q.size();
		while(size--)
		{
			if(q.front()==d)
			return cnt;
			
			int i=q.front().first,j=q.front().second;  q.pop();
			
			if(i-1>=0 && M[i-1][j]==3)
			{
				M[i-1][j]=0;
				q.push({i-1,j});
			}
			
			if(j-1>=0 && M[i][j-1]==3)
			{
				M[i][j-1]=0;
				q.push({i,j-1});
			}
			
			if(i+1<n && M[i+1][j]==3)
			{
				M[i+1][j]=0;
				q.push({i+1,j});
			}
			
			if(j+1<n && M[i][j+1]==3)
			{
				M[i][j+1]=0;
				q.push({i,j+1});
			}
		}
		
		cnt++;
	}
	
	return -1;
}
signed main()
{
	int M[4][4] = {{ 3 , 3 , 1 , 0 },
                   { 3 , 0 , 3 , 3 },
                   { 2 , 3 , 0 , 3 },
                   { 0 , 3 , 3 , 3 }};
    int n=4;
	
	cout<<MinimumStep(M,n)<<endl;
	
	return 0;
}
