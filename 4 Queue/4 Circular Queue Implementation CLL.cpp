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
			front = NULL;

			rear = NULL;

			size = 0;
		}

		void Enque(int x)
		{
			cout << "Enque : " << x << endl;

			node* temp = new node;

			temp->data = x;

			size++;

			if(!front)
			{
				front = temp;

				rear = temp;

				temp->next = temp;

				return;
			}

			temp->next = front;

			rear->next = temp;

			rear = temp;
		}

		void Deque()
		{
			cout << "Deque : ";

			if(!front)
			{
				cout << "Queue Empty" << endl;

				return;
			}

			cout << front->data << endl;
		
			size--;
		
			node* temp = front;
		
			if(front == rear)
			{
				front = NULL;
		
				rear = NULL;
			}
		
			else
			{
				front = front->next;
		
				rear->next = front;
			}
		
			delete temp;
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
		
			if(!front)
			{
				cout << endl;
		
				return;
			}
		
			node* temp = front;
		
			do
			{
				cout << temp->data << " ";
		
				temp = temp->next;
		
			}while(temp != front);
		
			cout << endl;
		}
};

signed main()
{
	Queue q;
	
	q.Deque();  q.Size();  q.Empty();  q.print();  cout << endl;
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
	q.Deque();  q.Size();  q.Empty();  q.print();  cout << endl;
	q.Deque();  q.Size();  q.Empty();  q.print();  cout << endl;

	return 0;
}

