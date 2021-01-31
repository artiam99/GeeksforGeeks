#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
class Graph
{
	int V;
	list<int> *adj;
	
	public:
		Graph(int V)
		{
			this->V=V;
			
			adj=new list<int>[V];
		}
		void addEdge(int u,int v)
		{
			adj[u].push_back(v);
		}
		void traverse(int x,vector<bool> &present)
		{
			if(present[x])
			return;
			
			cout<<x<<" ";
			present[x]=1;
			
			for(auto i=adj[x].begin();i!=adj[x].end();i++)
			traverse(*i,present);
		}
		void DFT()
		{
			vector<bool> present(V);
			
			for(int i=0;i<V;i++)
			if(!present[i])
			traverse(i,present);
			
			cout<<endl;
		}
};
signed main()
{
	Graph g(4);
	
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    g.DFT();
    
	return 0;
}
