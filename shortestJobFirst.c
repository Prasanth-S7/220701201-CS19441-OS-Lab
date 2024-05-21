#include<stdio.h>
int main(){
    printf("Enter the number of processes : ");
    int n;
    scanf("%d",&n);
    int p[10],at[10],bt[10],ct[10],tat[10],wt[10];
    for(int i =1;i<=n;i++){
        printf("Enter the Process no : %d : ",i);
        scanf("%d",&p[i-1]);
    }
    for(int i =0;i<n;i++){
        printf("Enter the arrival time of Process %d : ",p[i]);
        scanf("%d",&at[i]);
    }
    for(int i =0;i<n;i++){
        printf("Enter the burst time of Process %d : ",p[i]);
        scanf("%d",&bt[i]);
    }
    int temp =0;
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++){
            if(at[j]>at[j+1]){
                temp = at[j+1];
                at[j+1] = at[j];
                at[j] = temp;
                temp = bt[j+1];
                bt[j+1] = bt[j];
                bt[j] = temp;
                temp = p[j+1];
                p[j+1] = p[j];
                p[j] = temp;
            }
        }
    }

    //checking for arrival time collisions and swapping them based on their burst time
    for(int i =0;i<n-1;i++){
        if(at[i]==at[i+1]){
            if(bt[i]>bt[i+1]){
                temp = at[i+1];
                at[i+1] = at[i];
                at[i] = temp;
                temp = bt[i+1];
                bt[i+1] = bt[i];
                bt[i] = temp;
                temp = p[i+1];
                p[i+1] = p[i];
                p[i] = temp;
            }
        }
    }

    ct[0]= at[0]+bt[0];
    float atat=0, awt=0;
    for(int i=1;i<n;i++)
    {  
      //when proess is ideal in between i and i+1
      temp=0;
     if(ct[i-1]<at[i])
     {
        temp=at[i]-ct[i-1];
     }
     ct[i]=ct[i-1]+bt[i]+temp;
    }
    /* calculating tat and wt */
    printf("\np\t A.T\t B.T\t C.T\t TAT\t WT");
    for(int i=0;i<n;i++)
    {
    tat[i]=ct[i]-at[i];
    wt[i]=tat[i]-bt[i];
    atat+=tat[i];
    awt+=wt[i];
    }
    printf("\natat = %f",atat);
    printf("\nawt = %f",awt);
    atat=atat/n;
    awt=awt/n;
    for(int i=0;i<n;i++)
    {
      printf("\nP%d\t %d\t %d\t %d \t %d \t %d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\naverage turnaround time is %f",atat);

    printf("\naverage wating timme is %f",awt);
    return 0;

    //highly inefficient optimizations can be done
}