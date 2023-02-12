#include <stdio.h>

int main()
{
    int sizematrix[2];
    int odd = 0, even = 0;
    int matrix[100][100];

    scanf("%d %d", &sizematrix[0], &sizematrix[1]);

    for (int i = 0; i < sizematrix[1]; i++)
    {
        for (int j = 0; j < sizematrix[0]; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < sizematrix[1]; i++)
    {
        for (int j = 0; j < sizematrix[0]; j++)
        {
            if (matrix[i][j] % 2 == 1){
                printf("%d ", matrix[i][j]);
                odd = 1;
            }
        }
    }
    if(!odd)
        printf("None");

    printf("\n");
    for (int i = 0; i < sizematrix[1]; i++)
    {
        for (int j = 0; j < sizematrix[0]; j++)
        {
            if (matrix[i][j] % 2 == 0){

                printf("%d ", matrix[i][j]);
                even = 1;
            }
        }
    }
    if(!even)
        printf("None");

    return 0;
}