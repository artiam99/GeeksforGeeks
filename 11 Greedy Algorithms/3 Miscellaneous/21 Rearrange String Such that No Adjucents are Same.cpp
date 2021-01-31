#include<bits/stdc++.h>
using namespace std;
string Rearrange(string s,int n)
{
	int alpha[26];  memset(alpha,0,sizeof(alpha));
	
	for(int i = 0 ; i < n ; i++)
	alpha[s[i] - 'a']++;
	
	priority_queue<pair<int,char>> pq;
	
	for(int i = 0 ; i < 26 ; i++)
	if(alpha[i] != 0)
	pq.push({alpha[i] , i+'a'});
	
	pair<int,char> prev={0,'@'};
	
	s.clear();
	
	while(pq.size())
	{
		pair<int,char> curr = pq.top();
		
		pq.pop();
		
		s += curr.second;
		
		curr.first--;
		
		if(prev.first)
		pq.push(prev);
		
		prev = curr;
	}
	if(s.length() != n)
	return "-1";
	
	return s;
}
signed main()
{
	string s = "geeksforgeeks";
	int n = s.length();
	
	cout<< Rearrange(s,n) << endl;
	
    return 0;
}
