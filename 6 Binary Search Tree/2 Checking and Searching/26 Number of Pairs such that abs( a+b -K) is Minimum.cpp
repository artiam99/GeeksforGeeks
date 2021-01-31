#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int x)
	{
		data=x;
		left=right=NULL;
	}
};
void findPairs(int a[],int n,int k)
{
	sort(a,a+n);
	
	int min_val=INT_MAX;
	
	int l=0,r=n-1;
	
	while(l<r)
	{
		min_val = min(min_val , abs(a[l] + a[r] - k));
		
		if(a[l]+a[r]<k)
		l++;
		
		else if(a[l]+a[r]>k)
		r--;
		
		else
		break;
	}
	
	map<int,int> m;
	for(int i=0;i<n;i++)
	m[a[i]]++;
	
	int c=0;
	
	if(min_val==0)
	{
		for(int i=0;i<n;i++)
		{
			while(i!=n-1 && a[i]==a[i+1])
			i++;
			
			if(binary_search(a+i+1,a+n,k-a[i]))
			c+=m[a[i]]*m[k-a[i]];
		}
		
		if( !(k & 1) && binary_search(a , a + n , k / 2) && m[k / 2] > 1)
		c+=((m[k / 2] * (m[k / 2] - 1)) / 2);
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			while(i!=n-1 && a[i]==a[i+1])
			i++;
			
			if(binary_search(a + i + 1 , a + n , k + min_val - a[i]))
			c+=m[a[i]]*m[k + min_val - a[i]];
		}
		
		if( !((k + min_val) & 1) && binary_search(a , a + n , (k + min_val) / 2) && m[(k + min_val) / 2] > 1)
		c+=((m[(k + min_val) / 2] * (m[(k + min_val) / 2] - 1)) / 2);
		
		for(int i=0;i<n;i++)
		{
			while(i!=n-1 && a[i]==a[i+1])
			i++;
			
			if(binary_search(a + i + 1 , a + n , k - min_val - a[i]))
			c+=m[a[i]]*m[k - min_val - a[i]];
		}
		
		if( !((k - min_val) & 1) && binary_search(a ,a + n, (k - min_val) / 2) && m[(k - min_val) / 2] > 1)
		c+=((m[(k - min_val) / 2] * (m[(k - min_val )/ 2] - 1)) / 2),cout<<"bi";
	}
	
	cout<<c<<endl;	
}
signed main()
{
    int arr[] = {0, 4, 6, 2, 4}; 
    int n = sizeof(arr)/ sizeof(arr[0]);
    int k=7;
    
    findPairs(arr,n,k);
    
    return 0;
}
