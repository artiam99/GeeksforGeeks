#include<bits/stdc++.h>
using namespace std;
int Max_Sum(vector<int> &s1,int n1,vector<int> &s2,int n2,vector<int> &s3,int n3)
{
	for(int i = n1-2 ; i >= 0 ; i--)
	s1[i] += s1[i+1];
	
	for(int i = n2-2 ; i >= 0 ; i--)
	s2[i] += s2[i+1];
	
	for(int i = n3-2 ; i >= 0 ; i--)
	s3[i] += s3[i+1];
	
	int i1 = 0 , i2 = 0 , i3 = 0;
	
	while(i1 < n1 && i2 < n2 && i3 < n3)
	{
		if(s1[i1] == s2[i2] && s2[i2] == s3[i3])
		return s1[i1];
		
		if(s1[i1] >= s2[i2] && s1[i1] >= s3[i3])
		i1++;
		
		else if(s2[i2] >= s1[i1] && s2[i2] >= s3[i3])
		i2++;
		
		else if(s3[i3] >= s1[i1] && s3[i3] >= s2[i2])
		i3++;
	}
	
	return 0;
}
signed main()
{
	vector<int> s1 = { 3, 2, 1, 1, 1 };
	int n1 = s1.size();
 
    vector<int> s2 = { 4, 3, 2 };
	int n2 = s2.size();
	
    vector<int> s3 = { 1, 1, 4, 1 };
    int n3 = s3.size();
    
    cout<< Max_Sum(s1,n1,s2,n2,s3,n3) <<endl;
    
    return 0;
}
