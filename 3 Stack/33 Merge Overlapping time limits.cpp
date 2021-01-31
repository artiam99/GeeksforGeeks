#include <bits/stdc++.h>
using namespace std;

void Merge(vector<pair<int,int>> &a , int n)
{
	sort(a.begin() , a.end());
	
	vector<pair<int,int>> b;

	b.push_back(a[0]);
    
    int in = 0;

	for(int i = 1 ; i < n ; i++)
	{
		if(b[in].second >= a[i].first)
		b[in].second = max(a[i].first , b[in].second);
		
		else
		{
			b.push_back(a[i]);
		
			in++;
		}
	}

	for(auto i : b)
	cout << i.first << " " << i.second << endl;
}

int main()
{		
	vector<pair<int,int>> a = {{6 , 8} , {3 , 9} , {3 , 4} , {1 , 2} , {10 , 13} , {4 , 7}};
	int n = a.size();

	Merge(a , n);	
	
	return 0;
}

