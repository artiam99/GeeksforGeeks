#include<bits/stdc++.h>
using namespace std;
void constructDP(vector<int> &BOP , vector<int> &BCP , string &s , int n)
{
	stack<int> st;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(s[i] == '(')
		st.push(i);
		
		else
		{
			if(!st.empty())
			{
				BOP[st.top()+1] = 1;
				
				BCP[i+1] = 1;
				
				st.pop();
			}
		}
	}
	
	for(int i = 1 ; i <= n ; i++)
	{
		BOP[i] += BOP[i-1];
		BCP[i] += BCP[i-1];
	}
}

int Queries(vector<int> BOP , vector<int> BCP , int l , int r)
{
	if(BOP[l] == BOP[l-1])
	
	return (BCP[r] - BOP[l]) * 2;
	
	return (BCP[r] - BOP[l] + 1) * 2;
}

signed main()
{
    cout << "( ) ) ( ( ) ) ( ( ) )  (" << endl;
    cout << "0 1 2 3 4 5 6 7 8 9 10 11" << endl;

    string s = "())(())(())(";

	int n = s.length();
	
	vector<pair<int,int>> Q = {{4 , 11} , {4 , 5} , {1 , 2}};
	int q = Q.size();
	
	vector<int> BOP(n+1);
	vector<int> BCP(n+1);
	
	constructDP(BOP,BCP,s,n);
	
	cout << "BOP : ";
	
	for(auto i : BOP)
	cout << i << " ";
	cout << endl;
	
	cout << "BCP : ";
	for(auto i : BCP)
	cout << i << " ";
	cout << endl;
	
	for(int i = 0 ; i < q ; i++)
	cout << Queries(BOP , BCP , Q[i].first + 1 , Q[i].second + 1) << endl;
	
	return 0;
}

