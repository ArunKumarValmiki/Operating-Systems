#include <stdio.h>

int nof, nor, ref[50], frm[50], pf = 0, victim = -1, recent[10] = {0};

void lruvictim() {
    int lrucal[50] = {0};
    for (int i = 0; i < nof; i++)
        lrucal[i] = recent[frm[i]];

    int temp2 = lrucal[0];
    for (int j = 1; j < nof; j++)
        if (temp2 > lrucal[j])
            temp2 = lrucal[j];

    for (int i = 0; i < nof; i++)
        if (ref[temp2] == frm[i])
            victim = i;
}

int main() {
    printf("\n\t\t\tLRU PAGE REPLACEMENT ALGORITHM\n");
    printf("Enter the number of frames: ");
    scanf("%d", &nof);
    printf("Enter the number of reference strings: ");
    scanf("%d", &nor);
    printf("Enter reference strings: ");
    for (int i = 0; i < nor; i++)
        scanf("%d", &ref[i]);

    printf("\n\n\t\t LRU PAGE REPLACEMENT ALGORITHM ");
    printf("\n\tThe given reference strings:\n");
    for (int i = 0; i < nor; i++)
        printf("%4d", ref[i]);

    for (int i = 0; i < nor; i++) {
        int flag = 0;
        printf("\n\tReference No %d ->\t", ref[i]);
        for (int j = 0; j < nof; j++) {
            if (frm[j] == ref[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            pf++;
            if (pf <= nof)
                victim++;
            else
                lruvictim();
            frm[victim] = ref[i];
            for (int j = 0; j < nof; j++)
                printf("%4d", frm[j]);
        }
        recent[ref[i]] = i;
    }
    printf("\n\n\tNo. of page faults: %d\n", pf);
    return 0;
}

