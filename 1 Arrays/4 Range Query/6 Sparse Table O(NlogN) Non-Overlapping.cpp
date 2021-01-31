 #include<bits/stdc++.h> 
using namespace std;

void Sparse(vector<int> &a , int n , vector<pair<int,int>> &Q , int q)
{
	vector<vector<int>> lookup(n);
	
	for(int i = 0 ; i < n ; i++)
	lookup[i].push_back(a[i]);

	for(int i = 0 ; i < log2(n) ; i++)
	{
		for(int j = 0 ; j <= n - (1 << (i + 1)) ; j++)
		lookup[j].push_back(lookup[j][i] + lookup[j + (1 << i)][i]);
	}
	
	for(int i = 0 ; i < n ; i++)
	{
		for(auto j : lookup[i])
		cout << j << " " ;
		cout<<endl;
	}
	
	for(int i = 0 ; i < q ; i++)
	{
		int l = Q[i].first;
		
		int r = Q[i].second;
		
		int sum = 0;
		
		while(l <= r)
		{
			int p = log2(r - l + 1);
			
			sum += lookup[l][p];
			
			l = pow(2 , p) + l;
		}
		cout << sum << endl;
	}
}

int main()
{
	vector<int> a = {7, 2, 3, 0, 5, 10, 3, 12, 18}; 
	int n = a.size();
	
	vector<pair<int,int>> Q={{0 , 4}, {4 , 7}, {7 , 8}}; 
	int q = Q.size();
	
	Sparse(a , n , Q , q);
	
	return 0; 
}

