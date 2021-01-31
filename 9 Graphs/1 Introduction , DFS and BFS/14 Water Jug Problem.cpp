#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
int MinimumNumberofStep(int m,int n,int c)
{
	bool M[m+1][n+1];
	memset(M,false,sizeof(M));
	
	queue<pair<int,int>> q;
	
	q.push({0,0});
	
	M[0][0]=true;
	
	int cnt=0;
	
	while(q.size())
	{
		int size=q.size();
		
		while(size--)
		{
			int i=q.front().first,j=q.front().second; q.pop();
			
			if((i==c && j==0) || (i==0 && j==c))
			return cnt;
			
			if(i>0)
			{
				if(!M[0][j])
				{
					M[0][j]=true;
					q.push({0,j});
				}
				if(j<n)
				{
					int d=n-j;
					
					if(d>=i)
					{
						if(!M[0][i+j])
						{
							M[0][i+j]=true;
							q.push({0,i+j});
						}
					}
					else
					{
						if(!M[i-d][n])
						{
							M[i-d][n]=true;
							q.push({i-d,n});
						}
					}
				}
			}
			else
			{
				if(!M[m][j])
				{
					M[m][j]=true;
					q.push({m,j});
				}
			}
			if(j>0)
			{
				if(!M[i][0])
				{
					M[i][0]=true;
					q.push({i,0});
				}
				if(i<m)
				{
					int d=m-i;
					
					if(d>=j)
					{
						if(!M[i+j][0])
						{
							M[i+j][0]=true;
							q.push({i+j,0});
						}
					}
					else
					{
						if(!M[m][j-d])
						{
							M[m][j-d]=true;
							q.push({m,j-d});
						}
					}
				}
			}
			else
			{
				if(!M[i][n])
				{
					M[i][n]=true;
					q.push({i,n});
				}
			}
			
		}
		cnt++;
	}
	return -1;
}
signed main()
{
	int m=4,n=3,c=2;
	
	cout<<MinimumNumberofStep(m,n,c)<<endl;
		
	return 0;
}
