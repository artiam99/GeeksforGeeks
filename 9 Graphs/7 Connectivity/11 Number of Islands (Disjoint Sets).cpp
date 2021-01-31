#include<bits/stdc++.h>
using namespace std;
struct DSET
{
	int *parent;
	int *rank;
	DSET(int n)
	{
		parent=new int[n];
		for(int i=0;i<n;i++)
		parent[i]=i;
		
		rank=new int[n];
		memset(rank,0,sizeof(int)*n);
	}
};
int Find(DSET *d,int x)
{
	if(d->parent[x]!=x)
	d->parent[x]=Find(d,d->parent[x]);
	
	return d->parent[x];
}
void Union(DSET *d,int s,int e)
{
	int sroot=Find(d,s);
	int eroot=Find(d,e);
	
	if(sroot == eroot)
	return;
	
	if(d->rank[sroot] > d->rank[eroot])
	d->parent[eroot]=sroot;
	
	if(d->rank[sroot] < d->rank[eroot])
	d->parent[sroot]=eroot;
	
	else
	{
		d->parent[eroot]=sroot;
		d->rank[sroot]++;
	}
}
int countIslands(vector<vector<bool>> &a)
{
	int n=a.size();
	int m=a[0].size();
	
	DSET *d=new DSET(n*m);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!a[i][j])
			continue;
			
			if(i-1 >=0 && a[i-1][j])
			Union(d, i*m+j , (i-1)*m+j);
			
			if(i+1 <n && a[i+1][j])
			Union(d, i*m+j , (i+1)*m+j);
			
			if(j-1 >=0 && a[i][j-1])
			Union(d, i*m+j , i*m+(j-1));
			
			if(j+1 <m && a[i][j+1])
			Union(d, i*m+j , i*m+(j+1));
			
			if(i-1 >=0 && j-1 >=0 && a[i-1][j-1])
			Union(d, i*m+j , (i-1)*m+(j-1));
			
			if(i-1 >=0 && j+1<m && a[i-1][j+1])
			Union(d, i*m+j , (i-1)*m+(j+1));
			
			if(i+1 <n && j-1 >=0 && a[i+1][j-1])
			Union(d, i*m+j , (i+1)*m+(j-1));
			
			if(i+1 <n && j+1 <m && a[i+1][j+1])
			Union(d, i*m+j , (i+1)*m+(j+1));
		}
	}
	
	int cnt=0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		if(d->parent[i*m+j]==i*m+j && a[i][j]==1)
        cnt++;
	}
	
	return cnt;
}
signed main()
{
    vector<vector<bool>>a = {{1, 1, 0, 0, 0},
                             {0, 1, 0, 0, 1},
                             {1, 0, 0, 1, 1},
                             {0, 0, 0, 0, 0},
                             {1, 0, 1, 0, 1}};
							
	cout<<"Number of Islands is: "<< countIslands(a) << endl;
		
	return 0;
}
