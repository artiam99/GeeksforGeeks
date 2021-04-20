#include<bits/stdc++.h>
using namespace std;
int Max_Height(vector<int> &a,int n)
{
	sort(a.begin() , a.end());
	
	int ans = 1;
	
	int prev_cnt = 1 , prev_wid = a[0];
	
	int curr_cnt = 0 , curr_wid = 0;
	
	for(int i = 1 ; i < n ; i++)
	{
		curr_cnt++;  curr_wid += a[i];
		
		if(curr_cnt > prev_cnt && curr_wid > prev_wid)
		{
			prev_cnt = curr_cnt;  prev_wid = curr_wid;
			
			curr_cnt = curr_wid = 0;
			
			ans++;
		}
	}
	return ans;
}
signed main()
{
	vector<int> a = {20 , 100 , 50};
	int n = a.size();
	
	cout<< Max_Height(a,n) << endl;
	
	return 0;
}
