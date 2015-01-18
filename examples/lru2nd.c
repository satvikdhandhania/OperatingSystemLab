#include<stdio.h>
main()
{
      int i,j,k,r[10],str[100],f[10],temp,n,fno,hit=0,fault=0,found,c=0,temp2;
      printf("\nEnter No Of pages in Reference String :");
      scanf("%d",&n);
      printf("No of frames :");
      scanf("%d",&fno);
      printf("Enter The Reference String :");
      for(i=0;i<n;i++)
       scanf("%d",&str[i]);

      for(j=0;j<fno;j++)
      {   
         r[j]=0;
         f[j]=-1;
      }
      for(i=0;i<n;i++)
      {   
         found=0;
         for(j=0;j<c;j++)
         {
            if(str[i]==f[j])
            { 
              hit++;
              found=1;
              r[j]=1;
              temp=f[j];
              temp2=r[j];
              for(k=j;k<c-1;k++)
              {
                f[k]=f[k+1];
                r[k]=r[k+1];             
              }
              f[k]=temp;
              r[k]=temp2;
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
            else if(c==fno)
            {
               for(k=1;k<c;k++)
               {
                     f[k-1]=f[k];
                     r[k-1]=r[k];
               }
               f[k-1]=str[i];     
               r[k-1]=1;
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
