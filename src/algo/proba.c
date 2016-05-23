/*
** kahef.c for kahef in /home/iiyama_a/rendu/Rushs/Sudoki-Bi/src
**
** Made by andy iiyama
** Login   <iiyama_a@epitech.net>
**
** Started on  Fri Feb 26 19:51:44 2016 andy iiyama
** Last update Sun Feb 28 14:50:36 2016 andy iiyama
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int	sumchance(int *numbers)
{
  int	chance;
  int	curs;

  curs = 1;
  chance = 0;
  while (curs < 10)
    chance += numbers[curs++];
  return (chance);
}

int	checksquare(int *numbers, int **grille, int a, int b)
{
  int	curs;
  int	curs2;

  curs = 0;
  curs2 = 0;
  while (curs2 < 3)
    {
      while (curs < 3)
	numbers[grille[(3 * a) + curs2][(3 * b) + curs++]] = 0;
      curs = 0;
      curs2++;
    }
  return (sumchance(numbers));
}

int	checkposs(int **grille, int a, int b)
{
  int	curs;
  int	numbers[10];

  numbers[0] = 0;
  numbers[1] = 1;
  numbers[2] = 10;
  numbers[3] = 100;
  numbers[4] = 1000;
  numbers[5] = 10000;
  numbers[6] = 100000;
  numbers[7] = 1000000;
  numbers[8] = 10000000;
  numbers[9] = 100000000;
  curs = 0;
  if (grille[a][b] != 0)
    return (0);
  else
    {
      while (curs < 9)
	numbers[grille[a][curs++]] = 0;
      curs = 0;
      while (curs < 9)
	numbers[grille[curs++][b]] = 0;
      return (checksquare(numbers, grille, (a / 3), (b / 3)));
    }
}

int	**getchance(int **grille, int **chance)
{
  int	a;
  int	b;

  a = 0;
  while (a < 9)
    {
      b = 0;
      while (b < 9)
	{
	  chance[a][b] = checkposs(grille, a, b);
	  b++;
	}
      a++;
    }
  return (chance);
}

int	**sudosolve(int **grille)
{
  int	**chance;
  int	a;

  a = 0;
  if ((chance = malloc(sizeof(int *) * 9)) == NULL)
      return (NULL);
  while (a < 9)
    if ((chance[a++] = malloc(sizeof(int) * 9)) == NULL)
      return (NULL);
  chance = getchance(grille, chance);
  return (chance);
}
