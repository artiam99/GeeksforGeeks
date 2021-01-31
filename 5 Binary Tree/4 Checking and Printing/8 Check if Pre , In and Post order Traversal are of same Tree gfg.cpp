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
Node* ConstructTree(vector<int> &pre,vector<int> &in)
{
	int n=pre.size();
	Node* root=NULL;
	stack<Node*> st;
	set<Node*> s;
	
	for(int p=0,i=0;p<n;)
	{
		Node* temp=NULL;
		do
		{
			temp=new Node(pre[p]);
			if(st.size())
			{
				if(s.find(st.top())!=s.end())
				{
					s.erase(st.top());
					st.top()->right=temp;
					st.pop();
				}
				else
				st.top()->left=temp;
			}
			st.push(temp);
		}while(pre[p++]!=in[i]&&p<n);
		temp=NULL;
		while(st.size()&&i<n&&st.top()->data==in[i])
		{
			temp=st.top();
			st.pop();
			i++;
		}
		if(temp)
		{
			st.push(temp);
			s.insert(temp);
		}
	}
	return root;
}
void checkpostorder(Node* root,vector<int> &post,bool &res)
{
	static int ind=0;
	
	if(!root)
	return;
	
	checkpostorder(root->left,post,res);
	checkpostorder(root->right,post,res);
	
	if(post[ind++]!=res)
	res=0;
}
bool check(vector<int> &pre,vector<int> &in,vector<int> &post)
{
	Node* root=ConstructTree(pre,in);
	
	int ind=0;
	bool res=1;
	
	checkpostorder(root,post,res);
	
	return res;
}
signed main()
{
	vector<int> pre = {1,2,4,5,3};
    vector<int> in = {4,2,5,1,3};
    vector<int> post = {4,5,2,3,1};
    
    if(check(pre,in,post))
    cout<<"Yes";
    else
    cout<<"No";
    cout<<endl<<endl;
	return 0;
}
