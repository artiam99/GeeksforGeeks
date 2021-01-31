#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *left , *right;
	
	Node(int d,Node* l,Node* r)
	{
		data = d , left = l , right = r;	
	}	
};
void Update(Node* prev , Node* curr , int l , int r , int ind , int diff)
{
	if(l > ind || r < ind)  return;
	
	if(l == r)
	{
		curr->data = diff;
		
		return;
	}
	
	int m = l + (r - l) / 2;
	
	if(ind <= m)
	{
		curr->right = prev->right;
		
		curr->left = new Node(0,NULL,NULL);
		
		Update(prev->left , curr->left , l , m , ind , diff);
	}
	
	else
	{
		curr->left = prev->left;
		
		curr->right = new Node(0,NULL,NULL);
		
		Update(prev->right , curr->right , m + 1 , r , ind , diff);
	}
	
	curr->data = curr->left->data + curr->right->data;
}
int GetSum(Node* st , int l , int r , int ql , int qr)
{	
	if(l >= ql && r <= qr)  return st->data;
	
	if(l > qr || r < ql)  return 0;
	
	int m = l + (r - l) / 2;
	
	return GetSum(st->left , l , m , ql , qr) + GetSum(st->right , m + 1 , r , ql , qr);
}
Node* Construct(vector<int> &a , int l , int r)
{	
	if(l == r)  return new Node(a[l],NULL,NULL);
	
	Node * curr = new Node(0,NULL,NULL);	
	
	int m = l + (r - l) / 2;
	
	curr->left = Construct(a , l , m);
	
	curr->right = Construct(a , m + 1 , r);
	
	curr->data = curr->left->data + curr->right->data;
	
	return curr;
}
signed main()
{
	vector<int> a = {2, 4, -5, 9, 0, 10};
	int n = a.size();
	
	Node *st = Construct(a,0,n-1);
	
	vector<Node*> version(1,st);
	
	cout << GetSum(version[0] , 0 , n - 1 , 1 , 4) << endl;
	
	version.push_back(new Node(0,NULL,NULL));
	Update(version[0] , version[1] , 0 , n - 1 , 2 , 10);
	
	cout << GetSum(version[1] , 0 , n - 1 , 2 , 4) << endl;
	
	version.push_back(new Node(0,NULL,NULL));
	Update(version[1] , version[2] , 0 , n - 1 , 5 , 12);
	
	cout << GetSum(version[2] , 0 , n - 1 , 2 , 5) << endl;
	
	return 0;
}
