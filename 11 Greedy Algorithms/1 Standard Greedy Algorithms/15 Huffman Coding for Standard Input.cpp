#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int fr;
	char ch;
	Node *left , *right;
	Node(int f,char c)
	{
		fr = f;
		ch = c;
		left = right = NULL;
	}
};
void DFS(Node* root,vector<bool> &a)
{
	if(root->ch != '*')
	{
		cout<< root->ch << " : ";
		
		for(auto i:a)
		cout<<i;
		cout<< endl;

		return;
	}
	
	a.push_back(0);
	DFS(root->left,a);
	a.pop_back();
	
	a.push_back(1);
	DFS(root->right,a);
	a.pop_back();
}
void Huffman_Coding(vector<char> &ch,vector<int> &cn,int n)
{    
    queue<Node*> q1,q2;
    
    for(int i = 0 ; i < n ; i++)
    {
        Node* root = new Node(cn[i],ch[i]);
        
        q1.push(root);
    }
    
    while(q1.size() || q2.size() > 1)
    {
        Node *left,*right;
        
        for(int i = 0 ; i < 2 ; i++)
        {
            if(q1.size() && q2.size())
            {
                if(q1.front()->fr <= q2.front()->fr)
                {
                    if(i==0)  left = q1.front() ,  q1.pop();
                    
                    else  right = q1.front() , q1.pop();
                    
                }
                else
                {
                    if(i==0)  left = q2.front() , q2.pop();
                    
                    else  right = q2.front() , q2.pop();
                }
            }
            
            else if(q1.size())
            {
                if(i==0)  left = q1.front() ,  q1.pop();
                    
                else  right = q1.front() , q1.pop();
            }
            else if(q2.size())
            {
                if(i==0)  left = q2.front() , q2.pop();
                    
                else  right = q2.front() , q2.pop();
            }
        }
        Node* root = new Node(left->fr+right->fr,'*');
        root->left = left;
        root->right = right;
        
        q2.push(root);
    }
    vector<bool> b;
    DFS(q2.front(),b);
}
int main()
{
	vector<char> ch = {'a','b','c','d','e','f'};
	vector<int> cn = {5, 9, 12, 13, 16, 45};
	int n = cn.size();
	
	Huffman_Coding(ch,cn,n);
	
	return 0;
}
