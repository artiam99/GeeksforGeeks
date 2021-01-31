#include<bits/stdc++.h>
using namespace std;
struct TrieNode
{
	TrieNode* children[26];
	
	int freq;
	
	int index;
	
	TrieNode()
	{
		for(int i = 0 ; i < 26 ; i++)
		children[i] = NULL;
		
		freq = 0;
		
		index = -1;
	}
};
TrieNode* InsertTrie(TrieNode* root , string &s)
{
	for(int i = 0 ; i < s.length() ; i++)
	{
		int index = s[i] - 'a';
		
		if(!root->children[index])  root->children[index] = new TrieNode();
		
		root = root->children[index];
	}
	root->freq++;
	
	return root;
}
struct HeapNode
{
	TrieNode* Trie;
	
	string key;
	
	int freq;
};
struct MinHeap
{
	int size;
	
	HeapNode *arr;
	
	MinHeap(int N)
	{
		arr = new HeapNode[N];
		
		size = 0;
	}
	HeapNode Top()
	{
		return arr[0];
	}
	void InsertHeap(TrieNode* curr , string &key)
	{
		arr[size].freq = curr->freq;
		
		arr[size].key = key;
		
		arr[size].Trie = curr;
		
		curr->index = size;
		
		int i = size;
		
		while(i && arr[i].freq < arr[(i-1) / 2].freq)
		{
			
			swap(arr[i].Trie->index , arr[(i-1) / 2].Trie->index);
				
			swap(arr[(i-1) / 2] , arr[i]);
			
			i = (i-1) / 2;
		}
		
		size++;
	}
	void Heapify(int i)
	{
		int smallest = i , left = i * 2 + 1 , right = i * 2 + 2;
		
		if(left < size && arr[left].freq < arr[smallest].freq)  smallest = left;
		
		if(right < size && arr[right].freq < arr[smallest].freq)  smallest = right;
		
		if(smallest != i)
		{
			swap(arr[smallest].Trie->index , arr[i].Trie->index);
				
			swap(arr[smallest] , arr[i]);
			
			Heapify(smallest);
		}
	}
	void Extract_Min()
	{
		size--;
		
		arr[0].Trie->index = -1;
		
		arr[size].Trie->index = 0;
		
		swap(arr[0] , arr[size]);
		
	    Heapify(0);
	}
	void Increase_Key(int ind)
	{	
		arr[ind].freq++;
		
		Heapify(ind);
	}
};		
void Kth_Frequent(string &file , int n , int K)
{	
	TrieNode* root = new TrieNode();
	
	MinHeap pq(1000);
	
	string s;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(file[i] == ' ')
		{
			TrieNode* curr = InsertTrie(root , s);
			
			if(curr->index != -1)  pq.Increase_Key(curr->index);  // if Key is in the Heap
			
			else
			{
				if(pq.size < K)  pq.InsertHeap(curr , s);
				
				else if(pq.Top().freq < curr->freq)
				{	
					pq.Extract_Min();
					
					pq.InsertHeap(curr , s);
				}
			}
			
			s.clear();
			
			continue;
		}
		
		s += file[i];
	}
	
	while(pq.size)
	{
		cout << pq.Top().key << " : " << pq.Top().freq << endl;
		
		pq.Extract_Min();
	}
}
signed main()
{	
	string file = "welcome to the world of geeks this portal has been created to provide well written well thought and well explained solutions for selected questions if you like geeks for geeks and would like to contribute here is your chance you can write article and mail your article to contribute at geeksforgeeks org see your article appearing on the geeks for geeks main page and help thousands of other geeks ";
	int n = file.length();
	
	int k = 5;
	
	Kth_Frequent(file , n , k);
	
	return 0;
}
