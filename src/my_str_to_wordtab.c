/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/pion_b/PSU_2016_minishell1
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Mon Jan 16 14:44:32 2017 Virgile
** Last update Sun Jan 22 10:59:05 2017 Virgile
*/

#include "my.h"

int	get_nb_separation(char *str, char separation)
{
  int	i;
  int	nb_separations;

  nb_separations = 0;
  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    {
      if (str[i] == separation)
	nb_separations++;
      i++;
    }
  return (nb_separations);
}

int	my_strtab_len(char *str, char separation)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != separation)
    i++;
  return (i);
}

char	**my_str_to_wordtab(char *str, char separation)
{
  int	i;
  int	j;
  int	nb_separations;
  char	**tab;

  nb_separations = get_nb_separation(str, separation);
  if ((tab = malloc((nb_separations + 2) * sizeof(char *))) == NULL	\
      || str == NULL)
    return (NULL);
  i = 0;
  while (i < nb_separations + 1)
    {
      if ((tab[i] = malloc(sizeof(char) *				\
			   (my_strtab_len(str, separation) + 1))) == NULL)
	exit(84);
      j = 0;
      while (my_strtab_len(str, separation) != 0)
	tab[i][j++] = *(str++);
      tab[i][j] = '\0';
      i++;
      str++;
    }
  tab[i] = NULL;
  return (tab);
}
