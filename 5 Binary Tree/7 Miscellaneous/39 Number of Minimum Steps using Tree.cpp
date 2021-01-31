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
int step(int n)
{
	int h=0;
	
	queue<int> q;
	
	q.push(0);
	
	while(1)
	{
		h++;
		int size=q.size();
		while(size--)
		{
			
			if(q.front()==n)
			return h-1;
			
			q.push(q.front()+h);
			q.push(q.front()-h);
			q.pop();
		}
	}
}
signed main()
{
    cout<<step(13);
	   
    return 0;
}
