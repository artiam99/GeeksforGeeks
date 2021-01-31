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
int findRoot(pair<int, int> arr[], int n)
{
    int root = 0;
   
    for (int i=0; i<n; i++)
    root += (arr[i].first - arr[i].second);

    return root;
}
signed main()
{
	pair<int, int> arr[] = {{1, 5}, {2, 0},{3, 0}, {4, 0}, {5, 5}, {6, 5}};
	
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Root  :  %d", findRoot(arr, n));
    
    return 0;
}
