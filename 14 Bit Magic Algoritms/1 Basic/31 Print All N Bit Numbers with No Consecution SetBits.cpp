#include <bits/stdc++.h> 
using namespace std;
void Print(int n)
{
	n = (1 << n) - 1;
    
    queue<int> q;
    
    q.push(1);
    
    while(q.size())
    {
        int i = q.front();  q.pop();
        
        cout<< i << " ";
        
        if((i << 1) <= n)  q.push((i << 1));
        
        if(!(i & 1) && ((i << 1) + 1) <= n)  q.push((i << 1)+1);
    }
    
    cout<< endl;
}
int main() 
{
	int n = 4;
	
	Print(n);
	
	return 0; 
}
