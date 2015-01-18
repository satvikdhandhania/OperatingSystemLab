#include<iostream>
#include<conio.h>
using namespace std;
struct proc
{
       int process,bt,at,wt,tat,psub,pcom;
}p[50],temp,s_bt[50],s_at[50],sjf[50];
main()
{
      int gant[50],i,j,min,n;
      cout<<"No. of processes : ";
      cin>>n;
      for(i=1;i<=n;i++)
      {
              cout<<"\nProcess number : ";
              cin>>p[i].process;
              cout<<"Burst Time : ";
              cin>>p[i].bt;
              cout<<"Arrival Time : ";
              cin>>p[i].at;
      }
      //fcfs
      for(i=1;i<n;i++)
      {
              min=i;
              for(j=i+1;j<=n;j++)
              {
                                if(p[j].at<p[min].at)
                                {
                                                     min=j;
                                }
              }
              temp=p[i];
              p[i]=p[min];
              p[min]=temp;
      }
      //Array sorted on basis of arrival times
      int st,begin;
      st=p[1].at;
      begin=st;
      for(i=1;i<=n;i++)
      {
                       if(p[i].at<=st)
                       {
                                      p[i].psub=st;
                                      p[i].pcom=st+p[i].bt;
                                      p[i].wt=p[i].psub-p[i].at;
                                      p[i].tat=p[i].pcom-p[i].at;
                                      st=p[i].pcom;
                       }
                       else if(p[i].at>st)
                       {
                            p[i].psub=p[i].at;
                            p[i].pcom=p[i].psub+p[i].bt;
                            p[i].wt=0;
                            p[i].tat=p[i].bt;
                            st=p[i].pcom;
                       }
      }  
      float avg_tat,avg_wt;
      for(i=1;i<=n;i++)
      {
                       avg_tat=p[i].tat+avg_tat;
                       avg_wt=p[i].wt+avg_wt;
      }
      if(n!=0)
      {
      avg_tat=avg_tat/n;
      avg_wt=avg_wt/n;
      } 
      cout<<"\n\n\t\t\t::FCFS::";       
      for(i=1;i<=n;i++)
      {
                       cout<<"\n\nProcess : "<<p[i].process;
                       cout<<"\nSubmission time : "<<p[i].psub;
                       cout<<"\nCompletion time : "<<p[i].pcom;
                       cout<<"\nWaiting time : "<<p[i].wt;
                       cout<<"\nTurnaround time : "<<p[i].tat;
      }
      if(n!=0)
      {
      cout<<"\n\n\nAverage turnaround time = "<<avg_tat;    
      cout<<"\nAverage waiting time = "<<avg_wt;
      }
      //sjf
      int exec[50];
      for(i=0;i<50;i++)
      exec[i]=0;
      int h,flag,k;
      for(i=1;i<=n;i++)
      {
                       s_at[i]=p[i];
                       s_bt[i]=s_at[i];
      }
      for(i=1;i<n;i++)
      {
                       min=i;
                       for(j=i+1;j<=n;j++)
                       {
                                          if(s_bt[j].bt<s_bt[min].bt)
                                          min=j;
                       }
                       temp=s_bt[i];
                       s_bt[i]=s_bt[min];
                       s_bt[min]=temp;
      }
      h=s_at[1].at;
      for(i=1;i<=n;i++)
      {
                       flag=0;
                       for(j=1;j<=n;j++)
                       {
                                        if(exec[s_bt[j].process]==0&&s_bt[j].at<=h)
                                        {
                                                                       sjf[i]=s_bt[j];
                                                                       sjf[i].psub=h;
                                                                       sjf[i].pcom=sjf[i].psub+sjf[i].bt;
                                                                       sjf[i].wt=h-sjf[i].at;
                                                                       sjf[i].tat=sjf[i].pcom-sjf[i].at;
                                                                       exec[sjf[i].process]=1;
                                                                       h=sjf[i].pcom;
                                                                       flag=1;
                                                                       break;
                                        }  
                       }
                       if(flag==0)
                       {
                                  for(k=1;k<=n;k++)
                                  {
                                                   if(s_at[k].at>h)
                                                   {
                                                                sjf[i]=s_at[k];
                                                                sjf[i].psub=sjf[i].at;
                                                                sjf[i].pcom=sjf[i].at+sjf[i].bt;
                                                                sjf[i].wt=0;
                                                                sjf[i].tat=sjf[i].pcom-sjf[i].at;
                                                                exec[sjf[i].process]=1;
                                                                h=sjf[i].pcom;
                                                                break;
                                                   }
                                  }
                       }
      }
      cout<<"\n\n\t\t\t::SJF::";       
      for(i=1;i<=n;i++)
      {
                       cout<<"\n\nProcess : "<<sjf[i].process;
                       cout<<"\nSubmission time : "<<sjf[i].psub;
                       cout<<"\nCompletion time : "<<sjf[i].pcom;
                       cout<<"\nWaiting time : "<<sjf[i].wt;
                       cout<<"\nTurnaround time : "<<sjf[i].tat;
      } 
      for(i=1;i<=n;i++)
      {
                       avg_tat=sjf[i].tat+avg_tat;
                       avg_wt=sjf[i].wt+avg_wt;
      }
      if(n!=0)
      {
      avg_tat=avg_tat/n;
      avg_wt=avg_wt/n;
      } 
      if(n!=0)
      {
      cout<<"\n\n\nAverage turnaround time = "<<avg_tat;    
      cout<<"\nAverage waiting time = "<<avg_wt;
      }                                                
      getch();
}                                                                                                     
