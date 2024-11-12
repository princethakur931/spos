#include <stdio.h>
#include <string.h>

typedef struct process {
    char pname[10];
    int burst, at, wt, ct, tat;
} p1;

int main() {
    p1 p[10];
    float avg_tat = 0;
    float avg_wt = 0;
    int n, i, j;
    p1 swap;

    printf("\nEnter The Number of Processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i].pname[0] = 'P';
        p[i].pname[1] = i + '0';
        p[i].pname[2] = '\0';

        printf("\nEnter The Burst Time for Process %s: ", p[i].pname);
        scanf("%d", &p[i].burst);

        printf("Enter The Arrival Time for Process %s: ", p[i].pname);
        scanf("%d", &p[i].at);
    }

   
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                swap = p[i];
                p[i] = p[j];
                p[j] = swap;
            }
        }
    }

    int time = 0;
    for (i = 0; i < n; i++) {
        if (time < p[i].at) {
            time = p[i].at; 
        }
        time += p[i].burst;
        p[i].ct = time;                    
        p[i].tat = p[i].ct - p[i].at;      
        p[i].wt = p[i].tat - p[i].burst;   

        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnAround\tWaiting\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i].pname, p[i].at, p[i].burst, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turn Around Time: %.2f", avg_tat);

    return 0;
}

