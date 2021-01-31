#include<bits/stdc++.h>
using namespace std;
static vector<int> cx = {2 , 2 , -2 , -2 , 1 , 1 , -1 , -1};
static vector<int> cy = {1 , -1 , 1 , -1 , 2 , -2 , 2 , -2};
int accesibility(int x,int y,int N,vector<vector<int>> &A)
{
	int acs = 0;
	
	for(int i = 0 ; i < 8 ; i++)
	{
		int x1 = x + cx[i];
		int y1 = y + cy[i];
		
		if(x1 >= 0 && y1 >= 0 && x1 < N && y1 < N && A[x1][y1] == -1)
		acs++;
	}
	return acs;
}
bool next_pos(int &x,int &y,int N,vector<vector<int>> &A)
{
	int xp = x , yp = y;
	
	bool flag = false;
	
	int s = rand() % 8;
	
	int mn = INT_MAX;
	
	for(int i = 0 ; i < 8 ; i++)
	{
		int j = (s + i) % 8;
		
		int x1 = xp + cx[j];
		int y1 = yp + cy[j];
		
		if(x1 >= 0 && y1 >= 0 && x1 < N && y1 < N && A[x1][y1] == -1)
		{
			int acs = accesibility(x1,y1,N,A);
			
			if(mn > acs)
			{
				x = x1 ; y = y1 ;
				
				mn = acs;
				
				flag = true;
			}
		}
	}
	return flag;
}
bool Tour(int N,vector<vector<int>> &A)
{	
	for(auto &i:A)
	for(auto &j:i)
	j = -1;

	int x = 0;
	int y = 0;
	
	A[x][y] = 0;
	
	int cnt = 0;
	
	while(next_pos(x,y,N,A))
	A[x][y] = ++cnt;
	
	return (cnt == N*N - 1);
}
void KnightsTour(int N)
{
	srand(time(NULL));
	
	vector<vector<int>> A(N,vector<int>(N,-1));
	
	while(!Tour(N,A))
	{
		;
	}
	
	for(auto i:A)
	{
		for(auto j:i)
		cout<< j << "    ";
		cout<< endl << endl;
	}
}
signed main()
{
	int N = 8;
	
	KnightsTour(N);
	
	return 0;
}
