#include<bits/stdc++.h>
using namespace std;

class Queue
{
	int front;
	
	int rear;
	
	int *arr;
	
	int size;
	
	int capacity;
	
	public:
		Queue(int capacity)
		{
			front = -1;
	
			rear = -1;
	 
			this->capacity = capacity;
	
			arr = new int[capacity];
	
			size = 0;
		}
		
		void Enque(int x)
		{
			cout << "Enque : ";
		
			if(size == capacity || rear == capacity-1)
			{
				cout << "Queue Full" << endl;
				
				return;
			}
			
			cout << x << endl;
			
			if(front == -1)
			front++;
			
			rear++;
			
			arr[rear] = x;
			
			size++;
		}
		
		void Deque()
		{
			cout << "Deque : ";
		
			if(front == -1)
			{
				cout << "Queue Empty" << endl;
		
				return;
			}
		
			int c = arr[front];
		
			cout << c << endl;
		
			if(front == rear)
			{
				front = -1;
		
				rear = -1;
			}
		
			else
			front++;
		
			size--;
		}
		
		void Size()
		{
			cout << "Size : " << size << endl;
		}
		
		void Empty()
		{
			cout << "Empty : ";
		
			if(size)
			cout << "No" << endl;
		
			else
			cout << "Yes" << endl;
		}
};

signed main()
{
	Queue q(3);

	q.Deque();  q.Size();  q.Empty();  cout << endl;
	q.Enque(4);  q.Size();  q.Empty();  cout << endl;
	q.Enque(5);  q.Size();  q.Empty();  cout << endl;
	q.Enque(3);  q.Size();  q.Empty();  cout << endl;
	q.Enque(2);  q.Size();  q.Empty();  cout << endl;
	q.Deque();  q.Size();  q.Empty();  cout << endl;
	q.Deque();  q.Size();  q.Empty();  cout << endl;
	q.Deque();  q.Size();  q.Empty();  cout << endl;
	q.Deque();  q.Size();  q.Empty();  cout << endl;

	return 0;
}
