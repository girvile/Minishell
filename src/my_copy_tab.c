/*
** my_copy_tab.c for my_copy_tab in /home/pion_b/PSU_2016_minishell1
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Mon Jan 16 15:13:22 2017 Virgile
** Last update Sun Jan 22 10:07:14 2017 Virgile
*/

#include "my.h"

char	*my_strcpy(char *str)
{
  int	i;
  char	*cpy;

  if ((cpy = malloc(sizeof(char) + (my_strlen(str) + 1))) == NULL)
    exit(84);
  i = 0;
  while (str[i])
    {
      cpy[i] = str[i];
      i++;
    }
  cpy[i] = '\0';
  return (cpy);
}

char	**my_add_to_tab(char **tab, char *new)
{
  int	i;
  char	**copy;

  i = 0;
  while (tab[i] != NULL)
    i++;
  if ((copy = malloc(sizeof(char *) * (i + 2))) == NULL)
    exit(84);
  i = 0;
  while (tab[i] != NULL)
    {
      copy[i] = my_strcpy(tab[i]);
      i++;
    }
  if (new != NULL)
    {
      copy[i] = my_strcpy(new);
      i++;
    }
  copy[i] = NULL;
  return (copy);
}
