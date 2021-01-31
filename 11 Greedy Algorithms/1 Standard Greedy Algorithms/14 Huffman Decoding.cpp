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
		
		if(i*2+1 < size && arr[i*2+1]->fr <= arr[smallest]->fr)
		smallest = i*2+1;
		
		if(i*2+2 < size && arr[i*2+2]->fr <= arr[smallest]->fr)
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
void DFS(Node* root,vector<bool> &a,unordered_map<char,vector<bool>> &m2)
{
	if(root->ch != '*')
	{
		m2[root->ch] = a;
		
		cout<< root->ch << " : ";
		
		for(auto i:a)
		cout<<i;
		cout<<endl;
		return;
	}
	
	a.push_back(0);
	DFS(root->left,a,m2);
	a.pop_back();
	
	a.push_back(1);
	DFS(root->right,a,m2);
	a.pop_back();
}
Node* Huffman_Coding(string &s,int n,vector<bool> &bs)
{
	cout<< s << endl << endl;
	
	unordered_map<char,int> m1;
	
	for(int i = 0 ; i < n ; i++)
	m1[s[i]]++;
	
	MinHeap pq(n);
	
	for(auto i:m1)
	{
		Node* root = new Node(i.second , i.first);
		
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
	
	Node* root = pq.ExtractMin();
	
	unordered_map<char,vector<bool>> m2;
	
	vector<bool> a;
	DFS(root,a,m2);
	
	cout<< endl;
	
	for(int i = 0 ; i < n ; i++)
	for(auto j:m2[s[i]])
	bs.push_back(j);
	
	return root;
}
string Huffman_Decoding(Node* root,vector<bool> &bs)
{
    string s;  int i = 0;
    
    while(i<bs.size())
    {
        Node* curr = root;
        
        while(curr->ch == '*')
        {
            if(bs[i] == 0)  curr = curr->left;
            
            else curr = curr->right;
            
            i++;
        }
        s += curr->ch;
    }
    
    return s;
}
int main()
{
	string s = "geeksforgeeks";
	int n = s.length();
	
	vector<bool> bs;
	
	Node* root = Huffman_Coding(s,n,bs);
	
	for(auto i:bs)
	cout<< i <<" ";
	cout<< endl << endl;
	
	cout<< Huffman_Decoding(root,bs);
	
	return 0;
}
