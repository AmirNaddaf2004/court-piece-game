#include <stdio.h>
#include "functions.h"

int judge(int symbolP1, int numP1, int symbolP2, int numP2, int symbolP3, int numP3, int symbolP4, int numP4, int situation, int bakhshname)
{
    int firstSym;
    switch (situation)
    {
    case 1:
        firstSym = symbolP1;
        break;
    case 2:
        firstSym = symbolP2;
        break;
    case 3:
        firstSym = symbolP3;
        break;
    case 4:
        firstSym = symbolP4;
        break;
    default:
        break;
    }
    if (symbolP1 == firstSym && symbolP2 == firstSym && symbolP3 == firstSym && symbolP4 == firstSym) /*checking if all players played the same symbol*/
    {
        if (numP1 > numP2 && numP1 > numP3 && numP1 > numP4) /*comparing and finding the result*/
            return 1;
        else if (numP2 > numP1 && numP2 > numP3 && numP2 > numP4)
            return 2;
        else if (numP3 > numP1 && numP3 > numP2 && numP3 > numP4)
            return 3;
        else
            return 4;
    }
    else if (symbolP1 == bakhshname || symbolP2 == bakhshname || symbolP3 == bakhshname || symbolP4 == bakhshname) /*checking if someone played bakhshname*/
    {
        if (symbolP1 != bakhshname)
            numP1 = 0;
        if (symbolP2 != bakhshname)
            numP2 = 0;
        if (symbolP3 != bakhshname)
            numP3 = 0;
        if (symbolP4 != bakhshname)
            numP4 = 0;
        if (numP1 > numP2 && numP1 > numP3 && numP1 > numP4) /*comparing and finding the result*/
            return 1;
        else if (numP2 > numP1 && numP2 > numP3 && numP2 > numP4)
            return 2;
        else if (numP3 > numP1 && numP3 > numP2 && numP3 > numP4)
            return 3;
        else
            return 4;
    }
    else /*if the symbols aren't the same and none of them is bakhshname*/
    {
        if (symbolP1 != firstSym)
            numP1 = 0;
        if (symbolP2 != firstSym)
            numP2 = 0;
        if (symbolP3 != firstSym)
            numP3 = 0;
        if (symbolP4 != firstSym)
            numP4 = 0;
        if (numP1 > numP2 && numP1 > numP3 && numP1 > numP4) /*comparing and finding the result*/
            return 1;
        else if (numP2 > numP1 && numP2 > numP3 && numP2 > numP4)
            return 2;
        else if (numP3 > numP1 && numP3 > numP2 && numP3 > numP4)
            return 3;
        else
            return 4;
    }
}