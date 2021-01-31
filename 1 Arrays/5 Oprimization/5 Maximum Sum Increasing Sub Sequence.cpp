#include<bits/stdc++.h>
using namespace std;

void MSISS(vector<int> &a , int n)
{
	vector<int> curmax = a;
	
	vector<int> idx(n);  iota(idx.begin() , idx.end() , 0);
	
	for(int i = 1 ; i < n ; i++)
	for(int j = 0 ; j < i ; j++)
	if(a[j] < a[i])
	{
		if(a[i] + curmax[j] > curmax[i])
		{
			curmax[i] = a[i] + curmax[j];
	
			idx[i] = j;
		}
	}
	
	cout << "Maximum Sum : " << *max_element(curmax.begin() , curmax.end()) << endl;
	
	vector<int> seq;
	
	int i = max_element(curmax.begin() , curmax.end()) - curmax.begin();
	
	seq.push_back(a[i]);
	
	while(i != idx[i])
	{
		seq.push_back(a[idx[i]]);
		
		i = idx[i];
	}
	
	for(auto i = seq.rbegin() ; i != seq.rend() ; i++)
	cout << *i << " ";
}

int main()
{
	vector<int> a = {1, 101, 2, 3, 100, 4, 5};
	int n = a.size();
	
	MSISS(a , n);
	
	return 0;
}

