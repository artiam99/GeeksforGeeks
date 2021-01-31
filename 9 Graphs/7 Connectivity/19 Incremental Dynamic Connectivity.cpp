#include<bits/stdc++.h>
using namespace std;
int Find(vector<pair<int,int>> &parent,int x)
{
	if(parent[x].first != x)
	parent[x].first = Find(parent,parent[x].first);
	return parent[x].first;
}
void Union(vector<pair<int,int>> &parent,int uroot,int vroot)
{
	if(parent[uroot].second > parent[vroot].second)
	parent[vroot].first=uroot;
	
	else if(parent[uroot].second < parent[vroot].second)
	parent[uroot].first=vroot;
	
	else
	{
		parent[vroot].first=uroot;
		parent[uroot].second++;
	}
}
void AnsQueries(int v,vector<pair<int,pair<int,int>>> &Q,int q)
{
	vector<pair<int,int>> parent(v);
	
	for(int i=0;i<v;i++)
	parent[i]={i,0};
	
	for(int i=0;i<q;i++)
	{
		int type = Q[i].first;
		int u = Q[i].second.first;
		int v = Q[i].second.second;
		
		if(type == 1)
		{
			int uroot = Find(parent,u);
			int vroot = Find(parent,v);
			
			if(uroot == vroot)
			cout<<u<<" and "<<v<<" are Connected"<<endl;
			else
			cout<<u<<" and "<<v<<" are not Connected"<<endl;
		}
		else if(type == 2)
		{
			int uroot = Find(parent,u);
			int vroot = Find(parent,v);
			
			if(uroot != vroot)
			Union(parent,uroot,vroot);
		}
	}
}
signed main()
{
	int v=7;
	vector<pair<int,pair<int,int>>> Q = {
		                                {1 , {0 , 1}},
									    {2 , {0 , 1}},
									    {2 , {1 , 2}},
									    {1 , {0 , 2}},
									    {2 , {0 , 2}},
									    {2 , {2 , 3}},
									    {2 , {3 , 4}},
									    {1 , {0 , 5}},
									    {2 , {4 , 5}},
									    {2 , {5 , 6}},
									    {1 , {2 , 6}}  
	                                   };
	int q=Q.size();
	
	AnsQueries(v,Q,q);
	                                    
	return 0;
	
	
}
