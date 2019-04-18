#include<iostream>
using namespace std;
#include <stdlib.h> 
#include <stdio.h>
#include<memory> 

typedef struct node
{

	int data=0;
	node *next;
}node;

class list
{
	private:
	node *head,*tail;
	public:
	list()
	{
		head =NULL;
		tail =NULL;
	}
	void createNode( int val)
	{
		node *temp =new node;
		temp->data =val;
		temp->next =NULL;
		if(head ==NULL)
		{
			head =temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail =temp;
		}
	}
	void dispNode(void);
//	void insertFirst(int val );
	void insert_pos(int pos,int val);
	void insertFirst(int val );
	void deleteFirst(void);
	void delete_last();
	void reverse(void);

/*	{
		node *temp =new node;
		temp =head;	
		while(temp!=NULL)
		{
		  cout <<temp->data<<'\n';
		  temp =temp->next;		
		}
	}	*/


};

void list::dispNode()  
 {
	 node *temp =new node;
         temp =head;
         while(temp!=NULL)
             {
                  cout <<temp->data<<'\n';
                  temp =temp->next;
             }
}
void list::insertFirst(int val )
{
	node *temp =new node;
	temp->data =val;
	temp->next=head;
	head=temp;


}
void list:: insert_pos(int pos,int val)
{
	node *pre=new node;
//	shared_ptr<node> pre(new node);
	node *curr =new node;
	node *temp =new node;
  	curr =head;
	for(int i=1;i<pos;i++)
	{
	  pre=curr;	
	  curr=curr->next;
	}
	temp->data=val;
	pre->next=temp;
	temp->next =curr;
}
void list:: deleteFirst()
{
	node *temp =new node;
	temp=head;
	head=head->next;
	delete temp;	
}
void list::delete_last()
{
	node *curr =new node;
	node *prev =new node;
	curr=head;
	while(curr->next!=NULL)
	{
	  prev =curr;
	  curr=curr->next;
	}
	tail=prev;
	prev->next=NULL;
	delete curr;


}
void list::reverse(void)
{
	node *curr= new node;
	node *prev = new node;
	node *nxt = new node;
	prev=NULL;
	nxt =NULL;
	curr =head;
	while(curr!=NULL)
	{
		nxt=curr->next;
		curr->next = prev;
		prev =curr;
		curr =nxt;
	}
	head  =prev;
//	delete curr;
//	delete prev;
//	delete nxt;
}










/*void delete_middle(int pos)
{
	node *curr =new node;
	node *prev =new node;
	curr=head;
	for(int i=1;i<pos;i++)
	{
		prev=curr;
		curr=curr->next;
	}
	prev->next=curr->next;

}*/


int main() 
{

	list l;
	l.createNode(1);
	l.createNode(2);
	l.createNode(3);
	l.insertFirst(4);
	l.insert_pos(2,6);
	l.deleteFirst();
	l.delete_last();
	l.reverse();
	l.dispNode();
	
	return 1; 
} 
