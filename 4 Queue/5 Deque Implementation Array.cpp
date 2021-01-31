#include<bits/stdc++.h>
using namespace std;
class Deque
{
	int front;

	int rear;

	int *arr;

	int capacity;

	public:

		Deque(int capacity)
		{
			front = -1;

			rear = -1;

			this->capacity = capacity;

			arr = new int[capacity];

			memset(arr , 0 , sizeof(int) * capacity);
		}

		void Push_back(int x)
		{
			cout << "Push_back : ";
		
			if((rear+1) % capacity == front)
			{
				cout << "Deque Full" << endl;
		
				return;
			}
			
			cout << endl;
	
			if(front == -1)
			front++;
	
			rear = (rear+1) % capacity;
	
			arr[rear] = x;
		}
		
		void Push_front(int x)
		{
			cout << "Push_front : ";
	
			if(rear == (front-1+capacity)%capacity)
			{
				cout << "Deque Full" << endl;
	
				return;
			}
	
			cout << x << endl;
	
			if(front == -1)
			{
				front++;
	
				rear++;
			}
	
			else
			front = (front - 1 + capacity) % capacity;
	
			arr[front] = x;
		}
	
		void Pop_back()
		{
			cout << "Pop_back : ";
	
			if(rear == -1)
			{
				cout << "Deque Empty" << endl;
	
				return;
			}
	
			cout << arr[rear] << endl;
	
			arr[rear] = 0;
	
			if(front == rear)
			front = rear = -1;
	
			else
			rear = (rear - 1 + capacity) % capacity;
		}
		void Pop_front()
		{
			cout << "Pop_front : ";
	
			if(front == -1)
			{
				cout << "Deque Empty" << endl;
	
				return;
			}
	
			cout << arr[front] << endl;
	
			arr[front] = 0;
	
			if(front == rear)
			front = rear = -1;
	
			else
			front = (front + 1) % capacity;
		}

		void Size()
		{
			cout << "Size : " << ((front == -1) ? 0 : (rear >= front) ? (rear - front + 1) : (capacity - front + rear + 1)) << endl;
		}

		void Empty()
		{
			cout << "Empty : ";
			
			if(front == -1)
			cout << "Yes" << endl;

			else
			cout << "No" << endl;
		}

		void print()
		{
			cout << "Deque : ";

			for(int i = 0 ; i < capacity ; i++)
			cout << arr[i] << " ";cout << endl;
		}
};

signed main()
{
   	Deque d(4);

   	d.Push_back(1);  d.Size();  d.Empty();  d.print();  cout << endl;
   	d.Pop_front();  d.Size();  d.Empty();  d.print();  cout << endl;
   	d.Push_front(1);  d.Size();  d.Empty();  d.print();  cout << endl;
   	d.Pop_back();  d.Size();  d.Empty();  d.print();  cout << endl;
   	d.Pop_back();  d.Size();  d.Empty();  d.print();  cout << endl;
   	d.Pop_front();  d.Size();  d.Empty();  d.print();  cout << endl;
   	d.Push_back(3);  d.Size();  d.Empty();  d.print();  cout << endl;
   	d.Push_front(2);  d.Size();  d.Empty();  d.print();  cout << endl;
   	d.Push_front(1);  d.Size();  d.Empty();  d.print();  cout << endl;
   	d.Push_back(4);  d.Size();  d.Empty();  d.print();  cout << endl;
   	d.Push_back(5);  d.Size();  d.Empty();  d.print();  cout << endl;
   	d.Push_front(5);  d.Size();  d.Empty();  d.print();  cout << endl;
   	d.Pop_back();  d.Size();  d.Empty();  d.print();  cout << endl;
   	d.Pop_front();  d.Size();  d.Empty();  d.print();  cout << endl;
   	d.Pop_back();  d.Size();  d.Empty();  d.print();  cout << endl;
   	d.Pop_front();  d.Size();  d.Empty();  d.print();  cout << endl;
   	d.Pop_back();  d.Size();  d.Empty();  d.print();  cout << endl;
   	d.Pop_front();  d.Size();  d.Empty();  d.print();  cout << endl;
	
	return 0;
}
