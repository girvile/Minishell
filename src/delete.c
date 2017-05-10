/*
** delete.c for delete in /home/pion_b/PSU_2016_minishell1
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Tue Jan 17 17:03:16 2017 Virgile
** Last update Tue Jan 17 17:16:10 2017 Virgile
*/

#include "my.h"

void	delete_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	{
	  free(tab[i]);
	  i++;
	}
      free(tab);
    }
}
