#include<bits/stdc++.h>
using namespace std;
#define int long long
void RottenOranges(vector<vector<int>> &a,int r,int c)
{
	queue<pair<int,int>> q;
    int one=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]==2)
            q.push({i,j});
            if(a[i][j]==1)
            one++;
        }
    }
    if(q.empty())
    {
        cout<<-1<<endl;
        return;
    }
    int cn=0;
    while(1)
    {
        if(q.empty()||one==0)
        break;
        cn++;
        q.push({-1,-1});
        while(q.front().first!=-1&&q.front().second!=-1)
        {
            int i=q.front().first;
            int j=q.front().second;
            if(i-1>=0&&a[i-1][j]==1)
            {
                q.push({i-1,j});
                a[i-1][j]=2;
                one--;
            }
            if(i+1<r&&a[i+1][j]==1)
            {
                q.push({i+1,j});
                a[i+1][j]=2;
                one--;
            }
            if(j-1>=0&&a[i][j-1]==1)
            {
                q.push({i,j-1});
                a[i][j-1]=2;
                one--;
            }
            if(j+1<c&&a[i][j+1]==1)
            {
                q.push({i,j+1});
                a[i][j+1]=2;
                one--;
            }
            q.pop();
        }
        q.pop();
    }
    if(one==0)
    cout<<cn<<endl;
    else
    cout<<-1<<endl;	
}
signed main()
{
	vector<vector<int>> a = { { 2, 1, 0, 2, 1 }, 
           			          { 1, 0, 1, 2, 1 }, 
                			  { 1, 0, 0, 2, 1 } }; 
	int r=a.size(),c=a[0].size();
	
	RottenOranges(a,r,c);
	
	return 0;
}
