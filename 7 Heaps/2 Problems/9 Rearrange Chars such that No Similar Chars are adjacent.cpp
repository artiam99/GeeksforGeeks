#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
string Rearrange(string s)
{
	vector<int> alpha(26,0);
	
	for(int i=0;i<s.length();i++)
	alpha[s[i] - 'a']++;
	
	priority_queue<pair<int,char>> pq;
	
	for(int i=0;i<26;i++)
	if(alpha[i]!=0)
	pq.push({alpha[i],i+'a'});
	
	pair<int,char> prev={0,'@'};
	
	s.clear();
	
	while(pq.size())
	{
		pair<int,char> curr=pq.top();
		
		pq.pop();
		
		s+=curr.second;
		
		curr.first--;
		
		if(prev.first)
		pq.push(prev);
		
		prev=curr;
	}
	
	return s;
}
signed main()
{
	string s="aabbbabacd";
	
	int n=s.length();
	
	s=Rearrange(s);
	
	if(s.length()==n)
	cout<<s<<endl;
	else
	cout<<"Not Possible"<<endl;
	
	return 0;
}
