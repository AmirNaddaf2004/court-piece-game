#include <stdio.h>
#include "functions.h"

void board(int score1, int score2, int symbolP1, int numP1, int symbolP2, int numP2, int symbolP3, int numP3, int symbolP4, int numP4, int situation)
{
    int numbers[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    char symbols[4] = {'A', 'B', 'C', 'D'};
    if (situation == 0)
    {
        printf("\t\tp3\n");
        printf("    --------------------------   team 1= %d\n", score1);
        printf("    |\t\t%c%2d\t     |\n", symbols[symbolP3], numbers[numP3]);
        printf("    |\t\t\t     |\n");
        printf("    |\t\t\t     |\n");
        printf("  p2|%c%2d\t\t  %c%2d|p4\n", symbols[symbolP2], numbers[numP2], symbols[symbolP4], numbers[numP4]);
        printf("    |\t\t\t     |\n");
        printf("    |\t\t\t     |\n");
        printf("    |\t\t%c%2d\t     |\n", symbols[symbolP1], numbers[numP1]);
        printf("    --------------------------   team 2= %d\n", score2);
        printf("\t\tp1\n");
    }
    if (situation == 1)
    {
        printf("\t\tp3\n");
        printf("    -------------------------   team 1= %d\n", score1);
        printf("    |\t\t\t    |\n");
        printf("    |\t\t\t    |\n");
        printf("    |\t\t\t    |\n");
        printf("  p2|\t\t\t    |p4\n");
        printf("    |\t\t\t    |\n");
        printf("    |\t\t\t    |\n");
        printf("    |\t\t\t    |\n");
        printf("    -------------------------   team 2= %d\n", score2);
        printf("\t\tp1\n");
    }
    if (situation == 2)
    {
        printf("\t\tp3\n");
        printf("    --------------------------   team 1= %d\n", score1);
        printf("    |\t\t%c%2d\t     |\n", symbols[symbolP3], numbers[numP3]);
        printf("    |\t\t\t     |\n");
        printf("    |\t\t\t     |\n");
        printf("  p2|%c%2d\t\t  %c%2d|p4\n", symbols[symbolP2], numbers[numP2], symbols[symbolP4], numbers[numP4]);
        printf("    |\t\t\t     |\n");
        printf("    |\t\t\t     |\n");
        printf("    |\t\t\t     |\n");
        printf("    --------------------------   team 2= %d\n", score2);
        printf("\t\tp1\n");
    }
    if (situation == 3)
    {
        printf("\t\tp3\n");
        printf("    --------------------------   team 1= %d\n", score1);
        printf("    |\t\t%c%2d\t     |\n", symbols[symbolP3], numbers[numP3]);
        printf("    |\t\t\t     |\n");
        printf("    |\t\t\t     |\n");
        printf("  p2|   \t\t  %c%2d|p4\n", symbols[symbolP4], numbers[numP4]);
        printf("    |\t\t\t     |\n");
        printf("    |\t\t\t     |\n");
        printf("    |\t\t\t     |\n");
        printf("    --------------------------   team 2= %d\n", score2);
        printf("\t\tp1\n");
    }
    if (situation == 4)
    {
        printf("\t\tp3\n");
        printf("    --------------------------   team 1= %d\n", score1);
        printf("    |\t\t\t     |\n");
        printf("    |\t\t\t     |\n");
        printf("    |\t\t\t     |\n");
        printf("  p2|   \t\t  %c%2d|p4\n", symbols[symbolP4], numbers[numP4]);
        printf("    |\t\t\t     |\n");
        printf("    |\t\t\t     |\n");
        printf("    |\t\t\t     |\n");
        printf("    --------------------------   team 2= %d\n", score2);
        printf("\t\tp1\n");
    }
}