#include<stdio.h>
int i,j,k,str[100],f[10],n,fno,hit=0,fault=0,found,flag[10],c=0;
void resetflag()
{
      for(j=0;j<fno;j++)
        flag[j]=0;  
}
int checkflag()
{  int i;
  for(i=0;i<fno;i++)
    if(flag[i]==0)
      return 0;
      
  return 1;   
}
int find(int i)
{   int j,k,temp;
    for(j=i;j<n;j++)
    { 
      for(k=0;k<fno;k++)
         if(f[k]==str[j])
          { 
            temp=k;
            flag[k]=1;
            
          }
       if(checkflag())
         return temp;
      }
    for(j=0;j<fno;j++)
      if(flag[j]==0)
          return j;
}
main()
{     int checkflag();
      int find(int);
      void resetflag();
      printf("\nEnter No Of pages in Reference String :");
      scanf("%d",&n);
      printf("No of frames :");
      scanf("%d",&fno);
      printf("Enter The Reference String :");
      for(i=0;i<n;i++)
       scanf("%d",&str[i]);

      for(j=0;j<fno;j++)
      {  flag[j]=0;
         f[j]=-1;
      }
      
      for(i=0;i<n;i++)
      {   
         found=0;
         for(j=0;j<fno;j++)
         {
            if(str[i]==f[j])
            { 
              hit++;
              found=1;
              break;
            }
         }
         if(found==0)        
         {   
            fault++;
            if(c<fno)
            {
              f[c]=str[i];
              c++;       
            }
            else
            {
            resetflag();
            k=find(i);
            f[k]=str[i];
            }
      }
        printf("\n %d Operation :",i);
        for(j=0;j<fno;j++)
          printf(" \t %d",f[j]);
         
      }
printf("\nHits = %d",hit);
printf("\nfaults =%d",fault);
float hr=(float)hit/n;
printf("\nHit Ratio : %f",hr*100.00);
scanf("%d",&fno);
}
