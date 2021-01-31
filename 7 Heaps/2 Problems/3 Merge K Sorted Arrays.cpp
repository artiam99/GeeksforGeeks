#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
#define n 4
struct comp
{
    bool operator ()(pair<int,pair<int,int>> p1,pair<int,pair<int,int>> p2)
    {
        return p1.first>p2.first;
    }
};
int* mergeKArrays(int arr[][n], int k)
{
    int *a=new int[n*k];
    
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,comp> pq;
    
    for(int i=0;i<k;i++)
    pq.push({arr[i][0],{i,0}});
        
    int i=0;    
    while(pq.size())
    {
        a[i++]=pq.top().first;
        
        pair<int,int> p=pq.top().second;
        pq.pop();
        
        if(p.second+1<n)
        pq.push({arr[p.first][p.second+1],{p.first,p.second+1}});
    }
    return a;
}
signed main()
{
	int arr[][n] =  {{2, 6, 12, 34},
                     {1, 9, 20, 1000},
                     {23, 34, 90, 2000}};
                     
    int k = sizeof(arr)/sizeof(arr[0]);
    
    int *output = mergeKArrays(arr,k); 
   
    cout << "Merged array is " << endl; 
    
	for(int i=0;i<n*k;i++)
	cout<<output[i]<<" ";
	cout<<endl;
	
    return 0;
}
