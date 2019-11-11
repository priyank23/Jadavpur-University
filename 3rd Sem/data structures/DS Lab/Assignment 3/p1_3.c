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
void delete_front(node **head)            //for deleting the first node of the list
{
	node *temp=*head;
	(*head)=(*head)->next;
	temp->next=NULL;
	free(temp);
}
int delete_after(node *prev)             //for deleting a node after a given node 
{
	if(prev->next==NULL || prev==NULL) return -1;
	else if((prev->next)->next==NULL)
	{
		node *cur=prev->next;
		prev->next=NULL;
		free(cur);
		return 0;
	}
	else
	{
		node *temp1,*temp2;
		temp1=prev->next;
		temp2=temp1->next;
		temp1->next=NULL;
		prev->next=temp2;
		free(temp1);
		return 0;
	}
}
void print_l(node *head)       //for printing the list
{
	node *cur=head;
	printf("The list is:\n");
	while(cur!=NULL)
	{
		printf("%d\n",cur->data);
		cur=cur->next;
	}
}
int main(void)            //main begins here
{ 
	node *head,*cur=NULL,*temp;  //declaring pointers
	int val;
	head=(node*)malloc(sizeof(node*));//allocating memory for head node
	temp=(node*)malloc(sizeof(node*));//alocating memory for temp node
	init_l(&head); //initialising head node with null
	cur=head;      
	printf("Enter the data of the list.(-1 to break).\n");  //taking the input for the list 
	scanf("%d",&val); 
	if(val!=-1)
	{
		temp->data=val;
		temp->next=NULL;
		cur=temp;
		scanf("%d",&val);
	}head=cur;
	while(val!=-1)
	{
		temp=(node*)malloc(sizeof(node*));
		temp->data=val;
		temp->next=NULL;
		cur->next=temp;
		cur=cur->next;
		scanf("%d",&val);
	}
	while(1){    //menu driver starts
	printf("What do you want to do?\n");
	printf("1.Check whether the list is or not.\n2.Insert at front.\n3.Insert after a given position.\n4.Delete front.\n5.Delete after a goven position.\n6.Check the pointer is at end of the list or not.\n7.Exit\n");
	int choice,pos;
	scanf("%d",&choice);  //taking the choice from the user
	node *target=(node*)malloc(sizeof(node*));
	switch(choice)
	{
		case 1:if(empty_l(head)) printf("The list is empty.\n");   //checking whether the list is empty or not 
			   else print_l(head);
			   break;
		
		case 2:printf("Enter the value.\n"); 
				scanf("%d",&val);
				target->data=val;   //filling the target node
				target->next=NULL;
				insert_front(&target,&head); //inserting at the front
				print_l(head);
				break;
		
		case 3:printf("Enter the position after which you want to insert the node and the value.\n");
			   scanf("%d%d",&pos,&val);
			   cur=head;
			   target->data=val;  //filling the target node
			   target->next=NULL;
			   if(pos!=0) //if position is 0,we are inserting at the front
			   {
			   while(--pos)
			   {
			   		cur=cur->next;
			   }
			   insert_after(&target,cur);
			   }
			   else insert_front(&target,&head);
			   print_l(head);  
			   break;
		
		case 4:delete_front(&head);   //deleting at the front
			   print_l(head);  
			   break;
		
		case 5:printf("Enter the position to be deleted.\n");  //taking the position from the user to be deleted
			   scanf("%d",&pos);
			   cur=head;
			   while(--pos!=1)   //updating the pointer to the given position
			   cur=cur->next;
				int x=delete_after(cur); //deleting the node 
				if(x==-1) printf("Node at this position does not exist.\n");
				else print_l(head);
			   break;
		
		case 6: x=atend_l(cur);  //checking whether the pointer is at end or not
				if(x==1) printf("The pointer is at end of the list.\n");
				else printf("The pointer is not at end of the list.\n");
				break;
		
		case 7:return 0;			   	   			    
	}printf("\n");
	}
}
