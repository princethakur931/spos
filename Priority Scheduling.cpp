#include <stdio.h>
#include <string.h>
typedef struct process {
 char pname[10];
 int burst;
 int priority;
 int wt;
 int rt;
 int tat;
} p1;
int main() {
 p1 p[10];
 float avg_tat = 0;
 float avg_wt = 0;
 float avg_rt = 0;
 int n;
 printf("\n ENTER THE NUMBER OF PROCESS :");
 scanf("%d", &n);
 for (int i = 0; i < n; i++) {
 p[i].pname[0] = 'p';
 p[i].pname[1] = i;
 p[i].pname[2] = '\0';
 printf("\nENTER THE BURST TIME:");
 scanf("%d", &p[i].burst);
 printf("\nENTER THE PRIORITY:");
 scanf("%d", &p[i].priority);
 }
 for (int i = 0; i < n; i++) {
 for (int j = i + 1; j < n; j++) {
 if (p[i].priority > p[j].priority) {
 p1 swap = p[i];
 p[i] = p[j];
 p[j] = swap;
 }
 }
 }
 for (int i = 0; i < n; i++) {
 p[i].wt = avg_rt;
 p[i].rt = p[i].wt;
 p[i].tat = p[i].burst + p[i].wt;
 avg_tat = avg_tat + p[i].tat;
 avg_rt = avg_rt + p[i].burst;
 }
 avg_wt = 0;
 for (int i = 0; i < n; i++) {
 avg_wt = p[i].wt + avg_wt;
 }
 avg_wt = avg_wt / n;
 avg_tat = avg_tat / n;
 printf("\nAVERAGE WAITING TIME:%f", avg_wt);
 printf("\nAVERAGE TURN ARROUND TIME :%f", avg_tat);
 return 0;
}
