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
struct MinHeap
{
	int size;
	Node* *arr;
	MinHeap(int n)
	{
		size = 0;
		arr = new Node*[n];
	}
	void Push(Node* root)
	{	
		arr[size] = root;
		
		int i = size;
		
		while(i != 0)
		{
			int p = (i-1)/2;
			
			if(arr[p]->fr > arr[i]->fr)
			{
				swap(arr[p],arr[i]);
				
				i = p;
			}
			else  break;
		}
		
		size++;
	}
	void Heapify(int i)
	{
		int smallest = i;
		
		if(i*2+1 < size && arr[i*2+1]->fr < arr[smallest]->fr)
		smallest = i*2+1;
		
		if(i*2+2 < size && arr[i*2+2]->fr < arr[smallest]->fr)
		smallest = i*2+2;
		
		if(i != smallest)
		{
			swap(arr[i],arr[smallest]);
			
			Heapify(smallest);
		}
	}
	Node* ExtractMin()
	{
		size--;
		
		swap(arr[0],arr[size]);
		
		Heapify(0);
		
		return arr[size];
	}
};
void DFS(Node* root,vector<bool> &a)
{
	if(root->ch != '*')
	{
		cout<< root->ch << " : ";
		
		for(auto i:a)
		cout<<i;
		cout<<endl;
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
	MinHeap pq(n);
	
	for(int i = 0 ; i < n ; i++)
	{
		Node* root = new Node(cn[i],ch[i]);
		
		pq.Push(root);
	}
	
	while(pq.size > 1)
	{
		Node *a = pq.ExtractMin();
		
		Node *b = pq.ExtractMin();
		
		Node *root = new Node(a->fr+b->fr,'*');
		
		root->left = a;
		root->right = b;
		
		pq.Push(root);
	}
	
	vector<bool> a;
	DFS(pq.ExtractMin(),a);
}
int main()
{
	vector<char> ch = {'a','b','c','d','e','f'};
	vector<int> cn = {5, 9, 12, 13, 16, 45};
	int n = cn.size();
	
	Huffman_Coding(ch,cn,n);
	
	return 0;
}
