#include<bits/stdc++.h>
using namespace std;
bool Tour(int i,int j,int moves,int &N,vector<vector<int>> &A)
{
	A[i][j] = moves++;
	
	if(moves == N*N)  return true;
	
	if(i+2 < N && j+1 < N && A[i+2][j+1] == -1 && Tour(i+2,j+1,moves,N,A))  return true;
	
	if(i+2 < N && j-1 >= 0 && A[i+2][j-1] == -1 && Tour(i+2,j-1,moves,N,A))  return true;
	
	if(i-2 >= 0 && j+1 < N && A[i-2][j+1] == -1 && Tour(i-2,j+1,moves,N,A))  return true;
	
	if(i-2 >= 0 && j-1 >= 0 && A[i-2][j-1] == -1 && Tour(i-2,j-1,moves,N,A))  return true;
	
	if(i+1 < N && j+2 < N && A[i+1][j+2] == -1 && Tour(i+1,j+2,moves,N,A))  return true;
	
	if(i+1 < N && j-2 >= 0 && A[i+1][j-2] == -1 && Tour(i+1,j-2,moves,N,A))  return true;
	
	if(i-1 >= 0 && j+2 < N && A[i-1][j+2] == -1 && Tour(i-1,j+2,moves,N,A))  return true;
	
	if(i-1 >= 0 && j-2 >= 0 && A[i-1][j-2] == -1 && Tour(i-1,j-2,moves,N,A))  return true;
	
	A[i][j] = -1;
	
	return false;
}
void KnightsTour(int N)
{
	vector<vector<int>> A(N,vector<int>(N,-1));
	
	if(!Tour(0,0,0,N,A))
	{
		cout<< "Not Possible" << endl;
		
		return;
	}
	
	for(auto i:A)
	{
		for(auto j:i)
		cout<< j << " ";
		cout<< endl;
	}
}
signed main()
{
	int N = 7;
	
	KnightsTour(N);
	
	return 0;
}
