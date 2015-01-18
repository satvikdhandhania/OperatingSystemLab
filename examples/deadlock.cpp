#include<stdio.h>
#include<conio.h>
struct process
{
 int all[5],req[5];
 int finish;      
       }pr[5];
main()
{
      int set1=0,set3=0,set4=0,req[5],set2=0,n,i,j,k,p,ava[5],work[5],set;
printf("\nEnter the number of types of resources ");
scanf("%d",&n);
printf("\nEnter the total number of processes ");
scanf("%d",&p);
for(i=0;i<p;i++)
{
                pr[i].finish=0;                
printf("\nEnter the allocated and requested resources of process p%d",i);
printf("\nAllocated\n");
for(j=0;j<n;j++)
scanf("%d",&pr[i].all[j]);
printf("\nRequest\n");
for(j=0;j<n;j++)
scanf("%d",&pr[i].req[j]);                
}
printf("\nEnter the available resources...\n");
for(j=0;j<n;j++)
{
scanf("%d",&ava[j]);
work[j]=ava[j];
}
//safety algorithm 
x:
         {
                   getch();
                   printf("in go to x\n");
                   getch();
for(i=0;i<p;i++)
{
                set=0;
for(j=0;j<n;j++)
if(pr[i].req[j]>work[j])
{
set=1;
break;
}
if(set==0&&pr[i].finish==0)
{
   set1=1;                        
 for(j=0;j<n;j++)
 {
  work[j]=work[j]+pr[i].all[j];
  pr[i].finish=1;               
                }}}}                           
 if(set1==1)
 {
  set1=0;
  goto x;          
           }
  else
  {
   for(i=0;i<p;i++)
   if(pr[i].finish==0)
    set2=1;  
}      
if(set2==1)
{
printf("\nNot in safe condition\n ");
return 0;
}
else
printf("\nIn safe condtion\n");             

                  getch();                                                         
      }
