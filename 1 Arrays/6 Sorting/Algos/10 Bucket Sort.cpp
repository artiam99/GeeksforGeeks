#include<bits/stdc++.h>
using namespace std;

void bucketsort(vector<float> &a , int n)
{
	vector<float> b[n];
	
	for(int i = 0 ; i < n ; i++)
	b[(int)(n * a[i])].push_back(a[i]);

	
	for(int i = 0 ; i < n ; i++)
	sort(b[i].begin() , b[i].end());
	
	
	int p = 0;
	
	for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j < b[i].size() ; j++)
	a[p++] = b[i][j];
}

int main() 
{
	vector<float> a = {0.78, 0.89, 0.34, 0.56, 0.68, 0.45, 0.72};
	int n = a.size();

	bucketsort(a , n);

	for(int i = 0 ; i < n ; i++)
	cout << a[i] << " ";
	cout << endl;

    return 0; 
}

