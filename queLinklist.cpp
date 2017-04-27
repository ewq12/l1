#include<iostream>
using namespace std;

class node {
	
	int data;
	node *next;
	public:
		node(int n) {
			
			data=n;
			next=NULL;
		}
		friend class quelist; 
};

class quelist {
	
	node *listptr;
	public:
		quelist() {
			listptr=NULL;
		}
		void enqueue();
		void dequeue();
		void display();
}q;

void quelist::enqueue() {
	
	int dt;
	cout<<"Enter Number :";
	cin>>dt;
	node *newnode = new node(dt);
	newnode->next=listptr;
	listptr=newnode;
}

void quelist::dequeue() {
	
	node *temp=listptr;
	node *temp1;
	while(temp->next!=NULL) {
		temp1=temp;
		temp=temp->next;
	}
	temp1->next=NULL;
	delete temp;
}

void quelist::display() {
	
	node *temp=listptr;
	while(temp!=NULL) {
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
}

main() {
	int opt;
	while(1) {
		cout<<endl;
		cout<<"1. Enqueue"<<endl;
		cout<<"2. Dequeue"<<endl;
		cout<<"3. Display"<<endl;
		cin>>opt;
		switch(opt) {
			
			case 1: q.enqueue();
					break;
					
			case 2: q.dequeue();
					break;
			
			case 3: q.display();
					break;				
		}
	}
}

