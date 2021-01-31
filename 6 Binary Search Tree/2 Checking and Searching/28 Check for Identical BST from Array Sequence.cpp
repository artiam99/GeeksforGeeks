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
bool checkuntill(int a[],int b[],int n,int i1,int i2,int l,int r)
{
	if( (i1==-1 && i2!=-1) || (i1!=-1 && i2==-1) || (a[i1]!=b[i2]) )
	return false;
	
	if(i1==-1 && i2==-1)
	return true;
	
	int a1=-1,a2=-1;
	for(int i=i1+1;i<n;i++)
	{
		if(a[i]>l && a[i]<r)
		{
			if(a[i]<a[i1] && a1==-1)
			a1=i;
			
			else if(a[i]>a[i1] && a2==-1)
			a2=i;
		}
		if(a1!=-1 && a2!=-1)
		break;
	}
	
	int b1=-1,b2=-1;
	for(int i=i2+1;i<n;i++)
	{
		if(b[i]>l && b[i]<r)
		{
			if(b[i]<b[i2] && b1==-1)
			b1=i;
			
			else if(b[i]>b[i2] && b2==-1)
			b2=i;
		}
		if(b1!=-1 && b2!=-1)
		break;
	}
	
	return (checkuntill(a,b,n,a1,b1,l,a[i1]) && checkuntill(a,b,n,a2,b2,a[i1],r));
}
bool check(int a[],int b[],int n)
{
	return checkuntill(a,b,n,0,0,INT_MIN,INT_MAX);
}
signed main()
{
    /*      8
         /    \
       3       10
     /  \        \
    1     6       14
        /   \     /
       4     7   13   */
    
    int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};   
    int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
    int n=sizeof(a)/sizeof(int);
    
    
    if(check(a,b,n))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    
    return 0;
}
