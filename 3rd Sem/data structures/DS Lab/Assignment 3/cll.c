#include<stdio.h>
#include<stdlib.h>
typedef struct Node{          //declaring structure for making the node
	int data;
	struct Node *next;
} node;
void init_l(node **cur)      //for initialising a node with null
{
	*cur=NULL;
}
int empty_l(node *tail)      //for checking whether the list is empty or not
{
	if(tail==NULL) return 1;
	else return 0;	
}
int atend_l(node *cur,node *tail)      //for checking whether the current node is at end of the list or not
{
	if(cur==tail) return 1;
	else return 0;
}
void insert_front(node *target,node *tail)  //for inserting a node in the front of the linked list
{
	//node *cur=*target;
	if((tail)==NULL) tail=target;
	else
	{
		target->next=(tail)->next;
		(tail)->next=target;
	}
}
void insert_after(node *target,node *prev)   //for inserting a node after a given node in a list
{
		node *cur=NULL;
		cur=prev->next;
		prev->next=target;
		(target)->next=cur;
}
void print_l(node *tail)       //for printing the list in the same order
{
	node *cur=tail->next;
	if(tail==NULL)
	{
		printf("MEMORY ERROR!!!\n");
		return;
	}
	printf("The list is:\n");
	while(cur!=tail)
	{
		printf("%d\n",cur->data);
		cur=cur->next;
	}
	printf("%d\n",cur->data);
}
node *unordered_search(node **tail,int key)   //searching for a key in an unordered list
{
	node *temp;
	if((*tail)==NULL) return (*tail);
	else
	{
		temp=(*tail)->next;
		while(temp->next!=(*tail))
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
		if((*tail)->data==key)
		{
			node *cur=(*tail);
			temp->next=cur->next;
			*tail=temp;
			cur->next=NULL;
			return cur;
		}
		return 0;
	}
}
node *ordered_search(node **tail,int key)  //searching for a key in an ordered list
{
	node *temp;
	int tmp;
	if((*tail)==NULL) return *tail;
	else
	{
		temp=(*tail)->next;
		tmp=temp->data;
		while(temp->next!=(*tail))
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
		if((*tail)->data==key)
		{
			node *cur=(*tail);
			temp->next=cur->next;
			(*tail)=temp;
			cur->next=NULL;
			return cur;
		}
	}
}
int size(node *tail)  //finding th size of the list
{
	int l=0;
	node *temp=tail->next;
	if(tail==NULL) return 0;
	else
	{
		while(temp!=tail)
		{
			l++;
			temp=temp->next;
		}
		l++;
		return l;
	}
}
int list_cmp(node *tail1,node *tail2)   //comparing two lists
{
	if(tail1==NULL && tail2==NULL)
		return 1;
	else if(size(tail1)==size(tail2))
	{
		node *temp1=tail1->next,*temp2=tail2->next;
		while(temp1!=tail1)
		{
			if(temp1->data==temp2->data)
			{
				temp1=temp1->next;
				temp2=temp2->next;
			}
			else return 0;
		}
		if(temp1->data==temp2->data) return 1;
		return 0;
	}
	else return 0;			 
}
int revprint_l(node *head,node *tail)    //reverse printing a list
{
	if(head==tail)
	{
		printf("%d\n",head->data);
		return 0;
	}
	else
	{
		revprint_l(head->next,tail);
		printf("%d\n",head->data);
		return 0;
	}
}
void append_l(node **tail1,node *tail2)    //appending a list at the end of another
{
	node *cur=(*tail1)->next;
	(*tail1)->next=tail2->next;
	tail2->next=cur;
	*tail1=tail2;
}
void delete_list(node **tail)    //deleting the list
{
	node* cur=(*tail)->next;
	(*tail)->next=NULL;
	(*tail)=cur;
	while((*tail)!=NULL)
	{
		(*tail)=(*tail)->next;
		free(cur);
		cur=(*tail);
	}
}
node *rem_duplicates_unordered(node *tail)   //removing duplicates in an unordered list
{
	int L=size(tail),i,j;
	int a[L];
	node *temp=tail->next;
	for(i=0;i<L;i++)
		a[i]=0;
	a[0]=temp->data;
	i=0;
	while(temp!=tail)
	{
		int k=0;
		for(j=0;j<=i;j++)
		{
			if((temp->next)->data==a[j])
			{
				node *cur=temp->next;
				temp->next=cur->next;
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
	return tail;
}
node *reverseList2(node *tail)			//for reversing the list using iteration method
{
	node* after=tail->next;
	if(after==NULL || after->next==after) return after;
	node *prev=after,*p=NULL;
	after=after->next;
	prev->next=NULL;
	p=after;
	after=after->next;
	while(after!=tail)
	{
		p->next=prev;
		prev=p;
		p=after;
		after=after->next;
	}
	p->next=prev;
	tail=after->next;
	after->next=p;
	tail->next=after;
	return tail;
}
node* insert(int i)
{
	node* newh=(node*)malloc(sizeof(node));
	printf("Enter the value at node %d\n",i);
	int x;
	if(scanf("%d",&x))
	{
		newh->data=x;
		newh->next=insert(++i);
	}
	else return NULL;
	return newh;
}
void delete_nth_first_last_node(node** head,int n)
{
	if((*head)==NULL)
	{
		printf("Empty list!\n");
		return;
	}
	
	if(size((*head))==1)
	{
		if(n==1)
		{
			node* temp=(*head)->next;
			(*head)->next=NULL;
			(*head)=temp;
		}
		else
		{
			printf("Wrong input of n\n");
		}
	}
	else if(size((*head))==n)
	{
		node* temp=(*head)->next;
		(*head)->next=NULL;
		(*head)=temp;
		//delete last node
		int count=1;
		node* h=(*head);
		while(count!=n-2)
		{
			(*head)=(*head)->next;
			count++;
		}
		//printf("%d\n",(*head)->data);
		temp=(*head)->next;
		(*head)->next=temp->next;
		temp->next=NULL;
	}
	else
	{
		if(n>size((*head)) || n==0)
			printf("Wrong input of n\n");
		else
		{
			int s=size(*head);
			node* temp=(*head)->next;
			(*head)->next=NULL;
			(*head)=temp;
			//nth
			//last
			int count=1;
			node* h=(*head);
			while(count!=n-2)
			{
				(*head)=(*head)->next;
				count++;
			}
				printf("%d\n",(*head)->data);
			temp=(*head)->next;
			(*head)->next=temp->next;
			temp->next=NULL;
			//(*head)=h;
			if(s-n!=1)//error inside this
			{
				(*head)=(*head)->next;
				while(count!=s-1)
				{
					(*head)=(*head)->next;
					count++;
				}	
			}
				printf("%d\n",(*head)->data);
			(*head)->next=NULL;
			(*head)=h;
		}
	}
}
void ordered(node* head)
{
	node* ptr=head->next;
	int count=1,eq=1;
	// if head is NULL
	if(head==NULL)
	{
		printf("List is empty!\n");
	}
	else if(head->next==NULL)
	{
		printf("List is ordered\n");
	}
	else
	{
		while(head->next!=NULL)
		{
			if(head->data>ptr->data)
				count--;
			else if(head->data<ptr->data)
				count++;
			else
				eq++;
		}
		if(eq==size(head) || count==size(head) || count==-size(head) || count+eq==size(head) || eq-count==size(head))
			printf("List is ordered\n");
		else
			printf("List is not ordered\n");
	}
}
void movelast(node** head)
{
	node* temp=*head;
	while(((*head)->next)->next!=NULL)
	{
		*head=(*head)->next;
	}
	node* ptr=(*head);
	(*head)=(*head)->next;
	ptr->next=NULL;
	(*head)->next=temp;
}
void sort(node** head)
{
	//if u want descending order then reverse the list
	int temp;
	node* ptr1;
	node* ptr2;
	for(ptr1=*head;ptr1!=NULL;ptr1=ptr1->next)
	{
		for(ptr2=ptr1->next;ptr2!=NULL;ptr2=ptr2->next)
		{
			if(ptr1->data>ptr2->data)
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
		}
	}
}
void swap(node **head)
{
	//if((*head)==NULL || (*head)->next==NULL) return 0;
	node *temp1=(*head);//,*temp2=(*head)->next;
	
	int val=0;
	while(temp1!=NULL && temp1->next!=NULL)
	{
		val=temp1->data;
		temp1->data=(temp1->next)->data;
		(temp1->next)->data=val;
		temp1=(temp1->next)->next;
		//temp2=(temp2->next)->next;
	}
}
void rotate(node** head)
{
	int i,n;
	printf("Enter the no of times list has to be rotated\n");
	scanf("%d",&n);
	for (i = 1; i <n; ++i)
	{
		movelast(head);
	}
}
void delete_alter(node** head)
{
	node *ptr,*ptr1;
	int n=size(*head);
	for(ptr=*head;ptr!=NULL;ptr=ptr->next)
	{
		ptr1=ptr->next;
		ptr->next=ptr1->next;
		ptr1->next=NULL;
		if(n%2==1 && ptr->next->next==NULL)
			break;
	}
}
int main()
{
	node *tail,*head=insert(1);
	node* temp=head;
	while(temp->next!=NULL) temp=temp->next;
	tail=temp;
	tail->next=head;
	printf("%d\n",size(tail));
	print_l(tail);
	revprint_l(head,tail);
	delete_list(&tail);
	print_l(tail);
//	ordered_search(&head,5);
//	print_l(head);
//	printf("The size of the list is %d\n",size_l(head));
//	swap(&head);
//	print_l(head);
//	delete_list(&head);
//	print_l(head);
	//head=rem_duplicates_unordered(head);
//	print_l(head);
	return 0;
}
