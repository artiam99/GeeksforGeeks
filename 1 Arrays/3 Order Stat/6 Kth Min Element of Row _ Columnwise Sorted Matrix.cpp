#include <bits/stdc++.h> 
using namespace std;

int Kth_Min(vector<vector<int>> &a , int n , int k)
{
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
	
	pq.push({a[0][0] , {0,0}});

	set<pair<int,int>> s;
	
	s.insert({0 , 0});
	
	for(int c = 0 ; c < k - 1 ; c++)
	{
		pair<int,pair<int,int>> temp = pq.top();
		
		pq.pop();
		
		int i = temp.second.first;
		
		int j = temp.second.second;
		
		pair<int,int> temp1;
		
		if(i + 1 < n)
		{
			temp1 = {i + 1 , j};
		
		    if(s.find(temp1) == s.end())
		    {
			    s.insert(temp1);
			    
		    	pq.push({a[temp1.first][temp1.second] , {temp1.first , temp1.second}});
	    	}
		}
		
		if(j + 1 < n)
		{
			temp1 = {i , j + 1};
		
	     	if(s.find(temp1) == s.end())
    		{
    			s.insert(temp1);
    			
	    		pq.push({a[temp1.first][temp1.second] , {temp1.first , temp1.second}});
	    	}
		}
	}
	
	return pq.top().first;
}

int main() 
{
	srand(time(NULL));
	
	vector<vector<int>> a = { {1 , 2 , 6 , 7 },
							  {3 , 5 , 8 , 13},
							  {4 , 9 , 12, 14},
							  {10, 11, 15, 16} };
	int n = 4;
	int k = rand() % (16) + 1;
	
	cout << k << " " << Kth_Min(a , n , k) << endl;
	
	return 0; 
}
