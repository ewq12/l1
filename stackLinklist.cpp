#include<iostream>
using namespace std;

class node {
	
	int data;
	node *next;
	
	public:
		node(int n) {
			
			data=n;
			next = NULL;
		}
		friend class stacklist;
};

class stacklist {
	
	node *listptr;
	public:
		stacklist() {
			listptr = NULL;
		}
		void push();
		void pop();
		void display();
}st;

void stacklist::push() {
	
	node *temp;
	int dt;
	cout<<"Enter the value : ";
	cin>>dt;
	node *newnode = new node(dt);
	if(listptr == NULL) {
		listptr = temp = newnode; 
	}
	else {
		newnode->next=listptr;
		listptr = newnode;
	}
	
}

void stacklist::pop() {
	
	node *temp;
	temp=listptr;
	listptr=temp->next;
	delete(temp);
}

void stacklist::display() {
	
	node *temp=listptr;
	while(temp!=NULL) {
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}	
	cout<<"NULL";
	
}

main() {
	
	int opt;
	while(1) {
		cout<<endl;
		cout<<"1. PUSH"<<endl;
		cout<<"2. POP"<<endl;
		cout<<"3. Display"<<endl;
		cin>>opt;
		switch(opt) {
			
			case 1: st.push();
					break;
					
			case 2: st.pop();
					break;
			
			case 3: st.display();
					break;				
		}
	}
	
}
