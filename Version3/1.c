#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "functions.h"
#define A 0
#define B 1
#define C 2
#define D 3

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
    shuffle_card(shuffledCards);
    result = play(shuffledCards);
    if (result == 1) /*showing the final result*/
    {
        printf("team 1 won the game\n");
    }
    else
    {
        printf("team 2 won the game\n");
    }
    printf("game is finishe\n enter anything to exit\n");
    getchar();
    system("cls");
    return 0;
}
