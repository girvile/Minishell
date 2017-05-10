/*
** main.c for main in /home/pion_b/PSU_2016_minishell1/src
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Mon Jan 16 13:44:45 2017 Virgile
** Last update Sun Jan 22 18:38:12 2017 Virgile
*/

#include "my.h"

void		printab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putstr("\n");
      i++;
    }
}

void		init_signal(char **signals)
{
  signals[0] = NULL;
  signals[11] = "Segmentation fault (core dumped)\n";
  signals[6] = "Abort (core dumped)\n";
  signals[7] = "Bus error (core dumped)\n";
  signals[8] = "Floating exception (core dumped)\n";
  signals[9] = "Killed\n";
  signals[15] = "Terminated\n";
}

void		init_shell(t_shell *sh)
{
  sh->input = my_epurstr(sh->input);
  sh->av = my_str_to_wordtab(sh->input, ' ');
  sh->path = my_str_to_wordtab(my_getenv(sh->env, "PATH"), ':');
}

int		main(int ac, char **av, char **env)
{
  t_shell	*sh;

  (void)av;
  (void)ac;
  if ((sh = malloc(sizeof(*sh))) == NULL)
    return (84);
  sh->env = my_add_to_tab(env, NULL);
  if (isatty(0))
    my_putstr("$> ");
  init_signal(sh->signals);
  sh->error = 0;
  while ((sh->input = get_next_line(0)))
    {
      init_shell(sh);
      if ((!my_buildin(sh)) && ((sh->pid = fork()) == 0))
	exec_child(sh);
      waitpid(sh->pid, &sh->ret, 0);
      my_sighandler(sh->ret, sh);
      if (isatty(0))
	my_putstr("$> ");
    }
  return (sh->error);
}
