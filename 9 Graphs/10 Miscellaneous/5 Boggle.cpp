#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isneighbour(int x,int y,int x1,int y1)
{
    return (x1>=x-1 && x1<=x+1 && y1>=y-1 && y1<=y+1 && !(x==x1 && y==y1));
}
bool DFS(string &s,int c,int x1,int y1,unordered_map<char,vector<pair<int,int>>> &m,vector<vector<bool>> &vis)
{
    if(c==s.length()) return true;
    
    for(auto i:m[s[c]])
    {
        int x=i.first,y=i.second;
        if((c==0 || isneighbour(x,y,x1,y1)) && !vis[x][y])
        {
            vis[x][y]=true;
            
            bool flag=DFS(s,c+1,x,y,m,vis);
            
            vis[x][y]=false;
            
            if(flag)  return true;
        }
    }
}
void Boggle(vector<string> &dictionary,int n,vector<vector<char>> &boggle,int r,int c)
{
	set<string> a;
    
    for(auto i:dictionary)
    a.insert(i);
    
    unordered_map<char,vector<pair<int,int>>> m;
    
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            m[boggle[i][j]].push_back({i,j});
        
	bool flag=0;
    
    vector<vector<bool>> vis(r,vector<bool>(c,false));
    
    for(auto i:a)
    if(DFS(i,0,-1,-1,m,vis))
    {
        cout<<i<<" ";
        flag=1;
    }
    
    if(!flag)  cout<<-1;
    
    cout<<endl;
}
signed main()
{
	vector<string> dictionary={ "GEEKS", "FOR", "QUIZ", "GO" };
	int n=dictionary.size();
	
    vector<vector<char>> boggle={ { 'G', 'I', 'Z' }, 
                     		      { 'U', 'E', 'K' }, 
                       		      { 'Q', 'S', 'E' } };
    int r=boggle.size(),c=boggle[0].size();
    
    Boggle(dictionary,n,boggle,r,c);
    
	return 0;
}
