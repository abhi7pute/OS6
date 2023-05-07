#include <stdio.h>

int main() {
int m, n;
printf("Enter the number of processes: ");
scanf("%d", &m);
printf("Enter the number of resource types: ");
scanf("%d", &n);
int available[n];
printf("Enter the number of instances available for each resource type:\n");
for (int i = 0; i < n; i++) {
scanf("%d", &available[i]);
}

int allocation[m][n], max[m][n];
printf("Enter the allocation matrix:\n");
for (int i = 0; i < m; i++) {
for (int j = 0; j < n; j++) {
scanf("%d", &allocation[i][j]);
}
}
printf("Enter the maximum requirement matrix:\n");
for (int i = 0; i < m; i++) {
for (int j = 0; j < n; j++) {
scanf("%d", &max[i][j]);
}
}
int need[m][n];
printf("The need matrix is:\n");
for (int i = 0; i < m; i++) {
for (int j = 0; j < n; j++) {
need[i][j] = max[i][j] - allocation[i][j];
printf("%d ", need[i][j]);
}
printf("\n");
}
printf("The available matrix is:\n");
for (int i = 0; i < n; i++) {
printf("%d ", available[i]);
}
printf("\n");
 return 0;
}









#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
int n, head, totalHeadMovements = 0;
printf("Enter the total number of disk blocks: ");
scanf("%d", &n);
int queue[n];
printf("Enter the disk request queue: ");
for (int i = 0; i < n; i++) {
scanf("%d", &queue[i]);
}
printf("Enter the starting head position: ");
scanf("%d", &head);
printf("\nDisk Request Order: \n");
for (int i = 0; i < n; i++) {
printf("%d ", queue[i]);
totalHeadMovements += abs(head - queue[i]);
head = queue[i];
}
printf("\nTotal Head Movements: %d\n", totalHeadMovements);
return 0;
}
