/*
coder = YASH JAIN
date = 29-april-2020
topic = "doubly linked list implementation"
*/


#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node*prev;
	struct node*next;
};
struct node* head;//global variable
//-------------------------------------------//
struct node* getnewnode(int x)
{
	struct node* newnode =(struct node*)malloc(sizeof(struct node));
	newnode->data = x;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}
//--------------------------------------------//
void insertathead(int x)
{
	struct node*newnode = getnewnode(x);
	if(head == NULL){
		head = newnode;
		return;
	}
	head->prev = newnode;
	newnode->next = head;
	head = newnode;
} 
void print(){
	struct node* temp = head;
	printf("forward : ");
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void reverseprint()
{
	 //traversing to the last of linked list
	struct node*temp = head;
	if(temp==NULL) return;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	//now traversing back and printing the reverse list
	printf("reverse :\n" );
	while(temp!= NULL)
	{
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}
int main()
{
	head = NULL; //empty initially
	insertathead(20);insertathead(30);insertathead(40);
	print();
	reverseprint();	
}
