#include<bits/stdc++.h>
using namespace std;

template<typename t>
class Stack
{
	struct node
	{
		t data;

		node* next;
	};

	node* head;

	public:

		Stack()
		{
			head = NULL;
		}
		
		void push(t x);
		
		void pop();
		
		t top();
		
		bool empty();
		
		void reverse();
};

template<typename t>
void Stack<t>::push(t x)
{
	node* temp = new node();

	temp->data = x;
	
	temp->next = head;
	
	head = temp;
}

template<typename t>
void Stack<t>::pop()
{
	if(head == NULL)
	return;

	node* temp = head;
	
	head = temp->next;
	
	delete temp;
}

template<typename t>
t Stack<t>::top()
{
	return (head ? head->data : (t)(-1));
}

template<typename t>
bool Stack<t>::empty()
{
	return !(head);
}

template<typename t>
void Stack<t>::reverse()
{
	node* prev = NULL , *cur = head , *next;
	
	while(cur)
	{
		next = cur->next;
	
		cur->next = prev;
	
		prev = cur;
	
		cur = next;
	}
	
	head = prev;
}

int main()
{
	Stack<int> stk;
	
	stk.push(5);
	stk.push(4);
	stk.push(3);
	stk.push(2);
	stk.push(1);
	
	stk.reverse();
	
	while(!stk.empty())
	{
		cout << stk.top() << " ";
	
		stk.pop();
	}
	
	return 0;
}

