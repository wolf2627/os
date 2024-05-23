#include <stdio.h>
#include <stdlib.h>

int p, r, avail[10], j, k, i, a[10], max[10][10], m, alloc[10][10], need[10][10], top, buf, z;

void get() {
    printf("Enter the number of processes: ");
    scanf("%d", &p);
    printf("Enter the number of resource types: ");
    scanf("%d", &r);

    for (j = 0; j < r; j++) {
        printf("Number of resources for type %d: ", j + 1);
        scanf("%d", &avail[j]);
    }

    for (i = 0; i < p; i++) {
        printf("Maximum number of resources for process %d:\n", i + 1);
        for (j = 0; j < r; j++) {
            printf("For resource type %d: ", j + 1);
            scanf("%d", &max[i][j]);
        }
    }

    printf("Allocated instances:\n");
    for (i = 0; i < p; i++) {
        printf("Process %d:\n", i + 1);
        for (j = 0; j < r; j++) {
            printf("Resource type %d: ", j + 1);
            scanf("%d", &m);
            if (m <= avail[j]) {
                alloc[i][j] = m;
                avail[j] -= m;
            } else {
                printf("Allocation exceeds available resources.\n");
                alloc[i][j] = 0; // Set allocation to 0 for safety
            }
        }
    }
}

void disp1() {
    printf("Resources needed by processes:\n");
    for (i = 0; i < p; i++) {
        printf("Process %d: ", i + 1);
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

void seqnc() {
    int finish[10] = {0}; // Track finished processes
    top = 0;
    int found;

    while (top < p) {
        found = 0;
        for (i = 0; i < p; i++) {
            if (!finish[i]) {
                buf = 1;
                for (j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) {
                        buf = 0;
                        break;
                    }
                }
                if (buf) {
                    for (k = 0; k < r; k++) {
                        avail[k] += alloc[i][k];
                    }
                    a[top++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("The system is in an unsafe state.\n");
            exit(1);
        }
    }
}

void disp2() {
    printf("\nSequence of allocation process: ");
    for (i = 0; i < top; i++) {
        printf("%d ", a[i] + 1);
    }
    printf("\n");
}

int main() {
    get();
    disp1();
    seqnc();
    disp2();
    return 0;
}
