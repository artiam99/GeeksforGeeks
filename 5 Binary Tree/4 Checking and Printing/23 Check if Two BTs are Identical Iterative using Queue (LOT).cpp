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
bool areIdentical(Node *root1,Node* root2)
{
	queue<Node*> q1,q2;
	
	if(root1)
	q1.push(root1);
	
	if(root2)
	q2.push(root2);
	
	while(q1.size()&&q2.size())
	{
		if(q1.front()->data!=q2.front()->data)
		return false;
		
		if(q1.front()->left&&q2.front()->left)
		{
			q1.push(q1.front()->left);
			q2.push(q2.front()->left);
		}
		else if(q1.front()->left||q2.front()->left)
		return false;
		
		if(q1.front()->right&&q2.front()->right)
		{
			q1.push(q1.front()->right);
			q2.push(q2.front()->right);
		}
		else if(q1.front()->right||q2.front()->right)
		return false;
		
		q1.pop();
		q2.pop();
	}
	
	return !(q1.size()&&q2.size());
}
signed main()
{
	Node *root1 = new Node(1); 
    root1->left = new Node(2); 
    root1->right = new Node(3); 
    root1->left->left = new Node(4); 
    root1->left->right = new Node(5); 
  
    Node *root2 = new Node(1); 
    root2->left = new Node(2); 
    root2->right = new Node(3); 
    root2->left->left = new Node(4); 
    root2->left->right = new Node(5); 
  
    areIdentical(root1, root2)? cout << "Yes"
                              : cout << "No"; 
    return 0;
}
