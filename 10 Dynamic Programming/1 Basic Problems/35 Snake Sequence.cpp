#include<bits/stdc++.h>
using namespace std;
int SnakeSequence(vector<vector<int>> &a,int n,int m)
{
	vector<vector<int>> dp(n,vector<int>(m));
        
    pair<int,int> p={0,0};
    
	int mx=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i>0 && abs(a[i-1][j]-a[i][j])==1 && dp[i-1][j]>=dp[i][j])
            {
                dp[i][j]=dp[i-1][j]+1;

                if(mx<dp[i][j])
                {
                    p={i,j};

                    mx=dp[i][j];
                }
            }
            if(j>0 && abs(a[i][j-1]-a[i][j])==1 && dp[i][j-1]>=dp[i][j])
            {
                dp[i][j]=dp[i][j-1]+1;

                if(mx<dp[i][j])
                {
                    p={i,j};

                    mx=dp[i][j];
                }
            }
        }
    }
    
	stack<int> st;
    
	while(1)
    {
        int x=p.first,y=p.second;
        
		st.push(a[x][y]);
        
		if(x>0 && abs(a[x-1][y]-a[x][y])==1 && y>0 && abs(a[x][y-1]-a[x][y])==1)
        {
            if(dp[x-1][y]>=dp[x][y-1])
            p={x-1,y};
            
			else
            p={x,y-1};
        }
        
		else if(x>0 && abs(a[x-1][y]-a[x][y])==1)
        p={x-1,y};
        
        else if(y>0 && abs(a[x][y-1]-a[x][y])==1)
        p={x,y-1};
        
		else
        break;
    }
    
    cout<<"Length of Sequence : "<<mx+1<<endl<<endl;
    cout<<"Sequence : ";
    
    while(st.size())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
signed main()
{
	vector<vector<int>> a = { {9, 6, 5, 2}, 
        					  {8, 7, 6, 5}, 
       						  {7, 3, 1, 6}, 
        					  {1, 1, 1, 7}, 
    						};
	int n=a.size();
	int m=a[0].size();
	
	SnakeSequence(a,n,m);
	
	return 0;
}
