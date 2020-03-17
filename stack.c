#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head;
struct node *push(struct node *head,int val)
{
	if(head==NULL)
	{
		struct node *t=(struct node *)malloc(sizeof(struct node));
		t->data=val;
		t->next=NULL;
		return t;
	}
	struct node *t=(struct node*)malloc(sizeof(struct node));
	t->data=val;
	t->next=head;
	return t;
}
struct node *pop(struct node*head)
{
	if(head!=NULL){
	struct node *t=(struct node*)malloc(sizeof(struct node));
	t=head->next;
	return t;
	}
	else
		printf("Stack is empty");
}

void printing(struct node *head)
{
	struct node *current = head;
	while(current!=NULL)
	{
		printf("%d->",current->data);
		current=current->next;
	}
	printf("\n");
}
int main ()
{
	int i=0;
	while(i<10)
	{
	int n;
	char ch;
	scanf(" %c",&ch);
	if(ch=='+'){
		scanf("%d",&n);
		head=push(head,n);
	}
	else{
		head=pop(head);
	}
		i++;
	}
	printing(head);
	return 0;
}

