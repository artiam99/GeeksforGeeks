#include<bits/stdc++.h>
using namespace std;

template<class t>

class priority_que
{
	struct node
    {
        t data;

        int priority;

        node* prev;

    	node* next;	
    };

    node* head;

    node* tail;

    public:

    	priority_que()
    	{
    		head = NULL;

    		tail = NULL;
		}
		
    	node* getnode(t x , int p)
        {
        	node* temp = new node();
         	
			temp->data = x;
        	
			temp->priority = p;
        	
			temp->next = NULL;
        	
			temp->prev = NULL;
        	
			return temp;
        }
        
        void push(t x , int p)
        {
        	node* temp = getnode(x , p);
        	
        	if(head == NULL)
        	{
        		head = temp;
         		
				tail = temp;
	        	
				return;
        	}
        	
        	node* temp1 = head;
        	
			node* prev = NULL;
        	
			while(temp1 != NULL && temp1->data < p)
        	{
        		prev = temp1;
	        	
				temp1 = temp1->next;
        	}
        	
        	if(prev != NULL)
        	prev->next = temp;
        	
			else
        	head = temp;
        	
        	temp->prev = prev;
        	
			if(temp1 != NULL)
        	temp1->prev = temp;
        	
			else
        	tail = temp;
        	
           	temp->next = temp1;
        }
        
        void pop()
        {
        	if(head == NULL)
        	return;
        
			if(head->next == NULL)
	        {
	        	delete head;
	        	
	        	head = NULL;

	        	tail = NULL;

	        	return;
        	}
        	
        	node* temp = head;
        
			head = temp->next;
        
			head->prev = NULL;
        
			delete temp;
        }
        
		t top()
        {
	        return head->data;
        }  
        
		bool empty()
        {
        	return (head == NULL);
        }
};

int main() 
{
	priority_que<int> pq;

	pq.push(3 , 4);
	pq.push(6 , 7);
	pq.push(2 , 3);
	pq.push(12 , 13);
	pq.push(56 , 57);
	pq.push(8 , 9);

	while(!pq.empty())
	{
		cout << pq.top() << endl;
		
		pq.pop();
	}
	
	return 0;
}

