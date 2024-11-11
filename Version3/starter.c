#include <stdio.h>
#include "functions.h"

int starter(int starterCards[4][11], int bakhshname)
{

    int i, j, startVal = 0, symbol = -1, startCard;
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
        startVal = 9;
        for (i = 0; i < 4; i++)
        {
            if (i != bakhshname)
            {
                for (j = 0; j < startVal; j++)
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
    return startCard;
}