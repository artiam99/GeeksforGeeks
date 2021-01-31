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
void printOddNodes(Node* root)
{
	queue<Node*> q;
    
    if(root) q.push(root);
	
	int i=1;
    
    while(q.size())
    {
        int size=q.size();
        while(size--)
        {
            if(i%2!=0)
			cout<< q.front()->data <<" ";
            
            if(q.front()->left)
			q.push( q.front()->left );
            
            if(q.front()->right)
			q.push( q.front()->right );
           
            q.pop();
        }
        i++;
    }
    cout<<endl;
}
signed main()
{
	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
	printOddNodes(root);
    
    return 0; 
}
