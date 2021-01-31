#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Node
{
	int data;
	vector<Node*> neighbour;
	Node(int x)
	{
		data=x;
	}
};
Node* CloneGraph(Node* src)
{
	unordered_map<Node*,Node*> m;
	
	queue<Node*> q;
	
	if(src)
	q.push(src);
	
	Node* node=new Node(src->data);
	m[src]=node;
	
	
	while(q.size())
	{
		Node* u=q.front(); q.pop();
		
		vector<Node*> v=u->neighbour;
		
		for(auto i:v)
		{
			if(!m[i])
			{
			    node=new Node(i->data);
				m[i]=node;
				q.push(i); 
			}
			m[u]->neighbour.push_back(m[i]);
		}
	}
	return m[src];
}
void BFT(Node* src)
{
	queue<Node*> q;
	set<Node*> vis;
	
	if(src)
	q.push(src);
	vis.insert(src);
	
	while(q.size())
	{
		cout<<q.front()->data<<" ";
		for(auto i:q.front()->neighbour)
		{
			if(vis.find(i)==vis.end())
			{
				vis.insert(i);
				q.push(i);
			}
		}
		q.pop();
	}
	cout<<endl;
}
signed main()
{
	Node* node1=new Node(1);
	Node* node2=new Node(2);
	Node* node3=new Node(3);
	Node* node4=new Node(4);
	
	node1->neighbour.push_back(node2);
	node1->neighbour.push_back(node4);
	
	node2->neighbour.push_back(node1);
	node2->neighbour.push_back(node3);
	
	node3->neighbour.push_back(node2);
	node3->neighbour.push_back(node4);
	
	node4->neighbour.push_back(node3);
	node4->neighbour.push_back(node1);
	
	Node* src=node1;
	
	BFT(src);
	
	Node* newsrc=CloneGraph(src);
	
	BFT(newsrc);
	
	return 0;
}
