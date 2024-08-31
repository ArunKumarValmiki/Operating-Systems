#include<stdio.h>
int nof, nor, pf = 0, victim = -1, ref[50], frm[50], count = 0;

void optPageReplacement();
int optVictim(int index);

int main() {
    printf("OPTIMAL PAGE REPLACEMENT ALGORITHM\n");
    printf("Enter the number of frames: ");
    scanf("%d", &nof);
    printf("Enter the number of reference strings: ");
    scanf("%d", &nor);
    printf("Enter the reference strings: ");
    for(int i = 0; i < nor; i++)
        scanf("%d", &ref[i]);
    optPageReplacement();
    printf("\n\nNumber of page faults: %d\n", pf);
    return 0;
}
void optPageReplacement() {
    for(int i = 0; i < nof; i++) frm[i] = -1;
    printf("\n");
    for(int i = 0; i < nor; i++) {
        int flag = 0;
        printf("\nRef no %d ->\t", ref[i]);
        for(int j = 0; j < nof; j++) {
            if(frm[j] == ref[i]) {
                flag = 1; break;
            }
        }
        if(flag == 0) {
            count++;
            if(count <= nof) victim++;
            else victim = optVictim(i);
            pf++; frm[victim] = ref[i];
            for(int j = 0; j < nof; j++) printf("%4d", frm[j]);
        }
    }
}
int optVictim(int index) {
    int farthest = -1, victimIndex = -1;
    for (int i = 0; i < nof; i++) {
        int found = 0;
        for (int j = index + 1; j < nor; j++) {
            if (frm[i] == ref[j]) {
                found = 1;
                if (j > farthest) {
                    farthest = j;
                    victimIndex = i;
                }
                break;
            }
        }
        if (!found) return i;
    }
    if (victimIndex == -1) {
        for (int i = 0; i < nof; i++) {
            if (frm[i] == ref[index]) {
                victimIndex = i;
                break;
            }
        }
    }
    return victimIndex;
}
