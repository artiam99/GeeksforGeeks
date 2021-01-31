#include<bits/stdc++.h>
using namespace std;
void Fill(vector<vector<int>> &a,int n,pair<int,int> p,int x,int y,int &no)
{	
	pair<int,int> fst , snd , trd , fth;
	
	if(p.first - x < (n / 2))
	{
		if(p.second - y < (n / 2))
		{
			fst = p , snd = {n/2 - 1 + x , n/2 + y} , trd = {n/2 + x, n/2 - 1 + y} , fth = {n/2 + x , n/2 + y};
			
			a[snd.first][snd.second] = a[trd.first][trd.second] = a[fth.first][fth.second] = no++;
		}
		
		else
		{
			fst = {n/2 - 1 + x , n/2 - 1 + y} , snd = p , trd = {n/2 + x , n/2 - 1 + y} , fth = {n/2 + x , n/2 + y};
			
			a[fst.first][fst.second] = a[trd.first][trd.second] = a[fth.first][fth.second] = no++;
		}
	}
	
	else
	{
		if(p.second - y < (n / 2))
		{
			fst = {n/2 - 1 + x , n/2 - 1 + y} , snd = {n/2 - 1 + x , n/2 + y} , trd = p , fth = {n/2 + x , n/2 + y};
			
			a[fst.first][fst.second] = a[snd.first][snd.second] = a[fth.first][fth.second] = no++;
		}
		
		else
		{
			fst = {n/2 - 1 + x , n/2 - 1 + y} , snd = {n/2 - 1 + x , n/2 + y} , trd = {n/2 + x , n/2 - 1 + y} , fth = p;
			
			a[fst.first][fst.second] = a[snd.first][snd.second] = a[trd.first][trd.second] = no++;
		}
	}
	
	if(n == 2)  return;
	
	Fill(a , n/2 , fst , x + 0 , y + 0 , no);
	Fill(a , n/2 , snd , x + 0 , y + n/2 , no);
	Fill(a , n/2 , trd , x + n/2 , y + 0 , no);
	Fill(a , n/2 , fth , x + n/2 , y + n/2 , no);
}
void Fill_Tile(int n,pair<int,int> p)
{
	vector<vector<int>> a(n,vector<int>(n));
	
	int no = 1;
	
	Fill(a,n,p,0,0,no);
	
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			if(a[i][j] < 10)
			cout<< " ";
			
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	srand(time(NULL));
	
    int n = 16;
    
    pair<int,int> p = { rand() % n , rand() % n };
    
    Fill_Tile(n,p);
 
    return 0;
}
