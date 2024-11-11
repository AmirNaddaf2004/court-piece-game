#include <stdio.h>
#include "functions.h"

int playbot(int playerCard[4][11], int bakhshname, int result, int team, int symbol)
{
    int flag, numCompare, symCompare;
    int num, playerSym;
    int i, j;
    if (result == team)
    {
        for (i = 0; i < 11; i++)
        {
            flag = 1;
            if (playerCard[symbol][i] == 1)
            {
                playerCard[symbol][i] = 0;
                playerSym = symbol;
                num = i;
                flag = 0;
                break;
            }
        }
        numCompare = 11;
        if (flag)
        {
            for (i = 0; i < 4; i++)
            {
                if (i != bakhshname)
                {
                    for (j = 0; j < numCompare; j++)
                    {
                        if (playerCard[i][j] == 1)
                        {
                            numCompare = j;
                            symCompare = i;
                            flag = 0;
                            break;
                        }
                    }
                }
            }
            playerCard[symCompare][numCompare] = 0;
            playerSym = symCompare;
            num = numCompare;
        }
        if (flag)
        {
            for (i = 0; i < 11; i++)
            {
                flag = 1;
                if (playerCard[bakhshname][i] == 1)
                {
                    playerCard[bakhshname][i] = 0;
                    playerSym = bakhshname;
                    num = i;
                    break;
                }
            }
        }
    }
    else
    {
        for (i = 10; i >= 0; i--)
        {
            flag = 1;
            if (playerCard[symbol][i] == 1)
            {
                playerCard[symbol][i] = 0;
                playerSym = symbol;
                num = i;
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            for (i = 10; i >= 0; i--)
            {
                flag = 1;
                if (playerCard[bakhshname][i] == 1)
                {
                    playerCard[bakhshname][i] = 0;
                    playerSym = bakhshname;
                    num = i;
                    flag = 0;
                    break;
                }
            }
        }
        numCompare = 11;
        if (flag)
        {
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < numCompare; j++)
                {
                    if (playerCard[i][j] == 1)
                    {
                        numCompare = j;
                        symCompare = i;
                        break;
                    }
                }
            }
            playerCard[symCompare][numCompare] = 0;
            playerSym = symCompare;
            num = numCompare;
        }
    }
    return playerSym * 11 + num;
}