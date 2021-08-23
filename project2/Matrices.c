#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct node123
{
	int data;
	struct node123 *link;
}node123;

void lawmat()
{
FILE *ptr;
char str1;
ptr=fopen("mat.txt","r");
str1 = fgetc(ptr);
while (str1 != EOF)
		{
			printf ("%c", str1);
			str1 = fgetc(ptr);
		}
fclose(ptr);
}

node123 *head1,*head2;


void addition(node123 **head1,node123 **head2);


int input(node123 **head);


void display(node123 **head,int x);

void input2(node123 **head,int x);

void soleq(node123 **head1,node123 **head2,int x);


void mult(node123 **head1,node123 **head2,int x);

void det(node123 **head,int x);


int mat()
{

	int x=1;
	while(x==1)
	{
		printf("                                     MATRICES AND DETERMINANT\n");
	printf("Enter operation to be performed\n");
	printf("1-Multiplication\n2-Addition\n3-Detrminant\n4-solve equation\n5-All Formulas");
	int n;
	scanf("%d",&n);
	head1=head2=NULL;
	switch(n)
	{
		case 1:
		{
			printf("Note-:Multiplication can be performed only with [SQUARE matrices]\n");
			int x=input(&head1);    //stores first matrix in linked list
			input(&head2);          //stores second matrix in linked list
			mult(&head1,&head2,x);  //calls mutliplication function
			head1=head2=NULL;       //re initiate linked list
		}break;
		case 2:
		{
			int x=input(&head1);
			input(&head2);
		    addition(&head1,&head2);
		    display(&head1,x);    //print the resultant linked list on screen
			head1=head2=NULL;
		}break;
		case 3:
		{
			printf("Determinant can be calculated of 2nd order matrix only\n");
			int x=input(&head1);
			det(&head1,x);
			head1=head2=NULL;

		}break;
		case 4:
		{
			printf("Enter coefficient matrix\n");
			int x=input(&head1);
			input2(&head2,x);     //calls special function to store columb matrix
			soleq(&head1,&head2,x);
			head1=head2=NULL;
		}break;
		case 5:lawmat();
		break;
		default:
		printf("wrong input\n");
	}
	printf("\nPress 1 for Matrix menu or any other key to end matrix operations  \n");
	scanf("%d",&x);
}
return 0;
}


int input(node123 **head)
{
	printf("Enter order of SQUARE Matrix-");
	int n,i;
	scanf("%d",&n);
	printf("\nenter elements\n")
	node123 *current=NULL;
    for(i=0;i<n*n;i++)   //creates link list
    {
    	node123 *newnode123=(node123 *)malloc(sizeof(node123));
    	scanf("%d",&newnode123->data);
    	if(*head==NULL)
    	{
    		*head=newnode123;
    		current=newnode123;

    	}
    	else
    	{
    		current->link=newnode123;
    		current=newnode123;
    	}
    	newnode123->link=NULL;
    }

   return n;

}


void addition(node123 **head1,node123 **head2)
{
	int i;

	node123 *temp1=*head1;
	node123 *temp2=*head2;
	while(temp1!=NULL)  //add two matrix and stores in first linked list
	{

        temp1->data=(temp1->data)+(temp2->data);
        temp1=temp1->link;
        temp2=temp2->link;
	}

}


void display(node123 **head,int x)
{
	node123 *temp=*head;
	int i,j;
	for(i=0;i<x;i++)         //print resultant matrix in form of matrix
	{
		for(j=0;j<x;j++)
		{
			printf("%d ",temp->data);



		temp=temp->link;

	    }
	printf("\n");
    }

}
void mult(node123 **head1,node123 **head2,int x)
{
	node123 *temp1=*head1;
	node123 *temp2=*head1;
	int i,j,k,l,r=0;
	for(i=0;i<x;i++)//controlls rows
	{
		node123 *t3=temp2;
        for(l=0;l<x;l++)      //shifts rows
        {
        	node123 *t1=temp1;
        	node123 *t2=t3;
		    for(j=0;j<x;j++)  //mutiply and add specific column and rows
		      {
			     r=r+t1->data*t2->data;
			     if(t1!=NULL)
			        t1=t1->link;   //shifts  to next element in row
			    for(k=0;k<x;k++)   //shifts to next element of specific column
			    {
			     	if(t2!=NULL)
				        t2=t2->link;
				}
		      }

		    printf("%d ",r );    //print the resultan element
		    r=0;
		    t3=t3->link;
	    }
	    printf("\n");
		for(k=0;k<x;k++)        //shifts to next row
		{
			if(temp1!=NULL)
			    temp1=temp1->link;
	    }
	}

}
void det(node123 **head,int x)
{
	node123 *temp1,*temp2,*temp3;
	temp1=temp2=temp3=*head;
	if(x==2)
	{
		while(temp2->link!=NULL)
			temp2=temp2->link;
		while(temp3->link!=temp2)
			temp3=temp3->link;
		int det=0;
		det=det+(temp1->data)*(temp2->data);
		temp1=temp1->link;
		det=det-(temp1->data)*(temp3->data);
		printf("%d\n",det );
	}
	else
		printf("out of scope\n");

}
void input2(node123 **head,int x)
{
	printf("Enter constant matrix\n");
	int i;
	node123 *current=NULL;
	for(i=0;i<x;i++)
	{
		node123 *p=(node123 *)malloc(sizeof(node123));
	    scanf("%d",&p->data);
	    if(*head==NULL)
	    {
          *head=p;
          current=p;
	    }
	    else
	    {
	    	current->link=p;
	    	current=p;
	    }
	    p->link=NULL;
    }

}
void soleq(node123 **head1,node123 **head2,int x)
{
	node123 *temp1=*head1;
	node123 *temp2=*head2;
	int i,j,z=0;
	for(i=0;i<x;i++)
	{
		node123 *t3=temp1;
		node123 *t4=temp2;

		for(j=0;j<x;j++)
		{
			z=z+(t3->data)*(t4->data);
			t3=t3->link;
			t4=t4->link;
		}
		char k=x;
		k++;

		printf("%c=%d\n",k,z );
		z=0;
		for(j=0;j<x;j++)
		{
			if(temp1!=NULL)
			  temp1=temp1->link;
		}
	}

}
