#include <bits/stdc++.h> 
using namespace std;
struct Node
{
    int data , cnt;
    Node* left , *right;
    Node(int d)
    {
        data = d; cnt = 1;  left = right = NULL;
    }
};
Node* Insert(Node* root , int data)
{
    if(!root)
    return new Node(data);
    
    if(root->data > data)
    root->left = Insert(root->left , data);
    
    else if(root->data < data)
    root->right = Insert(root->right , data);
    
    root->cnt++;
    
    return root;
}
void Less_than_x(Node* root , int x , int& cnt)
{
    if(!root)  return;
    
    if(root->data < x)
    {
        cnt += root->cnt - ((root->right) ? root->right->cnt : 0);
        
        Less_than_x(root->right , x , cnt);
    }
    
    else
    Less_than_x(root->left , x , cnt);
}
vector<int> Construct_Lower_Array(vector<int> &arr, int n)
{
    vector<int> a(n);
    
    Node* root = NULL;
    
    for(int i = n-1 ; i >= 0 ; i--)
    {
        int cnt = 0;
        
        Less_than_x(root , arr[i] , cnt);
        
        a[i] = cnt;
        
        root = Insert(root , arr[i]);
    }
    
    return a;
}
signed main() 
{ 
	vector<int> a = {12 , 1 , 2 , 3 , 0 , 11 , 4};
	int n = a.size();
	
	vector<int> Right = Construct_Lower_Array(a , n);

	for(auto i : Right)
	cout << i << " ";
	cout << endl;

	return 0; 
} 

