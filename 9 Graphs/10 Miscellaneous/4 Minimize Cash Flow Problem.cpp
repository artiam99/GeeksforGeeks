#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
void Minimize(vector<int> &amount,vector<vector<int>> &Flow)
{	
	int mxCredit = max_element(amount.begin(),amount.end()) - amount.begin();
	
	int mxDebit = min_element(amount.begin(),amount.end()) - amount.begin();
	
	if(amount[mxCredit]==0 && amount[mxDebit] == 0)
	return;
	
	int mn = min(amount[mxCredit] , -amount[mxDebit]);
	
	amount[mxCredit] -= mn;
	amount[mxDebit] += mn;
	
	Flow[mxDebit][mxCredit] = mn;
	
	Minimize(amount,Flow);
}
void MinimizeFlow(vector<vector<int>> &Flow,int n)
{
	vector<int> amount(n);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		amount[i] += Flow[j][i] - Flow[i][j];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		Flow[i][j]=0;
	}
	
	Minimize(amount,Flow);
}
signed main()
{
	vector<vector<int>> Flow={  {0, 1000, 2000}, 
                  		        {0, 0   , 5000}, 
                   		        {0, 0   , 0   } };
    int n=Flow.size();
    
    MinimizeFlow(Flow,n);
    
    for(auto i:Flow)
    {
    	for(auto j:i)
    	cout<<j<<" ";
    	cout<<endl;
	}
	
	return 0;
}
