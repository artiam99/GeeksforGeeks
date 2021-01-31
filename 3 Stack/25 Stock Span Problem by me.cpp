#include <bits/stdc++.h> 
using namespace std;

void Stock_Span(vector<int> &a , int n)
{
	vector<int> b(n+1);
	
	b[0] = std::numeric_limits<int>::max();
	
	for(int i = 1 ; i <= n ; i++)
	b[i] = a[i-1];
	
	vector<int> p(n+1);
	
	for(int i = 0 ; i <= n ; i++)
	p[i] = i-1;
	
	for(int i = 1 ; i <= n ; i++)
	{
		int x = i;
		
		while(a[p[x]] <= a[i])
		x = p[x];
		
		p[i] = p[x];
	}
	
	for(int i = 1 ; i <= n ; i++)
	cout << i - p[i] << " ";
	cout << endl;
}

int main() 
{ 
	vector<int> a = {100, 80, 60, 70, 60, 75, 85};
	int n = a.size();
	
	Stock_Span(a , n);
	
	return 0; 
} 

