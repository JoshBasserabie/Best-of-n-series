#include <stdio.h>
#include <math.h>

double choose(double n, double k);

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
  for(double i = (games + 1) / 2; i <= games; i++) {
    addChance = choose(i - 1, i - ((games + 1) / 2));
    addChance *= pow((1 - gameChance), i - (games + 1) / 2);
    seriesChance += addChance;
  }
  seriesChance *= pow(gameChance, (games + 1) / 2);
  printf("\nThe chance of winning the series is: %2.8lf%%\n", seriesChance * 100);
  return 1;
}

double choose(double n, double k) {
  if(k == 0) {
    return 1;
  }
  return n / k * choose(n - 1, k - 1);
}