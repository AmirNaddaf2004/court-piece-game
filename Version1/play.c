#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#define TRUE 1

int play(int shuffledCards[])
{
    int cards[4][11] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}};
    int p1[4][11] = {0};
    int p2[4][11] = {0};
    int p3[4][11] = {0};
    int p4[4][11] = {0};
    int score1 = 0, score2 = 0;
    char symP1[11];
    int numberP1[11], numP1 = -1, numP2 = -1, numP3 = -1, numP4 = -1;
    int symbolP1 = -1, symbolP2 = -1, symbolP3 = -1, symbolP4 = -1;
    int bakhshname = -1;
    int situation = 1, symCompare, numCompare = 11;
    int playedCard;
    char playedSymbol[4] = {'A', 'B', 'C', 'D'};
    int symbol;
    int flag = 1;
    int result, startCard;
    int i, j, k = 0, z = 1;
    board(score1, score2, symbolP1, numP1, symbolP2, numP2, symbolP3, numP3, symbolP4, numP4, situation);

    for (j = 1; j <= 44; j++)
    {
        if (j <= 5 || (j >= 21 && j <= 24) || (j == 37 || j == 38))
        {
            p1[shuffledCards[j - 1] / 11][shuffledCards[j - 1] % 11] = 1;
        }
        else if ((j >= 6 && j <= 10) || (j >= 25 && j <= 28) || (j == 39 || j == 40))
        {
            p2[shuffledCards[j - 1] / 11][shuffledCards[j - 1] % 11] = 1;
        }
        else if ((j >= 11 && j <= 15) || (j >= 29 && j <= 32) || (j == 41 || j == 42))
        {
            p3[shuffledCards[j - 1] / 11][shuffledCards[j - 1] % 11] = 1;
        }
        else if ((j >= 16 && j <= 20) || (j >= 33 && j <= 36) || (j == 43 || j == 44))
        {
            p4[shuffledCards[j - 1] / 11][shuffledCards[j - 1] % 11] = 1;
        }
    }
    for (j = 1; j <= 44; j++)
    {
        if (j <= 5 || (j >= 21 && j <= 24) || (j == 37 || j == 38))
        {
            numberP1[k] = (shuffledCards[j - 1] % 11) + 1;
            switch (shuffledCards[j - 1] / 11)
            {
            case 0:
                symP1[k] = 'A';
                k++;
                break;
            case 1:
                symP1[k] = 'B';
                k++;
                break;
            case 2:
                symP1[k] = 'C';
                k++;
                break;
            case 3:
                symP1[k] = 'D';
                k++;
                break;
            }
        }
    }
    while (TRUE)
    {

        if (z)
        {
            for (k = 0; k <= 5; k++)
            {
                if (k == 5)
                {
                    z = 0;
                    break;
                }
                printf("|%c%d| ", symP1[k], numberP1[k]);
            }
        }
        printf("\nplease enter the bakhshname\nenter 0 for A , 1 for B, 2 for C, 3 for D:\n");
        scanf("%d", &bakhshname);
        getchar();
        fflush(stdin);
        if (bakhshname == 0 || bakhshname == 1 || bakhshname == 2 || bakhshname == 3)
        {
            break;
        }
        else
        {
            bakhshname = -1;
            printf("please choose between A,B,C,D correctly\n");
        }
    }
    printf("enter anything to continue:\n");
    getchar();
    fflush(stdin);
    system("cls");
    while (TRUE)
    {
        if (situation == 1)
        {
            if (score1 == 6)
                return 1;
            if (score2 == 6)
                return 2;
            board(score1, score2, symbolP1, numP1, symbolP2, numP2, symbolP3, numP3, symbolP4, numP4, situation);
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
            while (TRUE)
            {
                printf("please choose a card to play:\n");
                scanf("%d", &playedCard);
                getchar();
                fflush(stdin);
                if (playedCard < 11 && playedCard >= 0 && symP1[playedCard] != '-')
                    break;
                else
                    printf("please enter a card that you have\n");
            }
            printf("enter anything to continue:\n");
            getchar();
            fflush(stdin);
            system("cls");
            for (symbol = 0; symbol < 4; symbol++)
                if (playedSymbol[symbol] == symP1[playedCard])
                {
                    numP1 = numberP1[playedCard] - 1;
                    symbolP1 = symbol;
                    break;
                }
            p1[symbol][numP1] = 0; /*updating player one's cards*/
            symP1[playedCard] = '-';
            numberP1[playedCard] = 0;
            for (i = 10; i >= 0; i--) /*player 2 is playing*/
            {
                flag = 1;
                if (p2[symbol][i] == 1)
                {
                    p2[symbol][i] = 0;
                    symbolP2 = symbol;
                    numP2 = i;
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                for (i = 10; i >= 0; i--)
                {
                    flag = 1;
                    if (p2[bakhshname][i] == 1)
                    {
                        p2[bakhshname][i] = 0;
                        symbolP2 = bakhshname;
                        numP2 = i;
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
                        if (p2[i][j] == 1)
                        {
                            numCompare = j;
                            symCompare = i;
                            break;
                        }
                    }
                }
                p2[symCompare][numCompare] = 0;
                symbolP2 = symCompare;
                numP2 = numCompare;
            }
            for (i = 10; i >= 0; i--)
            {
                flag = 1;
                if (p3[symbol][i] == 1)
                {
                    p3[symbol][i] = 0;
                    symbolP3 = symbol;
                    numP3 = i;
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                for (i = 10; i >= 0; i--)
                {
                    flag = 1;
                    if (p3[bakhshname][i] == 1)
                    {
                        p3[bakhshname][i] = 0;
                        symbolP3 = bakhshname;
                        numP3 = i;
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
                        if (p3[i][j] == 1)
                        {
                            numCompare = j;
                            symCompare = i;
                            break;
                        }
                    }
                }
                p3[symCompare][numCompare] = 0;
                symbolP3 = symCompare;
                numP3 = numCompare;
            }
            for (i = 10; i >= 0; i--)
            {
                flag = 1;
                if (p4[symbol][i] == 1)
                {
                    p4[symbol][i] = 0;
                    symbolP4 = symbol;
                    numP4 = i;
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                for (i = 10; i >= 0; i--)
                {
                    flag = 1;
                    if (p4[bakhshname][i] == 1)
                    {
                        p4[bakhshname][i] = 0;
                        symbolP4 = bakhshname;
                        numP4 = i;
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
                        if (p4[i][j] == 1)
                        {
                            numCompare = j;
                            symCompare = i;
                            break;
                        }
                    }
                }
                p4[numCompare][symCompare] = 0;
                symbolP4 = symCompare;
                numP4 = numCompare;
            }
            result = judge(symbolP1, numP1, symbolP2, numP2, symbolP3, numP3, symbolP4, numP4, situation, bakhshname);
            situation = 0;
            board(score1, score2, symbolP1, numP1, symbolP2, numP2, symbolP3, numP3, symbolP4, numP4, situation);
            printf("enter anything to continue:\n");
            getchar();
            fflush(stdin);
            system("cls");
            if (result == 1 || result == 3)
                score1++;
            else
                score2++;
            situation = 1;
            board(score1, score2, symbolP1, numP1, symbolP2, numP2, symbolP3, numP3, symbolP4, numP4, situation);
            printf("enter anything to continue:\n");
            getchar();
            fflush(stdin);
            system("cls");
            situation = result;
        }
        else
        {
            if (score1 == 6)
                return 1;
            if (score2 == 6)
                return 2;
            startCard = starter(p2, p3, p4, situation, bakhshname);
            symbol = startCard / 11;
            if (situation == 2)
            {
                numP2 = startCard % 11;
                symbolP2 = startCard / 11;
            }
            else if (situation == 3)
            {
                numP3 = startCard % 11;
                symbolP3 = startCard / 11;
            }
            else
            {
                numP4 = startCard % 11;
                symbolP4 = startCard / 11;
            }
            if (situation != 2)
            {
                for (i = 10; i >= 0; i--) /*player 2 is playing*/
                {
                    flag = 1;
                    if (p2[symbol][i] == 1)
                    {
                        p2[symbol][i] = 0;
                        symbolP2 = symbol;
                        numP2 = i;
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    for (i = 10; i >= 0; i--)
                    {
                        flag = 1;
                        if (p2[bakhshname][i] == 1)
                        {
                            p2[bakhshname][i] = 0;
                            symbolP2 = bakhshname;
                            numP2 = i;
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
                            if (p2[i][j] == 1)
                            {
                                numCompare = j;
                                symCompare = i;
                                break;
                            }
                        }
                    }
                    p2[symCompare][numCompare] = 0;
                    symbolP2 = symCompare;
                    numP2 = numCompare;
                }
            }
            if (situation != 3)
            {
                for (i = 10; i >= 0; i--)
                {
                    flag = 1;
                    if (p3[symbol][i] == 1)
                    {
                        p3[symbol][i] = 0;
                        symbolP3 = symbol;
                        numP3 = i;
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    for (i = 10; i >= 0; i--)
                    {
                        flag = 1;
                        if (p3[bakhshname][i] == 1)
                        {
                            p3[bakhshname][i] = 0;
                            symbolP3 = bakhshname;
                            numP3 = i;
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
                            if (p3[i][j] == 1)
                            {
                                numCompare = j;
                                symCompare = i;
                                break;
                            }
                        }
                    }
                    p3[symCompare][numCompare] = 0;
                    symbolP3 = symCompare;
                    numP3 = numCompare;
                }
            }
            if (situation != 4)
            {
                for (i = 10; i >= 0; i--)
                {
                    flag = 1;
                    if (p4[symbol][i] == 1)
                    {
                        p4[symbol][i] = 0;
                        symbolP4 = symbol;
                        numP4 = i;
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    for (i = 10; i >= 0; i--)
                    {
                        flag = 1;
                        if (p4[bakhshname][i] == 1)
                        {
                            p4[bakhshname][i] = 0;
                            symbolP4 = bakhshname;
                            numP4 = i;
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
                            if (p4[i][j] == 1)
                            {
                                numCompare = j;
                                symCompare = i;
                                break;
                            }
                        }
                    }
                    p4[numCompare][symCompare] = 0;
                    symbolP4 = symCompare;
                    numP4 = numCompare;
                }
            }
            board(score1, score2, symbolP1, numP1, symbolP2, numP2, symbolP3, numP3, symbolP4, numP4, situation);
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
            flag = 0;
            for (i = 0; i < 11; i++)
            {
                if (p1[symbol][i] == 1)
                {
                    flag = 1;
                    break;
                }
            }
            while (TRUE)
            {
                printf("please choose a card to play:\n");
                scanf("%d", &playedCard);
                getchar();
                fflush(stdin);
                if (flag)
                {
                    if (playedCard < 11 && playedCard >= 0 && symP1[playedCard] != '-' && playedSymbol[symbol] == symP1[playedCard])
                        break;
                    else
                        printf("please enter a card with the symbol that is being played\n");
                }
                else if (playedCard < 11 && playedCard >= 0 && symP1[playedCard] != '-')
                    break;
                else
                    printf("please enter a card that you have\n");
            }
            for (symbol = 0; symbol < 4; symbol++)
                if (playedSymbol[symbol] == symP1[playedCard])
                {
                    numP1 = numberP1[playedCard] - 1;
                    symbolP1 = symbol;
                    break;
                }
            printf("enter anything to continue:\n");
            getchar();
            fflush(stdin);
            system("cls");
            p1[symbol][numP1] = 0; /*updating player one's cards*/
            symP1[playedCard] = '-';
            numberP1[playedCard] = 0;
            result = judge(symbolP1, numP1, symbolP2, numP2, symbolP3, numP3, symbolP4, numP4, situation, bakhshname);
            situation = 0;
            board(score1, score2, symbolP1, numP1, symbolP2, numP2, symbolP3, numP3, symbolP4, numP4, situation);
            printf("enter anything to continue:\n");
            getchar();
            fflush(stdin);
            system("cls");
            if (result == 1 || result == 3)
                score1++;
            else
                score2++;
            situation = 1;
            board(score1, score2, symbolP1, numP1, symbolP2, numP2, symbolP3, numP3, symbolP4, numP4, situation);
            printf("enter anything to continue:\n");
            getchar();
            fflush(stdin);
            system("cls");
            situation = result;
        }
    }
}