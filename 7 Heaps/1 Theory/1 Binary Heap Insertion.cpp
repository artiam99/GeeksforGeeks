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
		void print()
		{
			for(int i=0;i<size;i++)
			cout<<arr[i]<<" ";
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
	
	return 0;
}
