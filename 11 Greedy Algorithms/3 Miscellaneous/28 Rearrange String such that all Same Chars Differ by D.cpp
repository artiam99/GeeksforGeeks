#include<bits/stdc++.h>
using namespace std;
string Rearrange(string &s,int n,int d)
{
	int freq[26];  memset(freq,0,sizeof(freq));
	
	int dist[26];  memset(dist,0,sizeof(dist));
	
	for(int i = 0 ; i < n ; i++)
	freq[s[i]-'a']++;
	
	for(int i = 0 ; i < n ; i++)
	{
		int next_available_char = -1;
		
		for(int j = 0 ; j < 26 ; j++)
		if(dist[j] <= 0 && freq[j] > 0 && (next_available_char == -1 || freq[next_available_char] < freq[j]))
		next_available_char = j;
		
		if(next_available_char == -1)
		return "Not Possible";
		
		s[i] = 'a' + next_available_char;
		
		freq[next_available_char]--;
		
		dist[next_available_char] = d;
		
		for(int j = 0 ; j < 26 ; j++)
		dist[j]--;
	}
	return s;
}
signed main()
{
	string s = "aabbcc";
	int n = s.length();
	int d = 2;
	
	cout<< Rearrange(s,n,d) << endl;
	
    return 0;
}
