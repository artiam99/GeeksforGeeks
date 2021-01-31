#include<bits/stdc++.h>
using namespace std;

int block;

bool comp(pair<int,pair<int,int>> a1 , pair<int,pair<int,int>> a2)
{
	if(a1.second.first / block != a2.second.first / block)
	return (a1.second.first / block < a2.second.first / block);
	
	return (a1.second.second < a2.second.second);
}

void Queries(string &s , int n , vector<pair<int,pair<int,int>>> &Q , int q)
{
	vector<int> arr(n);
	
	stack<int> st;
	
	int in = 1;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(s[i] == '(')
		st.push(i);
		
		else
		{
			if(!st.empty())
			{
				arr[i] = in;
		
				arr[st.top()] = in;
		
				st.pop();
		
				in++;
			}
		}
	}
	
	block = sqrt(n);
	
	sort(Q.begin() , Q.end() , comp);
	
	unordered_map<int,int> m;
	
	int curl = 0 , curr= -1 , c = 0;
	
	vector<int> ans(q);
	
	for(int i = 0 ; i < q ; i++)
	{
		int l = Q[i].second.first;
		int r = Q[i].second.second;
		int p = Q[i].first;

		while(curr < r)
		{
			curr++;

			if(arr[curr] != 0)
			m[arr[curr]]++;

			if(m[arr[curr]] == 2)
			c++;
		}
		while(curr > r)
		{
			if(arr[curr] != 0)
			m[arr[curr]]--;
			
			if(m[arr[curr]] == 1)
			c--;
			
			curr--;
		}
		
		while(curl < l)
		{
			if(arr[curl] != 0)
			m[arr[curl]]--;
			
			if(m[arr[curl]] == 1)
			c--;
			
			curl++;
		}
		while(curl>l)
		{
			curl--;
		
			if(arr[curl] != 0)
			m[arr[curl]]++;
		
			if(m[arr[curl]] == 2)
			c++;
		}
		ans[p] = 2 * c;
	}
	
	for(auto i : ans)
	cout << i << endl;
}
signed main()
{
    cout << "( ) ) ( ( ) ) ( ( ) )  (" << endl;
    cout << "0 1 2 3 4 5 6 7 8 9 10 11" << endl;

    string s = "())(())(())(";
	int n = s.length();
	
	vector<pair<int,pair<int,int>>> Q = {{0 , {4 , 11}} , {1 , {4 , 5}} , {2 , {1 , 2}}};
	int q = Q.size();
	
	Queries(s , n , Q , q);
	
	return 0;
}

