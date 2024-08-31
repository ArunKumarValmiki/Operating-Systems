#include<stdio.h>

#define MAX_PROCESS 5
#define MAX_RESOURCES 3

int main() {
    int process_count, resource_count, count = 0, i, j;
    int allocation[MAX_PROCESS][MAX_RESOURCES], max[MAX_PROCESS][MAX_RESOURCES];
    int need[MAX_PROCESS][MAX_RESOURCES], safe_sequence[MAX_PROCESS];
    int available[MAX_RESOURCES], done[MAX_PROCESS], terminate = 0;

    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &process_count, &resource_count);

    printf("Enter allocation matrix (%dx%d):\n", process_count, resource_count);
    for (i = 0; i < process_count; i++) {
        for (j = 0; j < resource_count; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter maximum resource matrix (%dx%d):\n", process_count, resource_count);
    for (i = 0; i < process_count; i++) {
        for (j = 0; j < resource_count; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter available resources: ");
    for (i = 0; i < resource_count; i++) {
        scanf("%d", &available[i]);
    }

    printf("\nNeed matrix:\n");
    for (i = 0; i < process_count; i++) {
        for (j = 0; j < resource_count; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    // Initialize done array to keep track of completed processes
    for (i = 0; i < process_count; i++) {
        done[i] = 0;
    }

    while (count < process_count) {
        for (i = 0; i < process_count; i++) {
            if (done[i] == 0) {
                for (j = 0; j < resource_count; j++) {
                    if (need[i][j] > available[j]) {
                        break;
                    }
                }
                if (j == resource_count) {
                    safe_sequence[count] = i;
                    done[i] = 1;
                    for (j = 0; j < resource_count; j++) {
                        available[j] += allocation[i][j];
                    }
                    count++;
                    terminate = 0;
                } else {
                    terminate++;
                }
            }
        }
        if (terminate == (process_count - 1)) {
            printf("Safe sequence does not exist\n");
            break;
        }
    }

    if (terminate != (process_count - 1)) {
        printf("\nAvailable resources after completion:\n");
        for (i = 0; i < resource_count; i++) {
            printf("%d\t", available[i]);
        }
        printf("\nSafe sequence:\n");
        for (i = 0; i < process_count; i++) {
            printf("P%d\t", safe_sequence[i]);
        }
    }

    return 0;
}
