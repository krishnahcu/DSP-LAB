#include<stdlib.h>
#include <stdio.h>

void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_pos();
void delete_val();
void reverse();
 
 
struct node
{
        int info;
        struct node *next;
};
struct node *start=NULL;
int main()     
{
        int choice;
        while(1){
               
                printf("\n MENU                             ");
                printf("\n 1.Display    ");
                printf("\n 2.Insert at the beginning    ");
                printf("\n 3.Insert at the end  ");
                printf("\n 4.Insert at specified position       ");
                printf("\n 5.Delete from specified position     ");
                printf("\n 6.Delete from specified value       ");
                printf("\n 7.Reverse  ");
                printf("\n 8.exit  ");
                printf("\n--------------------------------------");
                printf("\nEnter your choice:t");
                scanf("%d",&choice);
                if(choice == 1)
                {
                	display();
                	break;
				}
				if(choice == 2)
				{
					insert_begin();
					break;	
				}
				if(choice == 3)
				{
					insert_end();
					break;
				}
				if(choice == 4)
				{
					insert_pos();
					break;
				}
				if(choice == 5)
				{
					delete_pos();
					break;
				}
				if(choice == 6)
				{
					delete_val();
					break;
				}
				if(choice == 7)
				{
					reverse();
					break;
				}
				if(choice == 8)
				{
					exit(0);
					break;
				}
				else{
					printf("\n Invalid choice");
				}
                
        }
        return 0;
}

void display()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("\nList is empty:");
                return;
        }
        else
        {
                ptr=start;
                printf("\nThe List elements are:");
                while(ptr!=NULL)
                {
                        printf("%dt",ptr->info );
                        ptr=ptr->next ;
                }
        }
}
void insert_begin()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:");
                return;
        }
        printf("\nEnter the data value for the node:t" );
        scanf("%d",&temp->info);
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                temp->next=start;
                start=temp;
        }
}
void insert_end()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:");
                return;
        }
        printf("\nEnter the data value for the node:t" );
        scanf("%d",&temp->info );
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
}
void insert_pos()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:");
                return;
        }
        printf("\nEnter the position for the new node to be inserted:t");
        scanf("%d",&pos);
        printf("\nEnter the data value of the node:t");
        scanf("%d",&temp->info) ;
  
        temp->next=NULL;
        if(pos==0)
        {
                temp->next=start;
                start=temp;
        }
        else
        {
                for(i=0,ptr=start;i<pos-1;i++) { ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("\nPosition not found:[Handle with care]");
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}

void delete_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("\nThe List is Empty:");
                exit(0);
        }
        else
        {
                printf("\nEnter the position of the node to be deleted:t");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=start;
                        start=start->next ;
                        printf("\nThe deleted element is:%dt",ptr->info  );
                        free(ptr);
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not Found:");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("\nThe deleted element is:%dt",ptr->info );
                        free(ptr);
                }
        }
}
void delete_val()
{
	
}
void reverse()
{
	 struct node *prevNode, *curNode;
	 struct node * head;

    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL; 

        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode; 

        printf("\nSuccessfully reversed list");
    }
	
}
