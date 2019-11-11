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
int empty_l(node *head)      //for checking whether the list is empty or not
{
	if(head==NULL) return 1;
	else return 0;	
}
int atend_l(node *cur)      //for checking whether the current node is at end of the list or not
{
	if(cur->next==NULL) return 1;
	else return 0;
}
void insert_front(node **target,node **head)  //for inserting a node in the front of the linked list
{
	//node *cur=*target;
	if(*head==NULL) *head=*target;
	else
	{
		(*target)->next=*head;
		*head=*target;
	}
}
void insert_after(node **target,node *prev)   //for inserting a node after a given node in a list
{
	if(prev->next==NULL)
	{
		prev->next=*target;
	}
	else
	{
		node *cur=NULL;
		cur=prev->next;
		prev->next=*target;
		(*target)->next=cur;
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
int size(node *head)  //finding th size of the list
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
	else if(size(head1)==size(head2))
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
		revprint_l(head->next);
		printf("%d\n",head->data);
		return 0;
	}
}
void append_l(node **head1,node *head2)    //appending a list at the end of another
{
	node *temp=*head1;
	while(temp->next!=NULL) temp=temp->next;
	temp->next=head2;
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
	int L=size(head),i,j;
	int a[L];
	node *temp=head;
	for(i=0;i<L;i++)
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
	node *prev=after,*p=NULL;
	after=after->next;
	prev->next=NULL;
	p=after;
	after=after->next;
	while(after->next!=NULL)
	{
		p->next=prev;
		prev=p;
		p=after;
		after=after->next;
	}
	p->next=prev;
	after->next=p;
	return after;
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
	else
	{
		return NULL;
	}
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
	node *head=insert(1);
	print_l(head);
//	ordered_search(&head,5);
//	print_l(head);
//	printf("The size of the list is %d\n",size_l(head));
//	swap(&head);
//	print_l(head);
//	delete_list(&head);
//	print_l(head);
	head=rem_duplicates_unordered(head);
	print_l(head);
	return 0;
}
