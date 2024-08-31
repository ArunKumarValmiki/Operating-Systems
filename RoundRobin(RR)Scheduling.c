#include <stdio.h>

int main() {
    int arrivalTime[20], burstTime[20], waitingTime[20], turnaroundTime[20], remainingTime[20];
    int numProcesses, timeQuantum;
    int i, completedProcesses = 0, totalWaitingTime = 0, totalTurnaroundTime = 0, currentTime = 0;
    float averageWaitingTime = 0.0, averageTurnaroundTime = 0.0;

    printf("Enter the number of processes (maximum 20): ");
    scanf("%d", &numProcesses);

    for (i = 0; i < numProcesses; i++) {
        printf("P[%d] - Enter the Arrival time: ", i + 1);
        scanf("%d", &arrivalTime[i]);
        printf("P[%d] - Enter the Burst time: ", i + 1);
        scanf("%d", &burstTime[i]);
        remainingTime[i] = burstTime[i]; 
    }

    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);

    // Implementing Round Robin scheduling
    while (1) {
        int allProcessesCompleted = 1;

        for (i = 0; i < numProcesses; i++) {
            if (remainingTime[i] > 0) {
                allProcessesCompleted = 0; 

                if (remainingTime[i] > timeQuantum) {
                    currentTime += timeQuantum;
                    remainingTime[i] -= timeQuantum;
                } else {
                    currentTime += remainingTime[i];
                    turnaroundTime[i] = currentTime - arrivalTime[i]; 
                    remainingTime[i] = 0;
                }
            }
        }

        if (allProcessesCompleted)
            break;
    }

    // Calculate waiting time and total times
    for (i = 0; i < numProcesses; i++) {
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    averageWaitingTime = (float) totalWaitingTime / numProcesses;
    averageTurnaroundTime = (float) totalTurnaroundTime / numProcesses;


    printf("\nProcess_no\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for (i = 0; i < numProcesses; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrivalTime[i], burstTime[i], waitingTime[i], turnaroundTime[i]);

    printf("\nAverage Waiting Time: %.2f", averageWaitingTime);
    printf("\nAverage Turnaround Time: %.2f\n", averageTurnaroundTime);

    return 0;
}
