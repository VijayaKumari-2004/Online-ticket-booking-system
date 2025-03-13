//NUMBER--TICKET NUMBER
//NAME--PERSON NAME


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ticket{
	char name[100];
	int data;
	struct ticket *next;
}*front=NULL,*rear=NULL,*top=NULL;
void book_ticket(char name[],int number){
	struct ticket *nn;
	nn=(struct ticket*)malloc(sizeof(struct ticket));
	nn->data=number;
	strcpy(nn->name,name);
	nn->next=NULL;
    if(front==NULL){
    	front=nn;
    	rear=nn;
	}
	else{
		rear->next=nn;
		rear=nn;
	}	
	printf("Ticket booked for:%s and Ticket number:%d \n",name,number);	
}
void display_ticket(){
	struct ticket *temp;
	temp=front;
	if(front==NULL){
		printf("NO booking were done!\n");
	}
	printf("Booked tickets:\n");
	while(temp!=NULL){
		printf("person name:%s,ticket number:%d\n",temp->name,temp->data);
		temp=temp->next;
	}
	
}

void cancelled_ticket(char name[30]){
	if(front==NULL){
		printf("NO Bookings to cancel!\n");
		return ;
	}
	struct ticket *del=front;
	front =front->next;
		if(front==NULL)
	     rear=NULL;
	del->next=top;
	top=del;
	printf("The ticket number:%d cancelled for %s\n",del->data,del->name);
}
void display_cancel(){
	struct ticket *temp=top;
	if(top==NULL){
	
	  printf("NO cancelled tickets!\n");
	  return ;
  }  
  printf("Cancelled tickets were:\n") ;
  while(temp!=NULL){
		printf("person name:%s,ticket number:%d\n",temp->name,temp->data);
		temp=temp->next;
	}	
}
int main(){
	int choice,tn=5674; //tn--ticket number
	char   name[30];
	printf("\n--*********************************ONLINE TICKET BOOKING SYSTEM**************************************--\n");
		printf("1.book ticket\n 2.display tickter\n 3.cancle ticket\n 4.display cancelled ticket\n 5.exit\n");
	while(1){
		
		printf("Enter the choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the passenger name: ");
				scanf("%s",name);
				book_ticket(name,tn++);
				break;
			case 2:
				display_ticket();
				break;
			case 3:
			  	cancelled_ticket(name);
			  	break;
			case 4:
			    display_cancel();
				break;
			case 5:
			    printf("\nThank you");
				break;
			default:
			  printf("\nNot valid choice");	 	
		}
		printf("\ncontinue 1 to end 0:");
		scanf("%d",&choice);
		if(choice==0)
		   break;
	}      
	
}
