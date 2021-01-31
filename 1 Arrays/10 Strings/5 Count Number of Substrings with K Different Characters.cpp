#include<bits/stdc++.h>
using namespace std;
	
int Count(string &a , int k)
{
	long long int n = a.length();
        
	int alpha[26];  memset(alpha , 0 , sizeof(alpha));
    
    int i = 0 , j = 0 , Size = 0;
    
    long long int greater = 0;
    
    while(i < n)
    {
        alpha[a[i] - 'a']++;
        
        if(alpha[a[i] - 'a'] == 1)
        Size++;
        
        if(Size > k)
        {
        
            while(Size > k)
            {
                alpha[a[j] - 'a']--;
                
                if(alpha[a[j] - 'a'] == 0)  Size--;
                
                j++;
            }
            
            greater += j;
            
            j--;
            
            alpha[a[j] - 'a']++;
            
            if(alpha[a[j] - 'a'] == 1)
            Size++;
        }
        i++;
    }
    
    i = 0 , j = 0 , Size = 0;
    
    long long int smaller = 0;
    
    memset(alpha , 0 , sizeof(alpha));
    
    while(i < n)
    {
        alpha[a[i] - 'a']++;
        
        if(alpha[a[i] - 'a'] == 1)
        Size++;
        
        if(Size >= k)
        {
        
            while(Size >= k)
            {
                alpha[a[j] - 'a']--;
                
                if(alpha[a[j] - 'a'] == 0)  Size--;
                
                j++;
            }
            
            j--;
            
            smaller += (i - j);
            
            alpha[a[j] - 'a']++;
            
            if(alpha[a[j] - 'a'] == 1)
            Size++;
        }
        else
        smaller += (i+1);
        
        i++;
    }
    
    return (((n * (n + 1)) / 2) - (greater + smaller));
}
signed main()
{
	string s = "aba";
	int k = 2;
	
	cout << Count(s , k) << endl;
	
	return 0;
}
