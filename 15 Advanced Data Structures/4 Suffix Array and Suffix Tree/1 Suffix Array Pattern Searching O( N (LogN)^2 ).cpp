#include<bits/stdc++.h>
using namespace std;
struct suf
{
	int ind;
	int rank[2];
};
bool comp(suf s1 , suf s2)
{
	if(s1.rank[0] == s2.rank[0])
	return (s1.rank[1] < s2.rank[1]);
	
	return (s1.rank[0] < s2.rank[0]);
}
int* Construct(string &s , int n)
{
	suf Arr[n];
	
	for(int i = 0 ; i < n ; i++)
	{
		Arr[i].ind = i;
		
		Arr[i].rank[0] = s[i] - 'a';
		
		Arr[i].rank[1] = ((i == n-1) ? -1 : s[i+1] - 'a');
	}
	
	sort(Arr , Arr + n , comp);
	
	int ind[n];
	
	for(int k = 4 ; k < 2 * n ; k *= 2)
	{
		int rank = 0 , rank0 = Arr[0].rank[0] , rank1 = Arr[0].rank[1];
		
		Arr[0].rank[0] = rank;
		
		ind[Arr[0].ind] = 0;
		
		for(int i= 1 ; i < n ; i++)
		{
			if(Arr[i].rank[0] != rank0 || Arr[i].rank[1] != rank1)  rank++;
			
			rank0 = Arr[i].rank[0] , rank1 = Arr[i].rank[1];
			
			Arr[i].rank[0] = rank;
			
			ind[Arr[i].ind] = i;
		}
		
		for(int i = 0 ; i < n ; i++)
		{
			int next = Arr[i].ind + k/2;
			
			Arr[i].rank[1] = ((next < n) ? Arr[ind[next]].rank[0] : -1);
		}
		
		sort(Arr , Arr + n , comp);		
	}
	
	int* suffarr = new int[n];
	
	for(int i = 0 ; i < n ; i++)
	suffarr[i] = Arr[i].ind;
	
	return suffarr;
}
void Search(string &pat , int m , string &s , int n , int* suffarr)
{
	char str[n+1] , patt[m+1];
	
	strcpy(patt , pat.c_str());
	
	strcpy(str , s.c_str());
	
	int l = 0 , r = n-1;
	
	while(l <= r)
	{
		int mid = l + (r - l) / 2;
		
		int res = strncmp(patt , str + suffarr[mid] , m);
		
		if(res == 0)
		{
			cout << "Pattern Found at " << suffarr[mid] << endl;
			
			return;
		}
		
		else if(res == -1)  r = mid - 1;
		
		else  l = mid + 1;
	}
	
	cout << "Pattern not Found" << endl;
}
signed main()
{
	string s = "banana";
	int n = s.length();
	
	int* suffarr = Construct(s , n);
	
	string pat = "an";
	int m = pat.length();
	
	Search(pat , m , s , n , suffarr);
	
	return 0;
}
