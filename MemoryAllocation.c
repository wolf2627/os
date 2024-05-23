#include <stdio.h>
#include <stdlib.h>

int ps[20], ms[20], bs[20], ws[20];
int p, m, j, i, temp, mm, mm1 = 0, b[20], w[20];

void firstfit(int *ps, int *ms, int p, int m) {
    printf("\nPROCESS\t MEMORYBLOCK\tREMAINING MEMORY\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < m; j++) {
            if (ps[i] <= ms[j]) {
                printf("\n%d(%dk)\t\t%d(%dk)\t%d", i + 1, ps[i], j + 1, ms[j], ms[j] - ps[i]);
                ms[j] = 0;
                break;
            }
        }
    }
}

void bestfit(int *ps, int *bs, int *b, int p, int m) {
    printf("\nPROCESS\t MEMORYBLOCK\tREMAINING MEMORY\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < m; j++) {
            if (ps[i] <= bs[j]) {
                printf("\n%d(%dk)\t\t%d(%dk)\t%d", i + 1, ps[i], b[j] + 1, bs[j], bs[j] - ps[i]);
                bs[j] = 0;
                break;
            }
        }
    }
}

void worstfit(int *ps, int *ws, int *w, int p, int m) {
    printf("\nPROCESS\t MEMORYBLOCK\tREMAINING MEMORY\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < m; j++) {
            if (ps[i] <= ws[j]) {
                printf("\n%d(%dk)\t\t%d(%dk)\t%d", i + 1, ps[i], w[j] + 1, ws[j], ws[j] - ps[i]);
                ws[j] = 0;
                break;
            }
        }
    }
}

void main() {
    int choice, b[20], w[20];
    for (i = 0; i < 20; i++) {
        bs[i] = 0;
        ws[i] = 0;
    }

    printf("\nENTER THE SIZE OF MEMORY: ");
    scanf("%d", &mm);

    printf("\nENTER THE NO. OF MEMORY BLOCKS: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        printf("\nMEMORY BLOCK %d: ", i + 1);
        scanf("%d", &ms[i]);
        mm1 = ms[i] + mm1;
        if (mm < mm1) {
            printf("\nINSUFFICIENT MEMORY");
            printf("\n\nNO. OF BLOCKS :%d", i++);
            m = i;
            break;
        }
        bs[i] = ms[i];
        ws[i] = bs[i];
    }

    printf("\n\nENTER THE NO. OF PROCESSES: ");
    scanf("%d", &p);

    printf("\nENTER THE PROCESS SIZE\n");
    for (i = 0; i < p; i++) {
        printf("\nPROCESS %d: ", i + 1);
        scanf("%d", &ps[i]);
    }

    for (i = 0; i < m; i++) {
        for (j = i + 1; j < m; j++) {
            if (bs[i] > bs[j]) {
                temp = bs[i];
                bs[i] = bs[j];
                bs[j] = temp;
            }
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            if (bs[i] == ms[j])
                b[i] = j;
        }
    }

    for (i = 0; i < m; i++) {
        for (j = i + 1; j < m; j++) {
            if (ws[i] < ws[j]) {
                temp = ws[i];
                ws[i] = ws[j];
                ws[j] = temp;
            }
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            if (ws[i] == ms[j])
                w[i] = j;
        }
    }

    do {
        printf("\n\nENTER YOUR CHOICE\n1. First Fit\n2. Best Fit\n3. Worst Fit\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                firstfit(ps, ms, p, m);
                break;
            case 2:
                bestfit(ps, bs, b, p, m);
                break;
            case 3:
                worstfit(ps, ws, w, p, m);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice <= 3);
}
