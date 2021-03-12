// Round Robin Algorithm implementation

#include<bits/stdc++.h>
using namespace std;

void findWaitTime(int p, int proc[], int burst[], int quant, int wait[]) {

    // remaining burst time array
    int rem_burst[p];
    for(int i=0;i<p;i++) rem_burst[i] = burst[i];
    
    int curr_time = 0;
    
    // traversing the array in round robin manner
    while(1) {
        
        bool all_done = true;
        
        for(int i=0;i<p;i++) {
            
             
            if(rem_burst[i]>0) {
                
                all_done = false;
                
                // if the burst time for the ith process is more than quantum, then    
                if(rem_burst[i] > quant) {
                    
                    // the process consumes one quantum 
                    // so the current time increases
                    curr_time += quant;
                    
                    // burst time decreases by one quantum
                    rem_burst[i] -= quant;
                }
                
                // if the burst time for the ith process is less than quantum,
                else {
                    
                    // the process consumes some time (< 1 quantum)
                    curr_time = curr_time + rem_burst[i];
                    
                    // waiting time decreases
                    wait[i] = curr_time - burst[i];
                    
                    rem_burst[i] = 0;
                    
                }
                
            }
            

        }
        
        if(all_done == true) break;
       
    }
}

void findTurnAroundTime(int p, int proc[], int burst[], int wait[], int tat[]) {
    
    for(int i=0;i<p;i++) tat[i] = burst[i] + wait[i];
}



void RoundRobinAlgo(int p, int proc[], int burst[], int quantum) {
    
    int wt[p], tat[p], total_wt=0, total_tat=0;
    
    // function to find waiting time for all processes
    findWaitTime(p, proc, burst, quantum, wt);
    
    // function to find turn around time
    findTurnAroundTime(p, proc, burst, wt, tat);
    
    
    cout<<"Process \t Burst Time \t Wait Time \t Turn Around Time\n";
 
    for(int i=0;i<p;i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout<<i+1<<" \t\t\t"<<burst[i]<<" \t\t\t"<<wt[i]<<" \t\t\t"<<tat[i]<<"\n";
    }
    
    cout<<"Average waiting time : "<<(float)total_wt/(float)p<<"\n";
    cout<<"Total Turn Around time : "<<(float)total_tat/(float)p<<"\n";
}



int main()
{
    int p;
    cin>>p;
    
    int proc[p], burst[p];
    
    for(int i=0;i<p;i++) cin>>proc[i];
    for(int i=0;i<p;i++) cin>>burst[i];
    
    int quantum;
    cin>>quantum;
    
    RoundRobinAlgo(p, proc, burst, quantum);
    
    return 0;
}
