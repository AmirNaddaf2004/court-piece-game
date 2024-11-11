#include <stdio.h>
#include "functions.h"

int starter(int p2[4][11], int p3[4][11], int p4[4][11], int situation, int bakhshname)
{
    int starterCards[4][11];
    int i, j, startVal = 0, symbol = -1, startCard;
    if (situation == 2)
    {
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 11; j++)
            {
                starterCards[i][j] = p2[i][j];
            }
        }
    }
    else if (situation == 3)
    {
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 11; j++)
            {
                starterCards[i][j] = p3[i][j];
            }
        }
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 11; j++)
            {
                starterCards[i][j] = p4[i][j];
            }
        }
    }
    for (i = 0; i < 4; i++)
    {
        if (i != bakhshname)
        {
            for (j = 10; j >= startVal; j--)
            {
                if (starterCards[i][j] == 1)
                {
                    startVal = j;
                    symbol = i;
                    break;
                }
            }
        }
    }
    if (symbol == -1)
    {
        symbol = bakhshname;
        for (i = 10; i > -1; i--)
        {
            if (starterCards[symbol][i] == 1)
            {
                startVal = i;
                break;
            }
        }
    }
    starterCards[symbol][startVal] = 0;
    startCard = symbol * 11 + startVal;
    if (situation == 2)
    {
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 11; j++)
            {
                p2[i][j] = starterCards[i][j];
            }
        }
    }
    else if (situation == 3)
    {
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 11; j++)
            {
                p3[i][j] = starterCards[i][j];
            }
        }
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 11; j++)
            {
                p4[i][j] = starterCards[i][j];
            }
        }
    }
    return startCard;
}