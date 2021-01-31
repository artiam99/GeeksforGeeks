#include<bits/stdc++.h>
using namespace std;

void MLISS(vector<int> &a , int n)
{
	vector<int> b(n,1);
	
	vector<int> idx(n);  iota(idx.begin() , idx.end() , 0);
	
	for(int i = 1 ; i < n ; i++)
	for(int j = 0 ; j < i ; j++)
	if(a[j] < a[i])
	{
		if(b[j] >= b[i])
		{
			b[i] = b[j] + 1;
		
			idx[i] = j;
		}
		
	}
	
	cout << "Maximum length : " << *max_element(b.begin() , b.end()) << endl;
	
	vector<int> seq;
	
	int i = max_element(b.begin() , b.end()) - b.begin();
	
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
	
	MLISS(a , n);
	
	return 0;
}
