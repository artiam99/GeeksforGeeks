#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define N 5
void Update(char Bank[N][N],int x,int y,vector<vector<int>> &dist)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	dist[x][y]=0;
	
	int lvl=1;
	
	while(q.size())
	{
		int size=q.size();
		
		while(size--)
		{
			x=q.front().first;
			y=q.front().second;
			q.pop();
			
			if(x-1 >= 0 && Bank[x-1][y]=='O' && dist[x-1][y] > lvl)
			{
				dist[x-1][y]=lvl;
				
				q.push({x-1,y});
			}
			
			if(x+1 < N && Bank[x+1][y]=='O' && dist[x+1][y] > lvl)
			{
				dist[x+1][y]=lvl;
				
				q.push({x+1,y});
			}
			
			if(y-1 >= 0 && Bank[x][y-1]=='O' && dist[x][y-1] > lvl)
			{
				dist[x][y-1]=lvl;
				
				q.push({x,y-1});
			}
			
			if(y+1 < N && Bank[x][y+1]=='O' && dist[x][y+1] > lvl)
			{
				dist[x][y+1]=lvl;
				
				q.push({x,y+1});
			}
		}
		lvl++;
	}
}
void FindDistance(char Bank[N][N])
{	
	vector<vector<int>> dist(N,vector<int>(N,INT_MAX));
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(Bank[i][j] == 'G')
		    Update(Bank,i,j,dist);
		    
		    else if(Bank[i][j]=='W')
		    dist[i][j]=-1;
		}
	}
	
	for(auto i:dist)
	{
		for(auto j:i)
		{
			if(j>=0)
			cout<<" ";
			
			cout<<j<<" ";
		}
		cout<<endl;
	}
	
}
signed main()
{
	char Bank[][N] = 
    { 
        {'O', 'O', 'O', 'O', 'G'}, 
        {'O', 'W', 'W', 'O', 'O'}, 
        {'O', 'O', 'O', 'W', 'O'}, 
        {'G', 'W', 'W', 'W', 'O'}, 
        {'O', 'O', 'O', 'O', 'G'} 
    };
	
	FindDistance(Bank);
	
	return 0;
}
