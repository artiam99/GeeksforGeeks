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

			memset(arr , 0 , sizeof(int) * capacity);

			size = 0;
		}
		
		void Enque(int x)
		{
			cout << "Enque : ";
		
			if(size == capacity)
			{
				cout << "Queue Full" << endl;
		
				return;
			}
		
			cout << x << endl;
		
			size++;
		
			if(front == -1)
			front++;
		
			rear = (rear+1)%capacity;
		
			arr[rear] = x;
		}
		
		void Deque()
		{
			cout << "Deque : ";
		
			if(size == 0)
			{
				cout << "Empty Queue" << endl;
		
				return;
			}
		
			cout << arr[front] << endl;
		
			arr[front] = 0;
		
			size--;
		
			if(front == rear)
			{
				front = -1;
		
				rear = -1;
			}
		
			else
			front = (front+1)%capacity;
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
		
		void print()
		{
			cout << "Queue : ";
		
			for(int i = 0 ; i < capacity ; i++)
			cout << arr[i] << " ";
			cout << endl;
		}
};

signed main()
{
	Queue q(3);
	
	q.Enque(4);  q.Size();  q.Empty();  q.print();  cout << endl;
	q.Enque(5);  q.Size();  q.Empty();  q.print();  cout << endl;
	q.Enque(3);  q.Size();  q.Empty();  q.print();  cout << endl;
	q.Enque(2);  q.Size();  q.Empty();  q.print();  cout << endl;
	q.Deque();  q.Size();  q.Empty();  q.print();  cout << endl;
	q.Deque();  q.Size();  q.Empty();  q.print();  cout << endl;
	q.Enque(1);  q.Size();  q.Empty();  q.print();  cout << endl;
	q.Enque(2);  q.Size();  q.Empty();  q.print();  cout << endl;
	q.Deque();  q.Size();  q.Empty();  q.print();  cout << endl;
	q.Deque();  q.Size();  q.Empty();  q.print();  cout << endl;
	q.Deque();  q.Size();  q.Empty();  q.print();  cout << endl;
	q.Enque(2);  q.Size();  q.Empty();  q.print();  cout << endl;
	q.Deque();  q.Size();  q.Empty();  q.print();  cout << endl;
	
	return 0;
}
