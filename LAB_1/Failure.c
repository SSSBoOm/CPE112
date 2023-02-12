#include "stdio.h"

int main() {
    int MARKS[20][5];

    for(int i = 0; i < 20; i++) {
        scanf("%d %d %d %d %d",&MARKS[i][0],&MARKS[i][1],&MARKS[i][2],&MARKS[i][3],&MARKS[i][4]);
    }

    int sum[20] = {0}, count = 0;
    for(int i = 0; i < 20; i++) {
        sum[i] += MARKS[i][0] + MARKS[i][1] + MARKS[i][2] + MARKS[i][3] + MARKS[i][4];
        if((float)sum[i] / 5 < 50) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}