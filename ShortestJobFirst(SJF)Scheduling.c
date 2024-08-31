#include <stdio.h>

void calculateWaitingTime(int arrivalTime[], int n, int burstTime[], int waitingTime[]) {
    int completionTime[n], remainingTime[n];

    for (int i = 0; i < n; i++) {
        remainingTime[i] = burstTime[i];
    }

    int currentTime = 0;
    while (1) {
        int selectedProcess = -1;

        for (int i = 0; i < n; i++) {
            if (currentTime >= arrivalTime[i] && remainingTime[i] > 0) {
                if (selectedProcess == -1 || remainingTime[i] < remainingTime[selectedProcess]) {
                    selectedProcess = i;
                }
            }
        }

        if (selectedProcess == -1) {
            break;
        }

        currentTime += burstTime[selectedProcess];
        completionTime[selectedProcess] = currentTime;
        remainingTime[selectedProcess] = 0;
    }

    for (int i = 0; i < n; i++) {
        waitingTime[i] = completionTime[i] - burstTime[i] - arrivalTime[i];
    }
}

void calculateTurnAroundTime(int arrivalTime[], int n, int burstTime[], int waitingTime[], int turnAroundTime[]) {
    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
    }
}


void calculateAverageTimes(int arrivalTime[], int n, int burstTime[]) {
    int waitingTime[n], turnAroundTime[n];

    calculateWaitingTime(arrivalTime, n, burstTime, waitingTime);
    calculateTurnAroundTime(arrivalTime, n, burstTime, waitingTime, turnAroundTime);

    float totalWaitingTime = 0, totalTurnAroundTime = 0;

    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }

    float averageWaitingTime = totalWaitingTime / n;
    float averageTurnAroundTime = totalTurnAroundTime / n;

    printf("Average Waiting Time: %f\n", averageWaitingTime);
    printf("Average Turn Around Time: %f\n", averageTurnAroundTime);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrivalTime[n], burstTime[n];

    // Input arrival and burst time for each process
    printf("Enter arrival and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("  Arrival Time: ");
        scanf("%d", &arrivalTime[i]);
        printf("  Burst Time: ");
        scanf("%d", &burstTime[i]);
    }

    // Calculate and display the average waiting and turn around times
    calculateAverageTimes(arrivalTime, n, burstTime);

    return 0;
}
