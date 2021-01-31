#include<bits/stdc++.h>
using namespace std;
int Max_Sum(vector<int> &a,int n,int k)
{
	priority_queue<int> pq;
	    
    int sum_pos = 0 , sum_neg = 0 , max_neg = INT_MIN , min_pos = INT_MAX , cnt_neg = 0 , zero = 0;
    
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] < 0)
        {
            cnt_neg++;
            
            sum_neg += a[i];
            
            max_neg = max(max_neg , a[i]);
            
            if(pq.size() < k)
            pq.push(a[i]);
                
            else if(pq.top() > a[i])
            {
                pq.pop();
                
                pq.push(a[i]);
            }
        }
        
        else if(a[i] == 0)
        zero = 1;
        
        else
        {
            sum_pos += a[i];
            
            min_pos = min(min_pos , a[i]);
        }
    }
    
    if(cnt_neg == 0)
    {
        if(zero || !(k & 1))  return sum_pos;
        
        else  return sum_pos - ((min_pos != INT_MAX) ? min_pos * 2 : 0);
    }
    else
    {
        if(cnt_neg <= k)
        {
            sum_neg *= -1;
            
            k -= cnt_neg;
            
            if(zero || !(k & 1))  return sum_pos + sum_neg;
            
            else
            {
                min_pos = min(min_pos,-1 * max_neg);
                
                return sum_pos + sum_neg - 2 * min_pos;
            }
        }
        else
        {
            while(pq.size())
            sum_neg -= 2 * pq.top() , pq.pop();
            
            return sum_pos + sum_neg;
        }
    }
}
signed main()
{
	vector<int> a = {-9, -8, -7, -5};
	int n = a.size();
	
	int k = 2;
	
	cout<< Max_Sum(a,n,k) << endl;
	
	return 0;
}
