#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct data
{
    int val;
    int freq;
} data;

int getData(data *root)
{
    for (int i = 0; i < 10; i++)
    {
        root[i].freq = 0;
        root[i].val = i;
    }
    char str[256];
    fgets(str, sizeof(str), stdin);
    if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }

    char *token = strtok(str, " ");
    while (token != NULL)
    {
        int num = atoi(token);
        if (num >= 0 && num <= 9)
        {
            root[num].freq++;
        }
        token = strtok(NULL, " ");
    }

    return 1;
}

int displayData(data *root)
{
    printf("n: ");
    for (int i = 0; i < 10; i++)
    {
        if (root[i].freq != 0)
            printf("%d ", root[i].val);
    }
    printf("\nf: ");
    for (int i = 0; i < 10; i++)
    {
        if (root[i].freq != 0)
            printf("%d ", root[i].freq);
    }
    printf("\n");

    return 1;
}

int findMaxFreq(data *root)
{
    int indexMax = 0, freqMax = root[indexMax].freq;
    for (int i = 0; i < 10; i++)
    {
        if (root[i].freq > 0)
        {
            indexMax = i, freqMax = root[i].freq;
            break;
        }
        else if (i == 9)
        {
            return -1;
        }
    }
    for (int i = 1; i < 10; i++)
    {
        if (root[i].freq > freqMax)
        {
            indexMax = i;
            freqMax = root[i].freq;
        }
    }
    return indexMax;
}

int findMinFreq(data *root)
{
    int indexMin = 0, freqMin = root[indexMin].freq;
    for (int i = 0; i < 10; i++)
    {
        if (root[i].freq > 0)
        {
            indexMin = i, freqMin = root[i].freq;
            break;
        }
        else if (i == 9)
        {
            return -1;
        }
    }
    for (int i = 1; i < 10; i++)
    {
        if (root[i].freq < freqMin && root[i].freq > 0)
        {
            indexMin = i;
            freqMin = root[i].freq;
        }
    }

    return indexMin;
}

int main()
{
    data root[10];

    getData(root);

    displayData(root);

    int max = findMaxFreq(root);
    if (max != -1)
        printf("Max = %d\n", max);
    else
        printf("Max = \n");

    int min = findMinFreq(root);
    if (min != -1)
        printf("Min = %d\n", min);
    else
        printf("Min = \n");

    return 0;
}