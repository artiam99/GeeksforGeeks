#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
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
bool levelOrderIsOfBST(int lvl[],int n)
{
	if(!n)
	return true;
	
	queue<tuple<int,int,int>> q;
	
	q.push(make_tuple(lvl[0],INT_MIN,INT_MAX));
	
	int i=1;
	
	while(i<n && q.size())
	{
		int parent=get<0>(q.front());
		int left_lim=get<1>(q.front());
		int right_lim=get<2>(q.front());
		
		q.pop();
		
		if(left_lim < lvl[i] && lvl[i] < parent)
		q.push(make_tuple(lvl[i++],left_lim,parent));
		
		if(right_lim > lvl[i] && lvl[i] > parent)
		q.push(make_tuple(lvl[i++],parent,right_lim));
	}
	
	if(i==n)
	return true;
	
	return false;
}
signed main()
{
	int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
	
    if (levelOrderIsOfBST(arr, n))
    cout << "Yes";
    else
    cout << "No";
    
    return 0;
}
