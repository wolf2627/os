#include<stdio.h>

int main(){
    int n, q, i, j, a[10][4], b[10][4], ct=0;
    float wt, tt;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &q);
    for(i =0; i<n;i++){
        printf("Enter the burst time of %d : ", (i+1));
        scanf("%d", &a[i][1]);
        a[i][0] = i;
        a[i][3] = a[i][1];
    }

    i=0; 
    j=n;

    while(i!=j){
        if(a[i][1]>q){
            a[j][1] = a[i][1] - q;
            a[i][1] = q;
            a[j][0] = a[i][0];
            j++;
        }
        ct+=a[i][1];
        a[i][2] = ct;
        b[a[i][0]][1] = ct;
        b[a[i][0]][0] = ct- a[a[i][0]][3];
        i++;
    }

    printf("Gantt chart\n");
    for(int i=0;i<j;i++){
        printf("P%d\t|", a[i][0]+1);
    }
    printf("\n0\t");
    for(i=0;i<j;i++){
        printf("%d\t", a[i][2]);
    }
    printf("\n");
    wt = 0;
    tt =0;

    for(i=0;i<n;i++){
        tt+=b[i][1];
        wt+=b[i][0];
    }
    printf("The average waiting time is %f\n", (wt/n));
    printf("The average turnaround time is %f\n", (tt/n));

}