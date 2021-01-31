#include <bits/stdc++.h>
using namespace std;

class Stack
{
	struct node
	{
		int data;

		node* next;

		node* prev;
	};

	node* top;

	node* mid;

	int count;

	public:

		Stack()
		{
			top = NULL;

			mid = NULL;

			count = 0;
		}
		
		void push(int x)
		{
			cout << "Pushed element : " << x << endl;
		
			node* temp = new node();
			
			temp->data = x;
			
			temp->prev = NULL;
			
			temp->next = top;
			
			if(top)
			top->prev = temp;
			
			top = temp;
			
			if(count == 0)
			mid = top;
			
			else if(count % 2 == 0)
			mid = mid->prev;
			
			count++;
		}
		
		void pop()
		{
			cout << "Poped Element : ";
		
			if(!top)
			{
				cout << "Empty Stack" << endl;
				
				return;
			}
			
			cout << top->data << endl;
			
			node* temp = top;
			
			top = top->next;
			
			if(top)
			top->prev = NULL;
			
			delete temp;
			
			if(count % 2 != 0)
			mid = mid->next;
			
			count--;
		}
		
		void Top()
		{
			cout<<"Top : ";
		
			if(!top)
			{
				cout << "Empty Stack" << endl;
				
				return;
			}
		
			cout << top->data << endl;
		}
		
		void Mid()
		{
			cout << "Mid : ";
		
			if(!mid)
			{
				cout << "Empty Stack" << endl;
				
				return;
			}
			
			cout << mid->data << endl;
		}
		
		void deletemid()
		{
			cout << "Mid deleted : ";
		
			if(mid == NULL)
			{
				cout << "Empty Stack" << endl;
				
				return;
			}
			
			cout << mid->data << endl;
			
			node* prev = mid->prev;
			
			node* next = mid->next;
			
			if(mid->prev)
			mid->prev->next = mid->next;
			
			if(mid->next)
			mid->next->prev = mid->prev;
			
			if(count % 2 == 0)
			mid = prev;
			
			else
			mid = next;
			
			if(count == 1 || count == 2)
			top = mid;
			
			count--;
	    }
	    
	    void print()
	    {
	    	cout << endl;
	    	cout << "Stack : " << endl;
	    	
			node* temp = top;
	    	
			node* last;
	    	
			while(temp)
	    	{
	    		cout << temp->data << " ";
	    	
				last = temp;
	    		
				temp = temp->next;
			}
			
			cout << endl;
			
			while(last)
			{
				cout << last->data << " ";
				
				last = last->prev;
			}
			
			cout << endl << endl;
		}
};

int main()
{
	Stack s;
	
	s.push(9);  s.Mid();  s.Top();  s.print();  s.deletemid();  cout<<endl;
	
	s.push(10);  s.push(12);  s.Mid();  s.Top();  s.print();  s.deletemid();  s.pop();  cout<<endl;
	
	s.push(8);  s.push(7);  s.push(6);  s.push(5);  s.push(4);  s.push(3);  s.push(2);  s.push(1);  s.Mid();  
	
	s.Top();  s.print();  s.deletemid();  s.print();  s.Mid();  s.pop();  s.print();  s.Mid();
	
	return 0;
}

