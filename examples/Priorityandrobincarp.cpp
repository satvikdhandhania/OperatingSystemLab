#include<iostream.h>
#include<conio.h>
struct process
{      char name[5];
       int at,bt,tat,rt,wt,sub,comp,prior,in[10],out[10],n;
}p[10],temp;
int n,i,j,q,sum=0;
float avgtat=0.0,avgwt=0.0;
void priority()
{  
   int min,lastmin,flag; 
   //priority scheduling
   lastmin=min=99;
   bool flag1;
   for(j=0;j<=sum;j++)
   {  
     flag=0;
     flag1=true;
     for(i=1;i<=n;i++)
      {   if(p[i].rt!=0)
           {
                        flag1=false;             
           }
         if((p[i].at<=j)&&(p[i].rt!=0))
          {  if(flag==0)
               {  
                  flag=1;
                  min=i;
               }    
             if((p[i].prior<p[min].prior)) 
               {
                  min=i;
               }
          }
      }
      if(flag1==true)
         break;
      if(lastmin!=min)
       {   
         p[min].in[p[min].n]=j;
         p[min].out[p[min].n]=j+1;
         p[min].n++;
       }
     if(lastmin==min)
      { 
         p[min].n--;
         p[min].out[p[min].n]=j+1;
         p[min].n++;
      }
     if(p[min].rt==p[min].bt)
      {   
        p[min].sub=j;
      }
    
     p[min].rt--;
    
     if(p[min].rt==0)
          p[min].comp=j+1;
     lastmin=min;
   }   

   for(i=1;i<=n;i++)
    {  
       p[i].wt=p[i].in[0]-p[i].at;
       p[i].tat=p[i].comp-p[i].at;
       for(j=1;j<p[i].n;j++)
       {
         p[i].wt=p[i].wt+p[i].in[j]-p[i].out[j-1];         
       }
    }   
//display 
     cout<<"\n\t\t\t\tPriority Scheduling  "; 
      for(i=1;i<=n;i++)
     {  
        cout<<"\n\n\nDetails for process "<<i<< " :";
        cout<<"\nProcess Name :";        
        fflush(stdin);
        puts(p[i].name);
        cout<<"Arrival Time :"<<p[i].at;
        cout<<"\nBurst Time :"<<p[i].bt;
        cout<<"\nPriority :"<<p[i].prior;
        cout<<"\nFirst Submission Time :"<<p[i].sub;
        cout<<"\nCompletion Time :"<<p[i].comp;
        cout<<"\n\t\t\t\tGaant Chart !! \n\n\n";
           for(j=0;j<p[i].n;j++)
        {  
           cout<<"\nSwap In "<<j+1<<" :"<<p[i].in[j];
           cout<<"\nSwap Out "<<j+1<<" :"<<p[i].out[j];
        }
        cout<<"\nWaiting Time :"<<p[i].wt;
        cout<<"\nTotal Turnaround Time :"<<p[i].tat;
        avgwt=avgwt+p[i].wt;
        avgtat=avgtat+p[i].tat;
     }                  
     cout<<"\n\n\n Average Waiting Time :"<<avgwt/n;
     cout<<"\n Average Turnaround Time :"<<avgtat/n;
}

void robin()
{    avgtat=avgwt=0.0;
     for(i=1;i<=n;i++)
     {
        p[i].rt=p[i].bt;
        p[i].wt=0;
        p[i].tat=0;     
        for(j=0;j<=p[i].n;j++)            
        {
           p[i].in[j]=0;
           p[i].out[j]=0;                           
        }
        p[i].n=1;
     }
     for(i=1;i<n;i++)
     for(j=1;j<n;j++)
      if(p[j].at>p[j+1].at)
        {
           temp=p[j];
           p[j]=p[j+1];
           p[j+1]=temp;                  
        }
     bool flag=true;
     bool flag1;
       j=0;
       while(flag&&j<=sum)
       { 
           flag1=true;
        for(i=1;i<=n;i++)
        {   
            if(p[i].at>j)
             {
                j++;
                break;
             }
            if(p[i].rt!=0)
             { flag1=false;
               if(p[i].rt<q)
                {    p[i].in[p[i].n]=j;
                     p[i].wt=p[i].wt+j-p[i].out[p[i].n-1]; 
                     j=j+p[i].rt;
                     p[i].rt=0;
                     p[i].out[p[i].n]=j;
                     p[i].n++;
                     p[i].tat=j-p[i].at;;
                     p[i].comp=j;
                }  
                else if(p[i].rt>=q)
                {   p[i].in[p[i].n]=j;         
                    p[i].wt=p[i].wt+j-p[i].out[p[i].n-1]; 
                    j=j+q;
                    p[i].rt-=q;
                    p[i].out[p[i].n]=j;
                    p[i].n++; 
                    p[i].comp=j;
                     p[i].tat=j-p[i].at;
                }
             }      
        }
           if(flag1)
             break;
       }
        
//display 
     cout<<"\n\t\t\t\tRobin Round Scheduling  "; 
      for(i=1;i<=n;i++)
     {  
        cout<<"\n\n\nDetails for process "<<i<< " :";
        cout<<"\nProcess Name :";        
        fflush(stdin);
        puts(p[i].name);
        cout<<"Arrival Time :"<<p[i].at;
        cout<<"\nBurst Time :"<<p[i].bt;
        cout<<"\nCompletion Time :"<<p[i].comp;
        cout<<"\n\t\t\t\tGaant Chart !! \n\n\n";
           for(j=1;j<p[i].n;j++)
        {  
           cout<<"\nSwap In "<<j<<" :"<<p[i].in[j];
           cout<<"\nSwap Out "<<j<<" :"<<p[i].out[j];
        }
        p[i].wt-=p[i].at;
        cout<<"\nWaiting Time :"<<p[i].wt;
        cout<<"\nTotal Turnaround Time :"<<p[i].tat;
        avgwt=avgwt+p[i].wt;
        avgtat=avgtat+p[i].tat;
     }                  
     cout<<"\n\n\n Average Waiting Time :"<<avgwt/n;
     cout<<"\n Average Turnaround Time :"<<avgtat/n;
}
main()
{
     cout<<"\nEnter The No Of processes : ";
     cin>>n;
     for(i=1;i<=n;i++)
     {  cout<<"\nEnter Details for process "<<i<< " :";
        cout<<"\nEnter Process Name :";        
        fflush(stdin);
        gets(p[i].name);
        cout<<"\nEnter Arrival Time :";
        cin>>p[i].at;
        cout<<"\nEnter Burst Time :";
        cin>>p[i].bt;
        p[i].rt=p[i].bt;
        cout<<"\nEnter Priority :";
        cin>>p[i].prior;
        p[i].n=0;
        sum=sum+p[i].bt;
     }
     priority();
     getch();
     system("cls");
     cout<<"\nEnter Time Quantum For Process :";
     cin>>q;
     robin();
     getch();
}
