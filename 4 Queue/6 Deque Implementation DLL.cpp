#include<bits/stdc++.h>
using namespace std;
class Deque
{
	struct node
	{
		int data;

		node* next;

		node* prev;

		node(int x)
		{
			data = x;

			prev = next = NULL;
		}
	};

	node* front;

	node* rear;

	int size;

	public:

		Deque()
		{
			front = NULL;

			rear = NULL;

			size = 0;
		}

		void Push_back(int x)
		{
			cout << "Push_back : " << x << endl;

			node* temp = new node(x);

			size++;

			if(!front)
			{
				front = temp;

				rear = temp;

				return;
			}
			rear->next = temp;

			temp->prev = rear;

			rear = temp;
		}

		void Push_front(int x)
		{
			cout << "Push_front : " << x << endl;

			node* temp = new node(x);

			size++;

			if(!front)
			{
				front = temp;

				rear = temp;

				return;
			}

			front->prev = temp;

			temp->next = front;

			front = temp;
		}

		void Pop_back()
		{
			cout << "Pop_back : ";

			if(!front)
			{
				cout << "Deque Empty" << endl;

				return;
			}

			cout << rear->data << endl;

			size--;

			node* temp = rear;

			if(front == rear)
			front = rear = NULL;

			else
			{
				rear = rear->prev;

				rear->next = NULL;
			}

			delete temp;
		}

		void Pop_front()
		{
			cout << "Pop_front : ";

			if(!front)
			{
				cout << "Deque Empty" << endl;

				return;
			}

			cout << front->data << endl;

			size--;

			node* temp = front;

			if(front == rear)
			front = rear = NULL;

			else
			{
				front = front->next;

				front->prev = NULL;
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

			if(!front)
			cout << "Yes" << endl;

			else
			cout << "No" << endl;
		}

		void print()
		{
			cout << "Deque : " << endl;

			if(!front)
			{
				cout << endl;

				return;
			}

			node* temp1 = front;

			node* temp2;

			while(temp1)
			{
				temp2 = temp1;

				cout << temp1->data << " ";

				temp1 = temp1->next;
			}

			cout << endl;

			while(temp2)
			{
				cout << temp2->data << " ";

				temp2 = temp2->prev;
			}

			cout << endl;
		}
};
signed main()
{
   	Deque d;

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

