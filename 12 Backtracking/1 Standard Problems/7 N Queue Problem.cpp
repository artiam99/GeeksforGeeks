#include<bits/stdc++.h>
using namespace std;
void Rec(int n,int c,vector<int> &a,bool &flag1)
{
    if(c == n)
    {
        flag1 = true;
        
        cout<< "[";  for(auto i : a)  cout<< i+1 << " ";  cout<< "] ";
        
        return;
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        bool flag = true;
        
        for(int j = 0 ; j < a.size() ; j++)
        if(i == a[j] || c - i == j - a[j] || (n-c) - i == (n-j) - a[j])
        {
            flag = false;
            
            break;
        }
        
        if(flag)
        {
            a.push_back(i);
            
            Rec(n,c+1,a,flag1);
            
            a.pop_back();
        }
        
    }
}
void NQueue(int N)
{
	vector<int> a;
	    
    bool flag1 = false;
    
    Rec(N,0,a,flag1);
    
    if(!flag1)
    cout<< -1;
    
    cout<< endl;
}
signed main()
{
	int N = 4;
	
	NQueue(N);
	
	return 0;
}
