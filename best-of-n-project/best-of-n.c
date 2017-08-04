#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define DEBUG false //Turns on printf statements that assist debugging (true/false)

double choose(double n, double k);

/*
  Given a number of games and a team's probability to win each game (from standard input),
  this program calculates the probability of the team winning the whole series.
  For a series with 2k + 1 games (for example a BO5 series, k = 2),
  the program calculates the probability by summing the chance of winning in k+1 games, k+2 games, ..., 2k+1 games.
*/

int main() {
  double games = 0;
  double gameChance = 0;
  double addChance = 0;
  double seriesChance = 0;
  printf("Welcome to the best of n series probability calculator.\n\n");
  printf("How many games are in the series?\n");
  scanf("%lf", &games);
  printf("What is the team's probability of winning each game?\n");
  printf("Please enter this as a decimal (not a fraction).\n");
  scanf("%lf", &gameChance);
  for(double i = floor(games / 2) + 1; i <= games; i++) {
    if(DEBUG)
      printf("\nCalculating chance of winning in %d games:\n", (int)i);
    addChance = choose(i - 1, (i - floor(games / 2) - 1));
    if(DEBUG)
      printf("Choose games: C(%.1lf, %.1lf) = %.1lf\n", i - 1, (i - floor(games / 2) - 1), addChance);
    addChance *= pow((1 - gameChance), (i - floor((games / 2)) - 1));
    if(DEBUG)
      printf("Factor in opponent's wins: %lf\n", addChance);
    seriesChance += addChance;
    if(DEBUG)
      printf("Final chance for %d games: %lf\n", (int)i, addChance * pow(gameChance, floor(games / 2) + 1));
  }
  seriesChance *= pow(gameChance, floor((games / 2)) + 1);
  seriesChance *= 100;
  printf("\nThe chance of winning the series is: %2.8lf%%\n", seriesChance);
  if((int)games & 1) {
    printf("Since this series has an odd number of games,\n");
    printf("the chance of the other team winning the series is %2.8lf%%\n", 100 - seriesChance);
  } else {
    double drawChance = choose(games, games/2) * pow(gameChance, games/2) * pow(1-gameChance, games/2) * 100;
    printf("Since this series has an even number of games,\n");
    printf("the chance of the other team winning the series is %2.8lf%%\n", 100 - seriesChance - drawChance);
    printf("and the chance of a draw is %2.8lf%%\n", drawChance);
  }
  return 1;
}

double choose(double n, double k) {
  if(k < 1) {
    return 1;
  }
  return n / k * choose(n - 1, k - 1);
}
