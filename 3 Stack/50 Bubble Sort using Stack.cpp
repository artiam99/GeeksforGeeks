#include<bits/stdc++.h>
using namespace std;
void bubble(vector<int> &a,int n)
{
	stack<int> s1;
	
	stack<int> s2;
	
	for(int i = 0 ; i < n ; i++)
	s1.push(a[i]);
	
	for(int i = 0 ; i < n ; i++)
	{
		if(i % 2 == 0)
		{
			while(!s1.empty())
			{
				if(s2.empty() || s2.top() <= s1.top())
				{
					s2.push(s1.top());
				
					s1.pop();
				}

				else
				{
					int a = s1.top();

					s1.pop();

					int b = s2.top();

					s2.pop();

					s1.push(b);

					s2.push(a);
				}
			}
			a[n-1-i] = s2.top();
		
			s2.pop();
		}
		
		else
		{
			while(!s2.empty())
			{
				if(s1.empty() || s1.top() <= s2.top())
				{
					s1.push(s2.top());
					
					s2.pop();
				}
				
				else
				{
					int a = s2.top();
				
					s2.pop();
				
					int b = s1.top();
				
					s1.pop();
				
					s2.push(b);
				
					s1.push(a);
				}
			}
			a[n-1-i] = s1.top();
			
			s1.pop();
		}
	}
}

signed main()
{
	vector<int> a = {5, 4, 1, 3, 2};
	int n = a.size();

	bubble(a , n);
	
	for(auto i : a)
	cout << i << " ";
	cout << endl;
	
	return 0;
}

