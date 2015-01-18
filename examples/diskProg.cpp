#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
 
int max,min,disk,mark[100],q[100],rear=0,size,head,seek;
 
void ins();
void dis();
void fcfs();
void sstf();
void clook();
void scan();
void look();
void fmaxmin();
 
int main()
{
	int i,ch;
 
	printf("\nEnter the size of the disk (in tracks) : ");
	scanf("%d",&disk);
	printf("\nEnter the current position of the disk head : ");
	scanf("%d",&head);
	printf("\nEnter the number of requests : ");
	scanf("%d",&size);
	if(size!= 0)
		printf("\nEnter the requests  - :   \n\n");
	else
	{
		printf("No requests to be made ");
		
	}
	for(i=1;rear<=size;i++)
	{
		ins();
		mark[i] = 0;
	}
	fmaxmin();
	q[0] = head;
	printf("\n\n\t\t\t\tDISK SCHEDULING\n\n");
	printf("1. FCFS \n2. SSTF \n3. SCAN\n4. LOOK \n5. CLOOK\n6. EXIT\n");
	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
 
		switch(ch)
		{
			case 1 :  {
					head = q[0];
					seek = 0;
					fcfs();
					break;
				  }
			case 2 :  {
					head = q[0];
					seek = 0;
					for(i=1;i<=size;i++)
						mark[i] = 0;
					for(i = 1;i<=size;i++)
						sstf();
					printf("\n\nThe total number of head movements is : %d",seek);
					break;	
				  }
			case 3 :  {
					head = q[0];
					seek = 0;
					for(i=1;i<=size;i++)
						mark[i] = 0;
					scan();
					break;	
				}
			case 4 :  {
					head = q[0];
					seek = 0;
					for(i=1;i<=size;i++)
						mark[i] = 0;
					look();
					break;	
				  }
			case 5 :  {
					head = q[0];
					seek = 0;
					for(i=1;i<=size;i++)
						mark[i] = 0;
					clook();
					break;
				  }
 
			case 6 :  exit(0);
 
			default : {
					printf("\n\nINVALID CHOICE!!!\n");
					break;
				  }
		}
	}
}
 
void ins()
{
	 int i;
	 rear++;
	 if(rear<=size)
	 {
		printf("Enter the request %d to track no. : ",rear);
		 scanf("%d",&i);
	}
	if(i>disk)
	{
		printf("\nEnter valid track request\n\n");
		rear--;
	}
	else
		q[rear] = i;
}
 
void dis()
{
	 int i;
	 for(i=1;i<=size;i++)
		printf("%d\t",q[i]);
}
 
void fcfs()
{
	int i;
	printf("\n\n\t\tFIRST COME FIRST SERVE\n\n");
	q[0] = head;
	printf("\nWORK QUEUE : \n");
	dis();
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n\nThe sequence is . . .\n");
	for(i=1;i<=size;i++)
	{
		printf("\nHead moves from %d to %d",head,q[i]);
		seek += abs(head - q[i]);
		head = q[i];
	}
	printf("\n\nThe total number of head movements is : %d",seek);
}
 
void sstf()
{
	int low = disk,j,flag;
	for(j=1;j<=size;j++)
	{
		if(abs(head-q[j]) < low && mark[j] == 0)
		{
			low = abs(head-q[j]);
			flag = j;
		}
	}
	mark[flag] = 1;
	printf("\nHead moves from %d to %d...",head,q[flag]);
	head = q[flag];
	seek += low;
}
 
void scan()
{
	int i,j;
	printf("\n\n\t\t\t\tSCAN SCHEDULING\n\n");
	printf("\nWORK QUEUE : \n");
	dis();
	printf("\n\n--------------------------------------------------------------------------------\n");
	printf("\nThe sequence is. . .\n\n");
	if(head>0)
	{
		for(j=head;j>=0;j--)
		{
			for(i=1 ;i<=size;i++)
				{
				if((j == q[i] && mark[i] == 0))
				{
					mark[i] = 1;
					printf("\nHead moves from %d to %d...",head,q[i]);
					seek += abs(head- j);
					head = q[i];
				}
				}
			if(j==0)
				{
					seek += abs(head - j);
					head = 0;
				}
		}
	}
		head = 0;
		for(j=0;j<=disk;j++)
		{
			for(i=1;i<=size;i++)
			{
				if(j == q[i] && mark[i] == 0)
				{
					mark[i] = 1;
					if(head !=0)
						printf("\nHead moves from %d to %d...",head,q[i]);
					seek += abs(head - j);
					head = q[i];
				}
			}
		}
	printf("\n\nTotal number of head movements is : %d",seek);
}
 
void look()
{
	int i,j;
	printf("\n\n\t\t\t\tLOOK SCHEDULING\n\n");
	printf("\nWORK QUEUE : \n");
	dis();
	printf("\n\n--------------------------------------------------------------------------------\n");
	printf("\nThe sequence is. . .\n\n");
	      for(j=q[0];j<=max;j++)
		{
			for(i=1 ;i<=size;i++)
				if(j == q[i] && mark[i] == 0)
				{
					mark[i] = 1;
					printf("\nHead moves from %d to %d...",head,q[i]);
					seek += abs(head -j);
					head = q[i];
				}
		}
	if(head>min)
	{
		for(j=q[0];j>=0;j--)
		{
			for(i=1 ;i<=size;i++)
				if(j == q[i] && mark[i] == 0)
				{
					mark[i] = 1;
					printf("\nHead moves from %d to %d...",head,q[i]);
					seek += abs(head -j);
					head = q[i];
				}
		}
	}
	printf("\n\nTotal number of head movements is : %d",seek);
}
 
void clook()
{
	int i,j;
	printf("\n\n\t\t\t\tCLOOK SCHEDULING\n\n");
	printf("\nWORK QUEUE : \n");
	dis();
	printf("\n\n--------------------------------------------------------------------------------\n");
	printf("\nThe sequence is. . .\n\n");
	      for(j=q[0];j<=max;j++)
		{
			for(i=1 ;i<=size;i++)
				if(j == q[i] && mark[i] == 0)
				{
					mark[i] = 1;
					printf("\nHead moves from %d to %d...",head,q[i]);
					seek += abs(head -j);
					head = q[i];
				}
		}
	if(head>min)
	{
		for(j=0;j<=q[0];j++)
		{
			for(i=1 ;i<=size;i++)
				if(j == q[i] && mark[i] == 0)
				{
					mark[i] = 1;
					printf("\nHead moves from %d to %d...",head,q[i]);
					seek += abs(head -j);
					head = q[i];
				}
		}
	}
	printf("\n\nTotal number of head movements is : %d",seek);
}
 
void fmaxmin()
{
	int i;
	for(i = 1;i<=size;i++)
	{
		if(q[i]>max)
			max = q[i];
		if(q[i]<min)
			min = q[i];
	}
}
