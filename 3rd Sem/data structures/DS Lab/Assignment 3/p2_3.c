#include<stdio.h>
#include<stdlib.h>

typedef struct Node{          //declaring structure for making the node
	int data;
	struct Node *next;
} node;

void print_l(node *head)       //for printing the list
{
	node *cur=head;
	printf("the list is:\n");
	while(cur!=NULL)
	{
		printf("%d\n",cur->data);
		cur=cur->next;
	}
}

/*int scan(node *head,node **cur,FILE *fp)   //recursive function for taking input in reverse order
{
	int c;
	fscanf(fp,"%d\n",c);
    if(c!=-1)
    	return 0;
    else
	{
		scan(head,cur,fp);
		node *temp=(node*)malloc(sizeof(node*));//allocating memory for head node
		temp->data=c;
		temp->next=NULL;
		(*cur)->next=temp;
		(*cur)=(*cur)->next;
	}	
}*/

int main(void)
{
	FILE *fp=fopen("p2_3.txt","r"),*fp2=fopen("p2_3.txt","r");
	node *head1,*head2,*cur=NULL;
	head1=(node*)malloc(sizeof(node*));//allocating memory for head1 node
	head2=(node*)malloc(sizeof(node*));//allocating memory for head2 node
	cur=head1;
	int iter=0,c;
	while(!feof(fp))       //loop for printing the list in the order they are read
	{
		fscanf(fp,"%d\n",&c);
		
			node *temp=(node*)malloc(sizeof(node*));//allocating memory for head node
			temp->data=c;
			temp->next=NULL;
			if(iter==0)
			{
				head1->data=c;
				head1->next=NULL;
				iter++;
			}
			else
			{
				cur->next=temp;
				cur=cur->next;
			}
		
	}
	printf("In same order ");
	print_l(head1);
	fclose(fp);
	iter=0;
	while(!feof(fp2))       //loop for printing the list in reverse order
	{
		fscanf(fp2,"%d\n",&c);
		if(iter==0)
		{
			head2->data=c;
			head2->next=NULL;
			iter++;
		}
		else
		{
			node *cur2=(node*)malloc(sizeof(node*));
			cur2->data=c;
			cur2->next=head2;
			head2=cur2;
		}
	}
	fclose(fp2);
	printf("\nIn reverse order ");
	print_l(head2);
}
