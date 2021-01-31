#include<bits/stdc++.h>
using namespace std;
int Largest_Cube(int N)
{
	vector<string> Cubes;
	
	for(int i = 1 ; i * i * i <= N ; i++)
	Cubes.push_back(to_string(i * i * i));
	
	string num = to_string(N);
	
	int mx = -1;
	
	for(auto i:Cubes)
	{
		int ind = 0;
		
		for(int j = 0 ; j < num.size() ; j++)
		if(ind < i.length() && num[j] == i[ind])
		ind++;
		
		if(ind == i.length())
		mx = max(mx , stoi(i));
	}
	
	return mx;
}
signed main()
{
	int N = 4125;
	
	cout<< Largest_Cube(N) <<endl;
	
    return 0;
}
