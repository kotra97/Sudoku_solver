/*
** sudoku.h for sudoku in /home/rousse_i/rendu/CPE/Sudoki-Bi/include
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Sat Feb 27 15:14:05 2016 mathis rousselot
** Last update Sun Feb 28 15:42:45 2016 mathis rousselot
*/

#ifndef SUDOKU_H_
# define SUDOKU_H_

int     check_validity(int **tab);
int     **algo(int **tab, int curs, int curs_2);
void	free_array(int **array);
int     **lobby(int **tab);
void    print_tab(int **tab, int index);
int     **sudosolve(int **);
char    *get_next_line(const int fd);
int     check_table(char *);
int     get_table(int ***tab, char *str, int nbr_su);

#endif /* !SUDOKU_H_ */
