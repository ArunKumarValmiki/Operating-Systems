#include <stdio.h>

int main() {
    int i, j, numProcesses, processID[20], priority[20], burstTime[20], arrivalTime[20];
    int waitingTime[20], turnaroundTime[20];
    int totalWaitingTime = 0, totalTurnaroundTime = 0, temp;
    float averageWaitingTime, averageTurnaroundTime;

    printf("Enter the number of processes (maximum 20): ");
    scanf("%d", &numProcesses);

    for(i = 0; i < numProcesses; i++) {
        printf("P[%d] - Enter the Burst time: ", i + 1);
        scanf("%d", &burstTime[i]);
        printf("P[%d] - Enter the Priority: ", i + 1);
        scanf("%d", &priority[i]);
        printf("P[%d] - Enter the Arrival time: ", i + 1);
        scanf("%d", &arrivalTime[i]);
        processID[i] = i + 1;
    }


    for(i = 0; i < numProcesses - 1; i++) {
        for(j = 0; j < numProcesses - i - 1; j++) {
            if(arrivalTime[j] > arrivalTime[j + 1] || 
               (arrivalTime[j] == arrivalTime[j + 1] && priority[j] > priority[j + 1])) {

                // Swap priorities
                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                // Swap burst times
                temp = burstTime[j];
                burstTime[j] = burstTime[j + 1];
                burstTime[j + 1] = temp;

                // Swap arrival times
                temp = arrivalTime[j];
                arrivalTime[j] = arrivalTime[j + 1];
                arrivalTime[j + 1] = temp;

                // Swap process IDs
                temp = processID[j];
                processID[j] = processID[j + 1];
                processID[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time for each process
    for(i = 0; i < numProcesses; i++) {
        if(i == 0) {
            waitingTime[i] = 0; 
        } else {
            waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1] - arrivalTime[i] + arrivalTime[i - 1];
        }
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    // Calculate average waiting time and turnaround time
    averageWaitingTime = (float) totalWaitingTime / numProcesses;
    averageTurnaroundTime = (float) totalTurnaroundTime / numProcesses;

    printf("\nJob\tBurst Time\tWaiting Time\tTurnaround Time\tPriority\n");
    for(i = 0; i < numProcesses; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processID[i], burstTime[i], waitingTime[i], turnaroundTime[i], priority[i]);
    }

    printf("Average Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);

    return 0;
}
