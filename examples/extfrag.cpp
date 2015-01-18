#include<stdio.h>
#include<conio.h>
struct alloc
{
  int all,finish;     
       }a[10];
main()
{
      int mem,n,i,flag=0;
  printf("\nEnter the memory size .. ");
  scanf("%d",&mem);
  printf("\nEnter the number of memory to allocate ...   ");
  scanf("%d",&n);
  printf("\nEnter the %d memories to allocate...\n",n);
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i].all);
   a[i].finish=0;               
                  }
   for(i=0;i<n;i++)
   {
   if(mem==0)
   break;
   else
   {
    if(a[i].all<=mem)
    {
      mem-=a[i].all;
      a[i].finish=1;              
                    }   
   }                
                   }
     if(mem==0)
     {
      for(i=0;i<n;i++)
      if(a[i].finish==0)
      {
         flag=1;
         break;               
                        }
       if(flag==1)
       printf("\nNO EXTERNAL FRAGEMENTATION BUT ALL MEMORIES ARE NOT ALLOCATED\n");
       else
       printf("\nNO EXTERNAL FRAGEMENTATION AND ALL MEMORIES ARE ALLOCATED\n");                          
               }
               else
               printf("\nEXTERNAL FRAGEMENTATION OCCURED\n");
               getch();                                
      }
