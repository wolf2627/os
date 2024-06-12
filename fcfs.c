#include<stdio.h>

int main(){
    int i, a[10], cnt = 0, n;
    float tt, wt;   
    printf("Enter the total numebr of process: ");
    scanf("%d", &n);
    printf("Enter the burst time: ");
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    printf("Gantt Chart\n");
    for(i=0;i<n;i++){
        printf(" P%d |", (i+1));
    }
    printf("\n");
    for(i=0;i<n;i++){
        cnt +=a[i];
        tt+=cnt;
        printf("%d\t",cnt);
    }
    printf("\n");
    wt = (float)(tt-cnt)/n;
    tt = (float)tt/n;
    printf("Average Waiting time: %0.2f\n", wt);
    printf("Average total time: %0.2f\n", tt);

}