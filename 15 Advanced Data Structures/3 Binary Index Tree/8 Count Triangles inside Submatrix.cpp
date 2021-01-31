#include <bits/stdc++.h> 
using namespace std;
int BIT[100][100];
int Get_Points(int x , int y)
{
	int sum = 0;
	
	for(int i = x+1 ; i > 0 ; i -= (i & -i))
	for(int j = y+1 ; j > 0 ; j -= (j & -j))
	sum += BIT[i][j];
	
	return sum;
}
void Update(int x , int y)
{
	for(int i = x+1 ; i < 100 ; i += (i & -i))
	for(int j = y+1 ; j < 100 ; j += (j & -j))
	BIT[i][j] += 1;
}
int Find_Triangles(int x1 , int y1 , int x2 , int y2)
{
	int n = Get_Points(x1-1 , y1-1) - Get_Points(x1-1 , y2) - Get_Points(x2 , y1 - 1) + Get_Points(x2 , y2);
	
	return ((n * (n - 1) * (n - 2)) / 6);
}
int main() 
{
	memset(BIT,0,sizeof(BIT));
	
	Update(2, 2);
    Update(3, 5);
    Update(4, 2);
    Update(4, 5);
    Update(5, 4);
	
	cout << "No. of triangles in the rectangle (1, 1) & (6, 6) are : " << Find_Triangles(1, 1, 6, 6) << endl;
 
    Update(3, 3);
 
    cout << "No. of triangles in the rectangle (1, 1) & (6, 6) are: " << Find_Triangles(1, 1, 6, 6) << endl;
	
	return 0; 
} 

