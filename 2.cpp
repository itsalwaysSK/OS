#include <stdio.h>

int main() {
    int n, i;
    int burst_time[20], waiting_time[20], turn_around_time[20];
    int total_waiting_time = 0, total_turn_around_time = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i+1);
        scanf("%d", &burst_time[i]);
    }

    waiting_time[0] = 0;

    for (i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }

    for (i = 0; i < n; i++) {
        turn_around_time[i] = waiting_time[i] + burst_time[i];
        total_waiting_time += waiting_time[i];
        total_turn_around_time += turn_around_time[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turn_around_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turn_around_time / n);

    return 0;
}

