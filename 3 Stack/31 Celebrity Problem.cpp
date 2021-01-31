#include <bits/stdc++.h> 
using namespace std;
#define Max 100

int getID(int party[][Max] , int n)
{
	stack<int> s;
	
	for(int i = 0 ; i < n ; i++)
	s.push(i);
	
	while(1)
	{
		int p = s.size();
		
		int a = s.top();
		
		s.pop();
		
		int b = s.top();
		
		s.pop();
		
		if(p == 2)
		{
			if(party[a][b] == 1 && party[b][a] == 0)
			return b;
		
			else if(party[a][b] == 0 && party[b][a] == 1)
			return a;
		
			return -1;
		}
		
		if(party[a][b] == 1)
		s.push(b);
		
		else
		s.push(a);
	}
}

int main() 
{ 
	int party1[Max][Max] = { {0, 0, 1, 0},
                             {0, 0, 1, 0},
                             {0, 0, 0, 0},
                             {0, 0, 1, 0} };
                     
    int party2[Max][Max] = { {0, 0, 1, 0},
                             {0, 0, 1, 0},
                             {0, 1, 0, 0},
                             {0, 0, 1, 0} };
	int n = 4;
	
	cout << "Party 1 : " << getID(party1 , n) << endl;
	cout << "Party 2 : " << getID(party2 , n) << endl;
	
	return 0; 
} 

