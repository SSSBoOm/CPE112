#include "stdio.h"

void round_down(float num)
{
    char str[64];

    sprintf(str, "%.2f", num);

    for (int i = 0; 1 ; i++)
    {
        if (str[i] == '.')
        {
            if (str[i + 1] == '0' && str[i + 2] == '0')
            {
                printf("\n");
            }
            else if (str[i + 1] != '0' && str[i + 2] == '0')
            {
                printf(".%c\n", str[i + 1]);
            }
            else
            {
                printf(".%c%c\n", str[i + 1], str[i + 2]);
            }
            break;
        }
        else
        {
            printf("%c", str[i]);
        }
    }
}

int main() {
    int MARKS[20][5];

    for(int i = 0; i < 20; i++) {
        scanf("%d %d %d %d %d",&MARKS[i][0],&MARKS[i][1],&MARKS[i][2],&MARKS[i][3],&MARKS[i][4]);
    }

    int sum[20] = {0};
    for(int i = 0; i < 20; i++) {
        sum[i] += MARKS[i][0] + MARKS[i][1] + MARKS[i][2] + MARKS[i][3] + MARKS[i][4];
    }

    for(int i = 0; i < 20; i++) {
        round_down((float)sum[i] / 5);
    }

    return 0;
}