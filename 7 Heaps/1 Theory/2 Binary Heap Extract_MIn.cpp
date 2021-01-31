#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
class minheap
{
	int size;
	int capacity;
	int *arr;
	public:
		minheap(int capacity)
		{
			size=0;
			this->capacity=capacity;
			arr=new int[capacity];
		}
		void insert(int key)
		{
			if(size==capacity)
			{
				cout<<"Heap Overflow"<<endl;
				return ;
			}
			size++;
			
			int i=size-1;
			
			arr[i]=key;
			
			while(i && arr[(i-1)/2]>arr[i])
			{
				swap(arr[i],arr[(i-1)/2]);
				
				i=(i-1)/2;
			}
		}
		void heapify(int i)// This Method Assumes Subtrees are already heapified
		{
			while(1)
			{
				int smallest=i;
				int l=i*2+1;
				int r=i*2+2;
				
				if(l<size && arr[l]<arr[smallest])
				smallest=l;
				
				if(r<size && arr[r]<arr[smallest])
				r=smallest;
				
				if(i!=smallest)
				{
					swap(arr[i],arr[smallest]);
					
					i=smallest;
				}
				else 
				break;
			}
		}
		int extract_min()
		{
			if(size==0)
			{
				cout<<"Heap Empty"<<endl;
				return -1;
			}
			
			swap(arr[0],arr[size-1]);
			size--;
			
			heapify(0);
			
			return arr[size];
		}
		void print()
		{
			for(int i=0;i<size;i++)
			cout<<arr[i]<<" ";
			cout<<endl;
		}
};
signed main()
{
	minheap h(4);
	h.insert(5);
	h.insert(1);
	h.insert(4);
	h.insert(2);
	h.insert(3);
	
	h.print();
	
	cout<<h.extract_min()<<endl;
	cout<<h.extract_min()<<endl;
	
	h.print();
	
	return 0;
}
