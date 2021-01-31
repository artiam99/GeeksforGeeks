#include<bits/stdc++.h>
using namespace std;
class Queue
{
	struct node
	{
		int data;
	
		node* next;
	};
	
	node* front;
	
	node* rear;
	
	int size;
	
	public:
	
		Queue()
		{
			size = 0;
	
			front = NULL;
	
			rear = NULL;
		}
	
		void Enque(int x)
		{
	
			cout << "Enque : " << x << endl;
	
			node* temp = new node;
	
			temp->data = x;
	
			temp->next = NULL;
	
			size++;
	
			if(front == NULL)
			{
				front = temp;
	
				rear = temp;
	
				return;
			}
	
			rear->next = temp;
	
			rear = temp;
		}
		
		void Deque()
		{
			cout << "Deque : ";
			
			if(front == NULL)
			{
				cout << "Queue Empty" << endl;
			
				return;
			}
		
			cout << front->data << endl;
		
			node* temp = front;
		
			if(front == rear)
			{
				front = NULL;
				rear = NULL;
			}
		
			else
			front = front->next;
		
			delete temp;
		
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
	Queue q;

	q.Deque();  q.Size();  q.Empty();  cout << endl;
	q.Enque(4);  q.Size();  q.Empty();  cout << endl;
	q.Enque(5);  q.Size();  q.Empty();  cout << endl;
	q.Enque(3);  q.Size();  q.Empty();  cout << endl;
	q.Enque(2);  q.Size();  q.Empty();  cout << endl;
	q.Deque();  q.Size();  q.Empty();  cout << endl;
	q.Deque();  q.Size();  q.Empty();  cout << endl;
	q.Deque();  q.Size();  q.Empty();  cout << endl;
	q.Deque();  q.Size();  q.Empty();  cout << endl;
	q.Deque(); q.Size();  q.Empty();  cout << endl;
	
	return 0;
}
