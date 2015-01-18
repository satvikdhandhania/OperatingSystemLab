#include<stdio.h>
#include<conio.h>
struct alloc
{
  int all,finish,block;     
       }al[10];
       struct memspace
       {
        int mem,flag,left;      
              }m[10];
main()
{
 int n,i,j,nd,mark=0,offset,diff,temp;
 printf("\nEnter the number of  memory spaces...  ");
 scanf("%d",&n);
 printf("\nEnter the %d memory spaces...\n",n);
 for(i=0;i<n;i++)
 {
 scanf("%d",&m[i].mem);
 m[i].flag=0;
}
 printf("\nEnter the number of memories to allocate.. ");
 scanf("%d",&nd);
 printf("\nEnter the %d memories to allocate..\n",nd);
 for(i=0;i<nd;i++)
 {
  scanf("%d",&al[i].all);
  al[i].finish=0;                
                  }
  for(i=0;i<nd;i++)
 {
  offset=-1; 
  diff=1000;               
  for(j=0;j<n;j++)
  {
   if(al[i].all<=m[j].mem&&m[j].flag==0)
   {
     temp=m[j].mem-al[i].all;
    if(temp<diff)
    {
    diff=temp;
    offset=j; 
}              
                 }               
                  } 
    if(offset>=0)
    {
     m[offset].left=m[offset].mem-al[i].all;
     al[i].block=offset;
     al[i].finish=1;
     m[offset].flag=1;           
                 }                             
                  } 
  for(i=0;i<n;i++)
  if(m[i].left!=0)
  {
     mark=1;
     break;             
                  }
 if(mark==1)
 printf("\nINTERNAL FRAGEMENTATION OCCUR\n");
 else
 printf("\nNO INTERNAL FRAGEMENTATION\n");
 getch();                                 
      }
