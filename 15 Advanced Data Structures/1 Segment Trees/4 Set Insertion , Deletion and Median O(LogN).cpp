#include<bits/stdc++.h>
using namespace std;
class Set
{
	int Max , *st;
	public:
	Set(int mx)
	{
		Max = mx;
		
		int p = ceil(log2(Max+1)) , size = 2 * pow(2 , p) - 1;
		
		st = new int[size];  memset(st,0,sizeof(int)*size);
	}
	void Update(int sti , int l , int r , int x , int diff)  // how many numbers we have in range l to r
	{
		if(l == r && l == x)
		{
			if(!(st[sti] == 0 && diff == -1))  st[sti] += diff;
			
			return;
		}
		
		if(x >= l && x <= r)
		{
			int m = l + (r - l) / 2;
			
			Update(sti * 2 + 1 , l , m , x , diff);
			
			Update(sti * 2 + 2 , m + 1 , r , x , diff);
			
			st[sti] = st[sti * 2 + 1] + st[sti * 2 + 2];
		}
	}
	int Find_Kth(int sti , int l , int r , int k)
	{
		if(l == r)  return ((st[sti]) ? l : -1);
		
		int m = l + (r - l) / 2;
		
		if(st[sti * 2 + 1] >= k)  return Find_Kth(sti * 2 + 1 , l , m , k);
		
		return Find_Kth(sti * 2 + 2 , m + 1 , r , k - st[sti * 2 + 1]);
	}
	void Insert(int x)
	{
		Update(0 , 0 , Max , x , 1);
	}
	void Delete(int x)
	{
		Update(0 , 0 , Max , x , -1);
	}
	int Median()
	{
		int k = (st[0] + 1) / 2;
		
		return Find_Kth(0 , 0 , Max , k);
	}
};
signed main()
{
	Set s(10); // Set Can Carry values from 0 to 10
	
	s.Insert(4);  s.Insert(7);  s.Insert(8);  s.Insert(9);  s.Insert(1);
	
	cout << s.Median() << endl;
	
	s.Delete(8);
	
	cout << s.Median() << endl;
	
	return 0;
}
