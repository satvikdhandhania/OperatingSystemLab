#include<stdio.h>
#include<conio.h>
struct alloc
{
       int all,finish,block;
       }a[10];
main()
{
 int arr[10],offset,tem[10],diff,temp,i,n,j,nd;
 printf("\nEnter the number of memory spaces... ");
 scanf("%d",&n);
 printf("\nEnter the memory spaces \n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&arr[i]);
  tem[i]=arr[i];               
                 }
  printf("\nEnter the number of memory to allocate.. ");
  scanf("%d",&nd);
  printf("\nEnter the memories to allocate... ");
  for(i=0;i<nd;i++)
  {
       a[i].finish=0;            
    scanf("%d",&a[i].all);               
                   }
 for(i=0;i<nd;i++)
 {
  offset=-1; 
  diff=-1;               
  for(j=0;j<n;j++)
  {
   if(a[i].all<=tem[j])
   {
     temp=tem[j]-a[i].all;
    if(temp>diff)
    {
    diff=temp;
    offset=j; 
}              
                 }               
                  } 
    if(offset>=0)
    {
     tem[offset]-=a[i].all;
     a[i].block=offset;
     a[i].finish=1;           
                 }                             
                  }                  
 for(i=0;i<nd;i++)
 {
  if(a[i].finish==0)
   printf("\nMemory= %d not allocated",a[i].all);
   else
   {
    printf("\nMemory= %d allocated to block= %d",a[i].all,a[i].block);   
   }                                  
                  } 
                  getch();                                     
      }
