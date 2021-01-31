#include<bits/stdc++.h>
using namespace std;
#define int long long
void StableMarriage(vector<vector<int>> &M,vector<vector<int>> &W,int n)
{
	vector<bool> FreeMen(n,false);
	
	vector<int> WomenMatch(n,-1);
	
	int freemen = n;
	
	while(freemen)
	{
		int m=0;
		for(; m < n; m++)
		if(!FreeMen[m])
		break;
		
		for(int i=0;i<n && !FreeMen[m];i++)
		{
			int w=M[m][i];
			
			if(WomenMatch[w] == -1)
			{
				WomenMatch[w] = m;
				FreeMen[m]=true;
				freemen--;
			}
			
			else
			{
				int m1=WomenMatch[w];
				
				int j=0;
				for(;j<n;j++)
				if(W[w][j]==m1 || W[w][j]==m)
				break;
				
				if(W[w][j] == m)
				{
					WomenMatch[w]=m;
					FreeMen[m]=true;
					FreeMen[m1] = false;
				}
			}
		}
	}
	
	cout<<"Women  Men"<<endl;
	for(int i=0;i<n;i++)
	cout<<"  "<<i<<"     "<<WomenMatch[i]<<endl;
}
signed main()
{
	vector<vector<int>> M = { {3, 1, 2, 0}, 
        					  {1, 0, 2, 3}, 
      						  {0, 1, 2, 3}, 
      						  {0, 1, 2, 3} };
    
	vector<vector<int>> W = { {0, 1, 2, 3}, 
    						  {0, 1, 2, 3}, 
      						  {0, 1, 2, 3}, 
      						  {0, 1, 2, 3} };
	
	int n=M.size();
	
	StableMarriage(M,W,n);
	
	return 0;
}
