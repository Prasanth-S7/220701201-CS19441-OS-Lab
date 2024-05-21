#include <stdio.h>

int main() {
    int n, quantum, i, total = 0, x, counter = 0;
    int wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;
    printf("Enter the total number of processes: ");
    scanf("%d", &n);
    x = n;
    for(i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time of process %d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        temp[i] = bt[i]; // Store burst time in temp array
    }
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    printf("\nProcess ID\tBurst Time\tTurnaround Time\tWaiting Time\n");
    
    for(total = 0, i = 0; x != 0;) {
        if(temp[i] <= quantum && temp[i] > 0) {
            total += temp[i];
            temp[i] = 0;
            counter = 1;
        } else if(temp[i] > 0) {
            temp[i] -= quantum;
            total += quantum;
        }
        if(temp[i] == 0 && counter == 1) {
            x--;
            printf("Process[%d]\t%d\t\t%d\t\t%d\n", i+1, bt[i], total - at[i], total - at[i] - bt[i]);
            wt += total - at[i] - bt[i];
            tat += total - at[i];
            counter = 0;
        }
        if(i == n-1) {
            i = 0;
        } else if(at[i+1] <= total) {
            i++;
        } else {
            i = 0;
        }
    }
    
    avg_wt = wt * 1.0 / n;
    avg_tat = tat * 1.0 / n;
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
    return 0;
}
