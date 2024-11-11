#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "functions.h"
#define TRUE 1

void shuffle_card(int *card);
void shuffle_card(int *card)
{
    int i, r, temp;
    for (temp = 0, i = 0; temp < 44; i++, temp++)
        card[temp] = i;
    srand(time(NULL));
    for (i = 43; i > 0; i--)
    {
        r = rand() % i;
        temp = card[i];
        card[i] = card[r];
        card[r] = temp;
    }
}
int main()
{
    int cards[4][11] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}};
    int shuffledCards[44];
    int result;
    int set1 = 0, set2 = 0;
    while (TRUE)
    {
        shuffle_card(shuffledCards);
        result = play(shuffledCards, set1, set2);
        if (result == 1)
        {
            set1++;
        }
        else if (result == 2)
        {
            set1 += 2;
        }
        else if (result == 3)
        {
            set2++;
        }
        else
        {
            set2 += 2;
        }
        if (set1 >= 5)
        {
            printf("Team 1 won the game\n");
            break;
        }
        if (set2 >= 5)
        {
            printf("Team 2 won the game\n");
            break;
        }
    }
    printf("game is finished\n enter anything to exit\n");
    getchar();
    system("cls");
    return 0;
}
