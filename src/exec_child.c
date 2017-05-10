/*
** exec_child.c for child in /home/pion_b/PSU_2016_minishell1
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Sun Jan 22 09:27:34 2017 Virgile
** Last update Sun Jan 22 18:44:10 2017 Virgile
*/

#include "my.h"

int	my_ispath(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '/')
	return (1);
      i++;
    }
  return (0);
}

void	exec_child(t_shell *sh)
{
  int	i;
  char	*path;

  i = 0;
  while (sh->path != NULL && sh->path[i])
    {
      if (access(sh->av[0], F_OK) == 0 && my_ispath(sh->av[0]))
	{
	    execve(sh->av[0], sh->av, sh->env);
	    my_putstr_error(sh->av[0]);
	    my_putstr_error(": Permission denied.\n");
	    exit(1);
	}
      else if (!my_ispath(sh->av[0]))
	{
	  path = conc(sh->path[i], conc("/", sh->av[0]));
	  execve(path, sh->av, sh->env);
	}
      i++;
    }
  my_putstr_error(sh->av[0]);
  my_putstr_error(": Command not found.\n");
  exit(1);
}
