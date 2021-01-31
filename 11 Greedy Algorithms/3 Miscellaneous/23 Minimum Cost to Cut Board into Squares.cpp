#include<bits/stdc++.h>
using namespace std;
int Min_Cost(vector<int> &len,int l,vector<int> &bdt,int b)
{	
	sort(len.begin(),len.end(),greater<int>());
	
	sort(bdt.begin(),bdt.end(),greater<int>());
	
	int il = 0 , ib = 0 , currl = 1 ,currb = 1 , cost = 0;
	
	while(il < l && ib < b)
	{
		if(len[il] > bdt[ib])
		{
			cost += len[il++] * currb;
			
			currl++;
		}
		else
		{
			cost += bdt[ib++] * currl;
			
			currb++;
		}
	}
	
	while(il < l)
	cost += len[il++] * currb;
	
	while(ib < b)
	cost += bdt[ib++] * currl;
	
	return cost;
}
signed main()
{
	vector<int> len = {2, 1, 3, 1, 4};
	int l = len.size();
	
	vector<int> bdt = {4,1,2};
	int b = bdt.size();
	
	cout<< Min_Cost(len,l,bdt,b) << endl;
	
    return 0;
}
