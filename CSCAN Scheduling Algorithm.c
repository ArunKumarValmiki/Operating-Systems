#include <stdio.h>

int absoluteValue(int);

void main() {

    int queue[25], n, headposition, i, j, seek = 0, maxrange, difference, temp;
    int queue1[20], queue2[20], temp1 = 0, temp2 = 0;
    float averageSeekTime;

    printf("Enter the maximum range of Disk: ");
    scanf("%d", &maxrange);
    printf("Enter the number of queue requests: ");
    scanf("%d", &n);
    printf("Enter the initial head position: ");
    scanf("%d", &headposition);
    printf("Enter the disk positions to be read (queue): ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &temp);
        if (temp > headposition) {
            queue1[temp1] = temp;
            temp1++;
        } else {
            queue2[temp2] = temp;
            temp2++;
        }
    }

    // Sort queue1 (ascending order)
    for (i = 0; i < temp1 - 1; i++) {
        for (j = i + 1; j < temp1; j++) {
            if (queue1[i] > queue1[j]) {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    }

    // Sort queue2 (descending order)
    for (i = 0; i < temp2 - 1; i++) {
        for (j = i + 1; j < temp2; j++) {
            if (queue2[i] < queue2[j]) {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }
        }
    }

    for (i = 1, j = 0; j < temp1; i++, j++) {
        queue[i] = queue1[j];
    }

    queue[i] = maxrange;  // Move to the end of the disk
    i++;
    queue[i] = 0;  // Move to the start of the disk
    i++;

    for (j = 0; j < temp2; i++, j++) {
        queue[i] = queue2[j];
    }

    queue[0] = headposition; 

    for (j = 0; j < n + 2; j++) {
        difference = absoluteValue(queue[j + 1] - queue[j]);
        seek += difference;
        printf("Disk head moves from position %d to %d with Seek %d\n", queue[j], queue[j + 1], difference);
    }

    averageSeekTime = seek / (float)n;
    printf("Total Seek Time = %d\n", seek);
    printf("Average Seek Time = %f\n", averageSeekTime);
}

int absoluteValue(int x) {
    return (x > 0) ? x : -x;
}
