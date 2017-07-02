#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node *head;
struct node *last;
void printing(struct node *head)
{
	struct node *current =head;
	while(current!=NULL)
	{
		printf("%d ->",current->data);
		current=current->next;
	}
	printf("\n");
}
struct node *enque(struct node *last,int val)
{
	if(last==NULL)
	{
		struct node *t=(struct node *)malloc(sizeof(struct node));
		t->data=val;
		t->next=NULL;
		head=t;
		return t;
	}
	else
	{
		struct node *t=(struct node *)malloc(sizeof(struct node));
		t->data=val;
		t->next=NULL;
		last->next=t;
		return t;//t is the new last do like last=enque(last,5);
	}
}
struct node *deque(struct node *head)
{
	if(head==NULL){
		printf("Queue is empty");return NULL;
	}
	else
	{
		head=head->next;
		return head;
	}
}
int main ()
{
	last=enque(last,6);
	last=enque(last,7);
	last=enque(last,8);
	printing(head);
	head=deque(head);
	printing(head);
	head=deque(head);
	printing(head);
	head=deque(head);
	printing(head);
	head=deque(head);
	printing(head);
	return 0;
}
