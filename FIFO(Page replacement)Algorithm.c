#include <stdio.h>

int main() {
    int i, j, nof, nor, flag = 0, pf = 0, victim = -1;
    int ref[50], frm[50];

    printf("\n\t\t\tFIFO PAGE REPLACEMENT ALGORITHM\n");
    printf("Enter the number of frames: ");
    scanf("%d", &nof);
    printf("Enter the number of pages: ");
    scanf("%d", &nor);
    printf("Enter the page numbers:\n");
    for (i = 0; i < nor; i++)
        scanf("%d", &ref[i]);

    printf("\nThe given pages are: ");
    for (i = 0; i < nor; i++)
        printf("%4d", ref[i]);

    for (i = 1; i <= nof; i++)
        frm[i] = -1;

    printf("\n");

    for (i = 0; i < nor; i++) {
        flag = 0;
        printf("\nPage %d ->\t", ref[i]);
        for (j = 0; j < nof; j++) {
            if (frm[j] == ref[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            pf++;
            victim++;
            victim = victim % nof;
            frm[victim] = ref[i];
            for (j = 0; j < nof; j++)
                printf("%4d", frm[j]);
        }
    }

    printf("\n\nNumber of page faults: %d\n", pf);

    return 0;
}
