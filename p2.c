#include<stdio.h> 
int main() 
{ 
  int i,n,time,remain,flag=0,time_quantum=2;                          // Given in question that context switching
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];            // is done after 2 seconds.
  printf("Enter the number of process: ");
  scanf("%d",&n);
  remain=n;
  for(i=0;i<n;i++) 
  { 
    printf("\nEnter Arrival Time for Process P%d: ",i+1); 
    scanf("%d",&at[i]);  
  } 
  for(i=0;i<n;i++)
  {
	printf("\nEnter Burst Time for Process P%d: ",i+1);
	scanf("%d",&bt[i]); 
    rt[i]=bt[i];
  }
  printf("\n\n");
  printf("\nProcess\t\tTurnaround Time\t\tWaiting Time"); 
  for(time=0,i=0;remain!=0;) 
  { 
    if(rt[i]<=time_quantum && rt[i]>0) 
    { 
      time+=rt[i]; 
      rt[i]=0; 
      flag=1; 
    } 
    else if(rt[i]>0) 
    { 
      rt[i]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[i]==0 && flag==1) 
    { 
      remain--; 
      printf("\nP%d\t\t\t%d\t\t\t%d",i+1,time-at[i],time-at[i]-bt[i]); 
      wait_time+=time-at[i]-bt[i]; 
      turnaround_time+=time-at[i]; 
       flag=0; 
    } 
    if(i==n-1) 
     i=0; 
    else if(at[i+1]<=time) 
      i++; 
    else 
      i=0; 
  }
  printf("\n\n\n\n\n");
  return 0; 
}
