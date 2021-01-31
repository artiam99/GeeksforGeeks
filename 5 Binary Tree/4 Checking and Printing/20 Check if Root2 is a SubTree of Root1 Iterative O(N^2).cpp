#include<bits/stdc++.h>
#include <cstring> 
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Node
{
	char data;
	Node* left;
	Node* right;
    Node(char x)
	{
		data=x;
		left=right=NULL;
	}
};
bool check(Node* root1,Node* root2)
{
    stack<Node*> s1,s2;
    Node* t1,*t2;
    s1.push(root1);
    s2.push(root2);
    while(s1.size()&&s2.size())
    {
        t1=s1.top();s1.pop();
        t2=s2.top();s2.pop();
        
        if(!t1&&!t2)
            continue;
        if((!t1&&t2)||(t1&&!t2))
            return false;
        if(t1->data!=t2->data)
            return false;
        s1.push(t1->left);
        s1.push(t1->right);
        s2.push(t2->left);
        s2.push(t2->right);
    }
    return !(s1.size()&&s2.size());
}
bool isSubtree(Node* T, Node* S)
{
    queue<Node*> q;
    q.push(T);
    while(q.size())
    {
        if(q.front()->data==S->data&&check(q.front(),S))
         return true;
        if(q.front()->left)
            q.push(q.front()->left);
        if(q.front()->right)
            q.push(q.front()->right);
        q.pop();
    }
    return false;
} 
signed main()
{
	Node* T = new Node('a'); 
    T->left = new Node('b'); 
    T->right = new Node('d'); 
    T->left->left = new Node('c'); 
    T->right->right = new Node('e'); 
  
    Node* S = new Node('a'); 
    S->left = new Node('b'); 
    S->left->left = new Node('c'); 
    S->right = new Node('d'); 
  
    if (isSubtree(T,S)) 
        cout << "Yes: S is a subtree of T"; 
    else
        cout << "No: S is NOT a subtree of T"; 
  
    return 0; 
    
    return 0; 
}
