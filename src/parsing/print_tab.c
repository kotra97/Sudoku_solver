/*
** print_tab.c for print_tab in /home/rousse_i/rendu/CPE/Sudoki-Bi/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Sat Feb 27 14:39:01 2016 mathis rousselot
** Last update Sat Feb 27 14:57:42 2016 mathis rousselot
*/

#include <stdio.h>

void    print_answer(int **tab)
{
  int   curs;

  curs = 0;
  while (curs != 9)
    {
      printf("| %i %i %i %i %i %i %i %i %i|\n", tab[curs][0], tab[curs][1],
	     tab[curs][2], tab[curs][3], tab[curs][4], tab[curs][5],
	     tab[curs][6], tab[curs][7], tab[curs][8]);
      curs++;
    }
}

void	print_error()
{
  int	curs;

  curs = 0;
  while (curs != 9)
    {
      printf("| X X X X X X X X X|\n");
      curs++;
    }
}

void	print_tab(int **tab, int index)
{
  if (index != 0)
    printf("####################\n");
  printf("|------------------|\n");
  if (tab[0][0] == -1)
    print_error();
  else
    print_answer(tab);
  printf("|------------------|\n");
}
