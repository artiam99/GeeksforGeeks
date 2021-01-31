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
int getMaxSum(Node* root)
{
	if(!root)
	return 0;
	
	queue<Node*> q;
    
	q.push(root);
	
	int incl_curr = intmin , excl_curr , excl_prev , size , sum;
    
    while(q.size())
    {
        size=q.size();
        sum=0;
        while(size--)
        {
            sum+=q.front()->data;
            
            if(q.front()->left)
			q.push( q.front()->left );
            
            if(q.front()->right)
			q.push( q.front()->right );
           
            q.pop();
        }
        if(incl_curr==intmin)
        {
        	incl_curr=sum;
            excl_curr=0;
		}
		else
		{
		    excl_prev=max(incl_curr,excl_curr);
    	    
			incl_curr= sum + excl_curr;
        
			excl_curr=excl_prev;
		}
    }
	
	return max(incl_curr,excl_curr);
}
signed main()
{
	Node* root = new Node(11);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(9);
    root->left->right = new Node(1);
    root->left->left->left = new Node(10);
    root->left->left->right = new Node(20);
    
    cout<<getMaxSum(root)<<endl;
    
    return 0; 
}
