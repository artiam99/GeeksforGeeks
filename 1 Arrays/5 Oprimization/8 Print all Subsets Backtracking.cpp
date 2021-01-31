#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> &a1 , vector<int> &a2)
{
	int n1 = a1.size();
	int n2 = a2.size();
	
	int i = 0 , j = 0;
	
	while(i < n1 && j < n2)
	{
		if(a1[i] < a2[j])
		return true;
		
		else if(a1[i] > a2[j])
		return false;
		
		i++;
		
		j++;
	}

	if(i == n1)
	return true;

	return false;
}

void All_Subset(int pos , int n , vector<int> &subset , vector<int> &a , vector<vector<int>> &s)
{
	if(pos == n)
	{
		s.push_back(subset);
		
		return;
	}
	
	All_Subset(pos + 1 , n , subset , a , s);
	
	subset.push_back(a[pos]);
	
	All_Subset(pos + 1 , n , subset , a , s);
	
	subset.pop_back();
}

void Print(vector<int> &a , int n)
{
	vector<int> subset;
	
	vector<vector<int>> s;
	
	All_Subset(0 , n , subset , a , s);
	
	sort(s.begin() , s.end() , compare);
	
	for(auto i : s)
	{
		if(i.size() == 0)
		{
			cout << "NULL" << endl;
			
			continue;
		}
		
		for(auto j : i)
		cout << j << " ";
		cout << endl;
	}
}

int main()
{
	vector<int> a = {5, 4, 8, 1};
	int n = a.size();
	
	Print(a , n);
	
	return 0;
}
