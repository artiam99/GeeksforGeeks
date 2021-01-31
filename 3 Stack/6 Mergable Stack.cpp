#include <bits/stdc++.h>
using namespace std;
class Stack
{
	struct node
	{
		int data;
		
		node* next;
	};
	
	node* head;
	
	node* tail;
	
	public:
		Stack()
		{
			head = NULL;
	
			tail = NULL;
		}
		
		void push(int x)
		{
			node* temp = new node();
		
			temp->data = x;
		
			temp->next = head;
		
			head = temp;
		
			if(!tail)
			tail = head;
		}
		
		void pop()
		{
			node* temp = head;
		
			head = head->next;
			
			delete temp;
			
			if(!head)
			tail = NULL;
		}
		
		void merge(Stack s)
		{
			if(tail)
			tail->next = s.head;
		
			else
			head = s.head;
		}
		
		void print()
		{
			node* temp = head;
		
			while(temp)
			{
				cout << temp->data << " ";
				
				temp = temp->next;
			}
			
			cout << endl;
		}
};
int main()
{
	Stack s1 , s2;
	
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s2.push(4);
	s2.push(5);
	s2.push(6);
	
	s1.print();
	s2.print();
	
	s1.merge(s2);
	
	s1.print();
	
	return 0;
}
