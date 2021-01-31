#include<bits/stdc++.h>
using namespace std;

void Max_Overlap(vector<int> &entry , vector<int> &exit , int n)
{
	sort(entry.begin() , entry.end());
	sort(exit.begin() , exit.end());
	
	int cnt = 0 , i = 0 , j = 0 , mx = 0 , time;
	
	while(i < n && j < n)
	{
		if(entry[i] <= exit[j])
		{
			cnt++;
			
			if(mx < cnt)
			{
				time = entry[i];
				
				mx = cnt;
			}
			
			i++;
		}
		else
		{
			cnt--;
			
			j++;
		}
	}
	
	cout << "Max Overlap is : " << mx << " at time : " << time << endl;
}

signed main()
{
	vector<int> entry = {1, 2, 10, 5, 5};
	vector<int> exit = {4, 5, 12, 9, 12};
	int n = entry.size();
	
	Max_Overlap(entry , exit , n);
	
	return 0;
}
