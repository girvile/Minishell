/*
** buildin.c for buildin in /home/pion_b/PSU_2016_minishell1
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Sun Jan 22 09:11:37 2017 Virgile
** Last update Sun Jan 22 18:54:02 2017 Virgile
*/

#include "my.h"

void		my_exec_cd(t_shell *sh)
{
  if (sh->av[1][0] == '/')
    {
      getcwd(sh->cwd, 1000);
      my_setenv(sh->env, "OLDPWD", my_strcpy(sh->cwd));
      chdir(sh->av[1]);
      getcwd(sh->cwd, 1000);
      sh->env = my_setenv(sh->env, "PWD", sh->cwd);
    }
  else if (sh->av[1][0] != '-')
    {
      getcwd(sh->cwd, 1000);
      my_setenv(sh->env, "OLDPWD", my_strcpy(sh->cwd));
      chdir(conc(conc(my_getenv(sh->env, "PWD"), "/"), sh->av[1]));
      getcwd(sh->cwd, 1000);
      sh->env = my_setenv(sh->env, "PWD", sh->cwd);
    }
  else if (my_getenv(sh->env, "OLDPWD") != NULL)
    {
      getcwd(sh->cwd, 1000);
      chdir(my_getenv(sh->env, "OLDPWD"));
      sh->env = my_setenv(sh->env, "OLDPWD", sh->cwd);
      getcwd(sh->cwd, 1000);
      sh->env = my_setenv(sh->env, "PWD", sh->cwd);
    }
}

void		exec_cd(t_shell *sh)
{
  if (sh->av[1] == NULL)
    {
      chdir("~/");
      getcwd(sh->cwd, 1000);
      sh->env = my_setenv(sh->env, "PWD", sh->cwd);
    }
  else if (sh->av[2] != NULL)
    my_putstr_error("cd: Too many arguments.\n");
  else
    my_exec_cd(sh);
}

void		exec_exit(t_shell *sh)
{
  if (sh->av[1] == NULL)
    {
      my_putstr_error("exit\n");
      exit(1);
    }
  else
    {
      my_putstr_error("exit\n");
      exit(my_getnbr(sh->av[1]));
    }
}

void		exec_setenv(t_shell *sh)
{
  if (sh->av[0] != NULL && sh->av[1] == NULL)
    printab(sh->env);
  else if (sh->av[0] != NULL && sh->av[1] != NULL)
    sh->env = my_setenv(sh->env, sh->av[1], sh->av[2]);
  else
    my_putstr_error("error setenv: invalid arguments\n");
}

int		my_buildin(t_shell *sh)
{
  int		i;

  i = 0;
  if (my_strcmp(sh->av[0], "exit"))
    exec_exit(sh);
  else if (my_strcmp(sh->av[0], "env"))
    printab(sh->env);
  else if (my_strcmp(sh->av[0], "setenv"))
    exec_setenv(sh);
  else if (my_strcmp(sh->av[0], "unsetenv"))
    {
      while (sh->av[0] != NULL && sh->av[++i] != NULL)
	sh->env = my_unsetenv(sh->env, sh->av[i]);
      if (sh->av[0] == NULL || sh->av[1] == NULL)
	my_putstr("unsetenv: Too few arguments.\n");
      return (1);
    }
  else if (my_strcmp(sh->av[0], "cd"))
    exec_cd(sh);
  else
    return (0);
  return (1);
}
