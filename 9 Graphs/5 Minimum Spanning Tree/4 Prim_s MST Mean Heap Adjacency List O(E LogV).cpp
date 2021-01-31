#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct adjnode
{
	int dest;
	int wt;
	adjnode* next;
	adjnode(int v,int w)
	{
		dest=v;
		wt=w;
		next=NULL;
	}
};
struct adjList
{
	adjnode* head;
};
struct Graph
{
	int V;
	adjList *adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new adjList[V];
	for(int i=0;i<V;i++)
	g->adj[i].head=NULL;
	
	return g;
}
void addEdge(Graph* g,int u,int v,int w)
{
	adjnode *node=new adjnode(v,w);
	node->next=g->adj[u].head;
	g->adj[u].head=node;
	
	node=new adjnode(u,w);
	node->next=g->adj[v].head;
	g->adj[v].head=node;
}
struct HeapNode
{
	int ind,key;
};
struct MinHeap
{
	int size;
	HeapNode *arr;
	int *pos;
	MinHeap(int V)
	{
		arr=new HeapNode[V];
		
		for(int i=0;i<V;i++)
		arr[i].ind=i,arr[i].key=INT_MAX;
		
		pos=new int[V];
		for(int i=0;i<V;i++)
		pos[i]=i;
		
		size=V;
	}
	HeapNode top()
	{
		return arr[0];
	}
	void Heapify(int i)
	{
		int smallest=i;
		int left=i*2+1;
		int right=i*2+2;
		
		if(left <size && arr[left].key<arr[smallest].key)
		smallest=left;
		
		if(right<size && arr[right].key<arr[smallest].key)
		smallest=right;
		
		if(smallest!=i)
		{
			pos[arr[i].ind]=smallest;
			pos[arr[smallest].ind]=i;
			
			swap(arr[smallest],arr[i]);
			
			Heapify(smallest);
		}
	}
	void ExtractMin()
	{
		size--;
		
		pos[arr[0].ind]=size;
		pos[arr[size].ind]=0;
		
		swap(arr[0],arr[size]);
		
	    Heapify(0);
	}
	void DecreaseKey(int i,int x)
	{
		i=pos[i];
		
		arr[i].key=x;
		
		while(i && arr[i].key < arr[(i-1)/2].key)
		{
			pos[arr[i].ind]=(i-1)/2;
			pos[arr[(i-1)/2].ind]=i;
			
			swap(arr[(i-1)/2],arr[i]);
			
			i=(i-1)/2;
		}
	}
};
void PrimsMST(Graph *g)
{
	bool *vis=new bool[g->V] ;
	memset(vis,0,sizeof(bool)*g->V);
	
	pair<int,int> parent[g->V];
	
	MinHeap pq(g->V);
	
	pq.DecreaseKey(0,0);
	
	while(pq.size)
	{
		int u=pq.top().ind;
		
		pq.ExtractMin();
		
		vis[u]=true;
		
		
		for(adjnode* temp = g->adj[u].head; temp ;temp=temp->next)
		{
			if(!vis[temp->dest] && temp->wt < pq.arr[pq.pos[temp->dest]].key)
			{
				pq.DecreaseKey(temp->dest,temp->wt);
				
				parent[temp->dest]={u,temp->wt};
			}
		}
	}
	for(int i=1;i<g->V;i++)
	cout<<i<<" "<<parent[i].first<<" -> "<<parent[i].second<<endl;
}
signed main()
{
	int V=9;
	
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,1,4);
	addEdge(g,0,7,8);
	addEdge(g,1,2,8);
	addEdge(g,1,7,11);
	addEdge(g,7,8,7);
	addEdge(g,7,6,1);
	addEdge(g,2,8,2);
	addEdge(g,6,8,6);
	addEdge(g,6,5,2);
	addEdge(g,2,5,4);
	addEdge(g,2,3,7);
	addEdge(g,3,5,14);
	addEdge(g,3,4,9);
	addEdge(g,4,5,10);
	
	PrimsMST(g);
	
	return 0;
}
