#include<stdio.h>
#include<conio.h>
main()
{
      int i,j,str[100],f[10],r[10],n,fno,hit=0,fault=0,pos=0,found;
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
        for(j=0;j<fno;j++)
         if(str[i]==f[j])
           {
               r[j]=1;
               found =1;
           }
        if(found)
         {
            hit++;
         }
        else
        {
          fault++;
          lb:
          if(r[pos]==0)
          {
            r[pos]=1;
            f[pos]=str[i];
            pos++;
            pos%=fno;
          }
          else
          {
            r[pos]=0;
            pos++;
            pos%=fno;
            goto lb;
          }
        }

        printf("\n\n\n %d Operation ",i+1);
        for(j=0;j<fno;j++)
                printf(" \t%d",f[j]);
        printf("\n Second Chance ");
        for(j=0;j<fno;j++)
                printf(" %d\t",r[j]);
      }
printf("\nHits = %d",hit);
printf("\nfaults =%d",fault);
float hr=(float)hit/n;
printf("\nHit Ratio : %f",hr*100);
getch();
}
