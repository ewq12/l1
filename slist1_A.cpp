z#include<iostream>
##include<conio.h>
using namespace std;
class node
{	
	int data;
	node *next;
	public:
	
	friend class linklist;	
	
	node(int x)
	{
		data=x;
		next=NULL;
		
	}
	
};

class linklist
{	int i,n,num;
	node *listptr;
	node *temp;
   public:
	linklist()
	{	
		listptr=NULL;
	}	
	void create()
	{	
	cout<<"Enter no. of nodes : ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter data :";
		cin>>num;
		node *newnode=new node(num);
		if (listptr==NULL)
			listptr=temp=newnode;
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
	}
	}
	
	int isEmpty()
	{
		return(listptr==NULL);
		
	}
	
	void display()
	{
		temp=listptr;
		if(isEmpty())
		{
			cout<<"List is empty";
			return;
		}
		cout<<"\n";
		while(temp!=NULL)
		{
			cout<<temp->data<<"  ->  ";
			temp=temp->next;
		}
		cout<<"!!";
	}
	
	void insertBeg()
	{
		int q;
		cout<<"Enter the data at beg: ";
		cin>>q;
		node *newnode = new node(q);
		if(isEmpty())
		{
			listptr=newnode;
		}
		else
		{
			newnode->next=listptr;
			listptr=newnode;
		}
		
	}
	
	void insertEnd()
	{
		temp=listptr;
		int q;
		cout<<"Enter the data at end: ";
		cin>>q;
		node *newnode = new node(q);
		if(isEmpty())
		{
			listptr=newnode;
		}
		else
		{
			while(temp->next!=NULL)
			{
				temp=temp->next;	
			}
			temp->next=newnode;
			newnode->next=NULL;
		}
	}
	
	void insertPos()
	{
		temp=listptr;
		int q,p,count=0;
		cout<<"\nEnter position : ";
		cin>>p;	
		cout<<"\nEnter the data : ";
		cin>>q;
		node *newnode = new node(q);
		newnode->next=NULL;
		if(isEmpty())
		{
			listptr=newnode;
		}
		while(count!=p-2)
		{
			temp=temp->next;
			count++;
		}
		if(temp->next==NULL)
		{
			cout<<"position not found";
		}
		else
		{
			newnode->next=temp->next;
			temp->next=newnode;
		}
	}
	
	void delBeg()
	{
		
		if(isEmpty())
		{
			cout<<"List is empty";
		}
		else if(listptr->next==NULL)
		{
			listptr=NULL;	
		}
			else
			{
				temp=listptr;
				listptr=listptr->next;
				delete temp;
			}
	}
	
	void delEnd()
	{
		temp=listptr;
		node *temp1;
		if(isEmpty())
		{
			cout<<"List is empty";
		}
		while(temp->next!=NULL){
			temp1=temp;
			temp=temp->next;
		}
		delete temp;
		temp1->next=NULL;
	}
	
	void delPos()
	{
		temp=listptr;
		node *temp1=temp->next;
		int q,p,count=0;
		cout<<"\nEnter position : ";
		cin>>p;	
		
		if(isEmpty())
		{
			cout<<"empty list";
		}
		while(count!=p-2&&temp1->next!=NULL)
		{
			temp=temp->next;
			temp1=temp1->next;
			count++;
		}
		if(temp->next==NULL)
		{
			cout<<"position not found";
		}
		else
		{
			temp->next=temp1->next;
			delete temp1;
		}
	}
	void delVal()
	{
		temp=listptr;
		node *temp1=temp->next;
		int q,p,count=0;
		cout<<"\nEnter value to be deleted : ";
		cin>>p;	
		
		if(isEmpty())
		{
			cout<<"empty list";
		}
		while(temp1->data!=p)
		{
			temp=temp->next;
			temp1=temp1->next;
			
		}
		if(temp->next==NULL)
		{
			cout<<"position not found";
		}
		temp->next=temp1->next;
		delete temp1;	
	}
	void search()
	{
		temp=listptr;
		int p,count=1;
		cout<<"\nEnter value to be seached : ";
		cin>>p;	
		
		if(isEmpty())
		{
			cout<<"empty list";
		}
		while(temp->data!=p)
		{
			temp=temp->next;
			count++;
		}
		if(temp->next==NULL&&temp->data!=p)
		{
			cout<<"position not found";
		}
		cout<<"Element found at "<<count<<"th position";
	}
	void rev()
	{
		node *temp, *c, *b;
		temp = listptr;
		c=NULL;

		while ( temp != NULL )
		{
		b=c;
		c=temp;
		temp= temp->next;
		c->next=b;
		}
		listptr = c;
	}
};

int main()
{
	linklist p;
	int a,n=1;
	p.create();
	while(n!=0){
	cout<<"\nEnter\n1.Insert in beg\n2.Insert at end\n3.Insert by position\n4.Delete from beg\n5.Delete from end\n6.Delete by position\n7.Delete by value\n8.Search\n9.Reverse\n10.Display\n-->";
	cin>>a;
	switch(a)
	{
	case 1:
		p.insertBeg();
		break;
	case 2:
		p.insertEnd();
		break;
	case 3:
		p.insertPos();
		break;	
	case 4:
		p.delBeg();
		break;
	case 5:
		p.delEnd();
		break;
	case 6:
		p.delPos();
		break;
	case 7:
		p.delVal();
		break;
	case 8:
		p.search();
		break;
	case 9:
		p.rev();
	case 10:
		p.display();
	}
cout<<"\nenter '0' to exit";
cin>>n;
}
	return 0;
}
