#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
void topo(int u,unordered_set<int> adj[],vector<bool> &vis,string &s)
{
    vis[u]=true;
    
    for(auto i:adj[u])
    if(!vis[i])
    topo(i,adj,vis,s);
    
    s.insert(s.begin(),'a'+(char)u);
}
signed main()
{
    int N=5,K=4;
	string dict[]={"baa","abcd","abca","cab","cad"};
	
	
	unordered_set<int> adj[K];
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<min(dict[i].length(),dict[i+1].length());j++)
        {
            if(dict[i][j]!=dict[i+1][j])
            {
                adj[dict[i][j]-'a'].insert(dict[i+1][j]-'a');
                break;
            }
        }
    }
    
    string s;
    vector<bool> vis(K,false);
    
    for(int i=0;i<K;i++)
    if(!vis[i])
    topo(i,adj,vis,s);
    
    cout<<s<<endl;
}
