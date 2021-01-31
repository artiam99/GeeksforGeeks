#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
int BFT(int src,int dest,unordered_map<int,int> &m)
{
    vector<bool> vis(31);
    
    queue<int> q;
    
    q.push(src);
    vis[src]=true;
    
    int cnt=0;
    
    while(q.size())
    {
        int size=q.size();
        
        while(size--)
        {
            int u=q.front();  q.pop();
            
            if(u==dest)  return cnt;
            
            for(int i=1;i<=6;i++)
            {
                int d=(m[u+i])?m[u+i]:u+i;
                
                if(d<=30 && !vis[d])
                {
                    vis[d]=true;
                    
                    q.push(d);
                }
            }
        }
        
        cnt++;
        
    }
    return cnt;
}
int SnakeLadder(vector<pair<int,int>> &a,int n)
{
	unordered_map<int,int> m;
	
	for(int i=0;i<n;i++)
	m[a[i].first]=a[i].second;
	
	return BFT(1,30,m);
}
signed main()
{
	vector<pair<int,int>> a={{21,8} , {13,29} , {16,26}};
	int n=a.size();
	
	cout<< SnakeLadder(a,n) <<endl;
	                
	return 0;
}
