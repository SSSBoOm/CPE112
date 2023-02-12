#include <stdio.h>
#include <string.h>

int main()
{
    int row = 0, col = 0;
    scanf("%d %d", &row, &col);

    int matrix[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, left = 0, bot = row, right = col, loop = 1, count = 0;
    // printf("\n");
    while (1)
    {
        // printf("\ncount : %d\n",count);
        // count++;
        if (left >= right || top >= bot)
        {
            break;
        }
        else if (loop == 1)
        {
            for (int i = left; i < right; i++)
            {
                printf("%d ", matrix[top][i]);
            }
            // printf("\n");
            loop = 2, top++;
        }
        else if (loop == 2)
        {
            for (int i = top; i < bot; i++)
            {
                printf("%d ", matrix[i][right - 1]);
            }
            // printf("\n");
            loop = 3, right--;
        }
        else if (loop == 3)
        {
            for (int i = right - 1; i >= left; i--)
            {
                printf("%d ", matrix[bot - 1][i]);
            }
            // printf("\n");
            loop = 4, bot--;
        }
        else if (loop == 4)
        {
            for (int i = bot - 1; i >= top; i--)
            {
                printf("%d ", matrix[i][left]);
            }
            // printf("\n");
            loop = 1, left++;
        }
    }
}