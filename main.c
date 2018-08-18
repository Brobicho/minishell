/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/11 21:07:19 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/18 19:08:07 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>


int			main(int ac, char **av, char **env)
{
	char	*str;
	t_shell	*shell;
	pid_t	pid;
	int		ret;

	(void)ac;
	(void)av;
	if (!(shell = malloc(sizeof(shell))))
		return (0);
	ft_print_tab(env);
	pid = 0;
	while (1)
	{
		ft_putstr("\r$> ");
		get_next_line(0, &str);
		if (str && !ft_strcmp(str, "exit"))
		{
			exit(0);
			return (0);
		}
		if (ft_isstrempty(str) < 1)
			continue ;
		shell->gnl = ft_strsplit(str, ' ');
		pid = fork();
		if (!pid)
		{
			if (ft_check_commands(shell->gnl))
			{
				if ((ret = execve(shell->gnl[0], &shell->gnl[0], NULL) == -1))
				{
					exit(0);
					continue ;
				}
			}
		}
		if (pid > 0)
			wait(&ret);
		signal(SIGINT, ft_sigint);
	}
	return (0);
}
