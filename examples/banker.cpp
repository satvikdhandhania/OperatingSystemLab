#include<stdio.h>
#include<conio.h>
struct process
{
 int all[5],need[5],max[5];
 int finish;      
       }pr[5];
main()
{
      int set1=0,set3=0,set4=0,req[5],set2=0,n,i,j,k,p,ava[5],work[5],set,recheck=0;
printf("\nEnter the number of types of resources ");
scanf("%d",&n);
printf("\nEnter the total number of processes ");
scanf("%d",&p);
for(i=0;i<p;i++)
{
                pr[i].finish=0;                
printf("\nEnter the allocated and max demand of resources of process p%d",i);
printf("\nAllocated\n");
for(j=0;j<n;j++)
scanf("%d",&pr[i].all[j]);
printf("\nMaximum demand\n");
for(j=0;j<n;j++)
scanf("%d",&pr[i].max[j]);
for(j=0;j<n;j++)
pr[i].need[j]=pr[i].max[j]-pr[i].all[j];                
}
printf("\nEnter the available resources...\n");
for(j=0;j<n;j++)
{
scanf("%d",&ava[j]);
work[j]=ava[j];
}
//safety algorithm 
x:
for(i=0;i<p;i++)
{
                set=0;
for(j=0;j<n;j++)
{
if(pr[i].need[j]>work[j])
set=1;
}
if(set==0&&pr[i].finish==0)
{
   set1=1;                        
 for(j=0;j<n;j++)
 {
  work[j]=work[j]+pr[i].all[j];
  pr[i].finish=1;               
 }
 }}                           
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
if(recheck==1)
{
  getch();
 return 0;                                      
}
printf("\nEnter the process and its request ... ");
scanf("%d",&k);
for(j=0;j<n;j++)
scanf("%d",&req[j]);
//Request algorithm
 for(j=0;j<n;j++)
  if(req[j]>pr[k].need[j])
  set3=1;
  if(set3==0)
  {
             printf("\nReq less than need \n");
  for(j=0;j<n;j++)
  if(req[j]>ava[j])
  set4=1;
  if(set4==0)
  {
  printf("\nREq less than available\n");           
   for(j=0;j<n;j++)          
   {
      ava[j]=ava[j]-req[j];
      pr[k].all[j]+=req[j];
      pr[k].need[j]-=req[j];                       
                             }}}
  //print
  for(i=0;i<p;i++)
  {
  printf("\nPROCESS%d\n",i);
  printf("\nAllocated resources ...\n");
  for(j=0;j<n;j++)
  printf("%d\t",pr[i].all[j]);
   printf("\nNeed resources ...\n");
  for(j=0;j<n;j++)
  printf("%d\t",pr[i].need[j]);                                                                   
                  }
                  recheck=1;
                  goto x;                                                         
      }
