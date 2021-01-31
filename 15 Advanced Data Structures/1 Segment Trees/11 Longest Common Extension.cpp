#include<bits/stdc++.h>
using namespace std;
struct suf
{
	int ind;
	int rank[2];	
};
bool comp(suf s1 , suf s2)
{
	if(s1.rank[0] == s2.rank[0])
	return (s1.rank[1] < s2.rank[1]);
	
	return (s1.rank[0] < s2.rank[0]);
}
int* Build_Suff_Arr(string &s , int n)
{
	suf Sufix[n];
	
	for(int i = 0 ; i < n ; i++)
	Sufix[i].ind = i , Sufix[i].rank[0] = s[i] - 'a' , Sufix[i].rank[1] = ((i == n-1) ? -1 : s[i+1] - 'a');
	
	sort(Sufix , Sufix + n , comp);
	
	int ind[n];
	
	for(int k = 4 ; k < 2 * n ; k++)
	{
		int rank = 0 , rank0 = Sufix[0].rank[0] , rank1 = Sufix[0].rank[1];
		
		ind[Sufix[0].ind] = 0;
		
		for(int i = 1 ; i < n ; i++)
		{
			if(rank0 != Sufix[i].rank[0] || rank1 != Sufix[i].rank[1])
			rank++;
			
			rank0 = Sufix[i].rank[0] , rank1 = Sufix[i].rank[1];
			
			Sufix[i].rank[0] = rank;
			
			ind[Sufix[i].ind] = i;
		}
		
		for(int i = 0 ; i < n ; i++)
		{
			int next = Sufix[i].ind + k/2;
			
			Sufix[i].rank[1] = ((next < n) ? Sufix[ind[next]].rank[0] : -1);
		}
		
		sort(Sufix , Sufix + n , comp);
	}
	
	int* suff = new int[n];
	
	for(int i = 0 ; i < n ; i++)
	suff[i] = Sufix[i].ind;
	
	return suff;
}
int* Kasai(string &s , int n , int* suff , int ind[])
{
	int* LCP = new int[n];  memset(LCP , 0 , sizeof(int)*n);
	
	int k = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(ind[i] == n-1)
		{
			k = 0;
			
			continue;
		}
		
		int j = suff[ind[i] + 1];
		
		while(i+k < n && j+k < n && s[i+k] == s[j+k])
		k++;
		
		LCP[ind[i]] = k;
		
		if(k > 0)
		k--;
	}
	
	return LCP;
}
int RMQ(int l , int r , int* st , int sti , int ql , int qr)
{
	if(l >= ql && r <= qr)
	return st[sti];
	
	if(l > qr || r < ql)
	return INT_MAX;
	
	int m = l + (r - l) / 2;
	
	return min(RMQ(l , m , st , sti * 2 + 1 , ql , qr) , RMQ(m+1 , r , st , sti * 2 + 2 , ql , qr));
}
void Construct_Untill(int* a , int l , int r , int* st , int sti)
{
	if(l == r)
	{
		st[sti] = a[l];
		
		return;
	}
	
	int m = l + (r - l) / 2;
	
	Construct_Untill(a , l , m , st , sti * 2 + 1);
	
	Construct_Untill(a , m+1 , r , st , sti * 2 + 2);
	
	st[sti] = min(st[sti * 2 + 1] , st[sti * 2 + 2]);
}
int* Construct_St(int* a , int n)
{
	int p = ceil(log2(n));
	
	int size = 2 * pow(2 , p) - 1;
	
	int *st = new int[n];
	
	Construct_Untill(a , 0 , n-1 , st , 0);
	
	return st;
}
void Ans_Queries(string &s , int n , vector<pair<int,int>> &Q , int q)
{
	int* suff = Build_Suff_Arr(s , n);
	
	int ind[n];
	
	for(int i = 0 ; i < n ; i++)
	ind[suff[i]] = i;
	
	int* LCP = Kasai(s , n , suff , ind);
	
	int* st = Construct_St(LCP , n);
	
	for(int i = 0 ; i < q ; i++)
	cout << RMQ(0 , n - 1 , st , 0 , ind[Q[i].second] , ind[Q[i].first] - 1) << endl;
}
signed main()
{
	string s = "abbababba";
	int n = s.length();
	
	vector<pair<int,int>> Q = {{1 , 2} , {1 , 6} , {0 , 5}};
	int q = Q.size();
	
	Ans_Queries(s , n , Q , q);
		
	return 0;
}
