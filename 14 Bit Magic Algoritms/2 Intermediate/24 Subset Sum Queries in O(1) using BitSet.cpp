#include<bits/stdc++.h> 
using namespace std;
void PreProcess(vector<int> &a,int n,bitset<1000> &bit)
{
	bit[0] = 1;
	
	for(int i = 0 ; i < n ; i++)
	bit |= (bit << a[i]);
}
void AnsQueries(vector<int> &a,int n,vector<int> &Q,int q)
{
	bitset<1000> bit;
	
	PreProcess(a,n,bit);
	
	for(int i = 0 ; i < q ; i++)
	{
		if(Q[i] > 1000)  cout << "N/A" << endl;
		
		else 
		{
			if(bit[Q[i]])  cout << "YES" << endl;
			
			else  cout << "NO" << endl;
		}
	}
}
int main() 
{
	vector<int> a = {1, 3, 2};
	int n = a.size();
	
	vector<int> Q = {5, 3, 8};
	int q = Q.size();
	
	AnsQueries(a,n,Q,q);
	
	return 0;
}

