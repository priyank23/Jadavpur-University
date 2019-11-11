#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next,*prev;
}node;


void init_l(node *cur)
{
    cur=NULL;
}

int empty_l(node *head)
{
    if(head==NULL) return 1;
    return 0;
}

int atend_l(node *cur)
{
    if(cur->next==NULL) return 1;
    return 0;
}

void insert_front(node *target,node **head)
{
    if(*head==NULL) *head=target;
    else{
        target->next=(*head);
        target->prev=NULL;
        (*head)->prev=target;
        (*head)=target;
    }
}

void insert_after(node *target,node *prev)
{
    node *cur=prev->next;
    prev->next=target;
    target->prev=prev;
    target->next=cur;
    cur->prev=target;
}

void delete_front(node **head)
{
    if((*head)==NULL) printf("Memory Error!!!\n");
    else{
        node *cur=(*head);
        (*head)=(*head)->next;
        (*head)->prev=NULL;
        free(cur);
    }
}

void delete_after(node *prev)
{
    if(prev->next==NULL) printf("No node available to be deleted.\n");
    else{
        node *cur=(prev->next),*temp=cur->next;
        temp->prev=NULL;
        cur->next=temp;
        free(cur);
    }
}
void print_l(node *head)       //for printing the list in the same order
{
	node *cur=head;
	if(head==NULL)
	{
		printf("MEMORY ERROR!!!\n");
		return;
	}
	printf("The list is:\n");
	while(cur!=NULL)
	{
		printf("%d\n",cur->data);
		cur=cur->next;
	}
}
node *unordered_search(node **head,int key)   //searching for a key in an unordered list
{
	node *temp;
	
	if((*head)==NULL) return (*head);
	else
	{
		temp=(*head);
		if((*head)->data==key)
		{
			(*head)=(*head)->next;
			temp->next=NULL;
			return temp;
		}
		while(temp->next!=NULL)
		{
			if((temp->next)->data==key)
			{
				node *cur=temp->next;
				temp->next=cur->next;
				cur->next=NULL;
				return cur;
			}
			else temp=temp->next;
		}
		return 0;
	}
}
node *ordered_search(node **head,int key)  //searching for a key in an ordered list
{
	node *temp;
	int tmp;
	if((*head)==NULL) return *head;
	else
	{
		temp=(*head);
		if((*head)->data==key)
		{
			(*head)=(*head)->next;
			temp->next=NULL;
			return temp;
		}
		tmp=(*head)->data;
		while(temp->next!=NULL)
		{
			if((temp->next)->data==key)
			{
				node *cur=temp->next;
				temp->next=cur->next;
				cur->next=NULL;
				return cur;
			}
			else if(tmp<key && temp->data<key)
			{
				tmp=temp->data;
				temp=temp->next;
			}
			else return 0;
		}
	}
}
int size_l(node *head)  //finding th size of the list
{
	int l=0;
	node *temp=head;
	if(head==NULL) return 0;
	else
	{
		while(temp!=NULL)
		{
			l++;
			temp=temp->next;
		}
		return l;
	}
}
int list_cmp(node *head1,node *head2)   //comparing two lists
{
	if(head1==NULL && head2== NULL)
		return 1;
	else if(size_l(head1)==size_l(head2))
	{
		node *temp1=head1,*temp2=head2;
		while(temp1!=NULL)
		{
			if(temp1->data==temp2->data)
			{
				temp1=temp1->next;
				temp2=temp2->next;
			}
			else return 0;
		}
		return 1;
	}
	else return 0;			 
}
int revprint_l(node *head)    //reverse printing a list
{
	if(head->next==NULL)
	{
		printf("%d\n",head->data);
		return 0;
	}
	else
	{
		node* temp=head;
		while(temp->next!=NULL) temp=temp->next;
		while(temp->prev!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->prev;
		}
		return 0;
	}
}
void append_l(node **head1,node *head2)    //appending a list at the end of another
{
	node *temp=*head1;
	while(temp->next!=NULL) temp=temp->next;
	temp->next=head2;
	head2->prev=temp;
}
void delete_list(node **head)    //deleting the list
{
	node *temp=(*head);
	while((*head)!=NULL)
	{
		(*head)=(*head)->next;
		temp=(*head);
		free(temp);
	}
}
node *rem_duplicates_unordered(node *head)   //removing duplicates in an unordered list
{
	int size=size_l(head),i,j;
	int a[size];
	node *temp=head;
	for(i=0;i<size;i++)
		a[i]=0;
	a[0]=head->data;
	i=0;
	while(temp->next!=NULL)
	{
		int k=0;
		for(j=0;j<=i;j++)
		{
			if((temp->next)->data==a[j])
			{
				node *cur=temp->next;
				temp->next=cur->next;
				(cur->next)->prev=temp;
				free(cur);
				k=1;
				break;
			}
		}
		if(k==0)
		{
			a[++i]=(temp->next)->data;
			temp=temp->next;
		}
	}
	return head;
}
node *reverseList2(node *after)			//for reversing the list using iteration method
{
	if(after==NULL || after->next==NULL) return after;
	node *pre=after,*p=NULL;
	after=after->next;
	pre->next=NULL;
	p=after;
	after=after->next;
	p->prev=after;
	pre->prev=p;
	while(after->next!=NULL)
	{
		p->next=pre;
		pre=p;
		p=after;
		after=after->next;
		p->prev=after;
		
	}
	p->next=pre;
	after->next=p;
	after->prev=NULL;
	p->prev=after;
	return after;
}
node* insert(int i,node* preh)
{
	node* newh=(node*)malloc(sizeof(node));
	printf("Enter the value at node %d\n",i);
	int x;
	if(scanf("%d",&x))
	{
		newh->data=x;
		newh->next=insert(++i,newh);
		newh->prev=preh;
	}
	else
	{
		return NULL;
	}
	return newh;
}
int main(void)
{
	node *head=insert(1,NULL);
	print_l(head);
	head=reverseList2(head);
	print_l(head);
	printf("\n\n%d\n",size_l(head);
/*	unordered_search(&head,5);
	print_l(head);
	ordered_search(&head,4);
	print_l(head);*/
}

