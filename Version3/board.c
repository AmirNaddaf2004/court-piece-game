#include <stdio.h>
#include "functions.h"

void board(int score1, int score2, int symbolP1, int numP1, int symbolP2, int numP2, int symbolP3, int numP3, int symbolP4, int numP4, int situation,char symP1[],int numberP1[])
{
    int numbers[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    char symbols[4] = {'A', 'B', 'C', 'D'};
    int k;
    printf("\t\tp3\n");
    printf("    --------------------------   team 1= %d\n", score1);
    if (situation != 1 && situation != 4)
    {
        printf("    |\t\t%c%2d\t     |\n", symbols[symbolP3], numbers[numP3]);
    }
    else
    {
        printf("    |\t\t\t     |\n");
    }
    printf("    |\t\t\t     |\n");
    printf("    |\t\t\t     |\n");
    if (situation == 0 || situation == 2)
        printf("  p2|%c%2d\t\t  %c%2d|p4\n", symbols[symbolP2], numbers[numP2], symbols[symbolP4], numbers[numP4]);
    else if (situation == 1)
    {
        printf("  p2|\t\t\t     |p4\n");
    }
    else
    {
        printf("  p2|   \t\t  %c%2d|p4\n", symbols[symbolP4], numbers[numP4]);
    }
    printf("    |\t\t\t     |\n");
    printf("    |\t\t\t     |\n");
    if (situation == 0)
    {
        printf("    |\t\t%c%2d\t     |\n", symbols[symbolP1], numbers[numP1]);
    }
    else
    {
        printf("    |\t\t\t     |\n");
    }
    printf("    --------------------------   team 2= %d\n", score2);
    printf("\t\tp1\n");
    if (situation != 0)
    {
        for (k = 0; k < 11; k++)
        {
            printf("|  %c  |", symP1[k]);
        }
        printf("\n");
        for (k = 0; k < 11; k++)
        {
            printf("| %2d  |", numberP1[k]);
        }
        printf("\n   0      1      2      3      4      5      6      7      8      9      10\n");
    }
}