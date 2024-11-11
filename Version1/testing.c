#include <stdio.h>

int main()
{
     int i = 1;
     int j = 0;
     while (1)
     {

          if (i == 1)
          {
               if (j == 1)
                    break;
               printf("1\n");
               i++;
               j++;
          }
          if (i == 2)
          {
               if (j == 1)
                    break;
               printf("2");
          }
     }
}
////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////
if (score1 == 6)
     return 1;
if (score2 == 6)
     return 2;
///////////////////////////////////////////////////////////////////////////

result = judge(symbolP1, numP1, symbolP2, numP2, symbolP3, numP3, symbolP4, numP4, situation, bakhshname);
situation = 0;
board(score1, score2, symbolP1, numP1, symbolP2, numP2, symbolP3, numP3, symbolP4, numP4, situation);
if (result == 1 || result == 3)
     score1++;
else
     score2++;
situation = 1;
board(score1, score2, symbolP1, numP1, symbolP2, numP2, symbolP3, numP3, symbolP4, numP4, situation);
situation = result;
///////////////////////////////////////////////////////////////////////////
pak krdne buffere keyboard
emtiazi
