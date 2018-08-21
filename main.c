/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/11 21:07:19 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/21 12:49:51 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			main(int ac, char **av, char **env)
{
	char	*str;
	t_shell	*shell;
	pid_t	pid;

	(void)ac;
	(void)av;
	if (!(shell = malloc(sizeof(shell))))
		return (0);
	ft_print_tab(env);
	pid = 0;
	while (1)
	{
		ft_putstr("\r$> ");
		signal(SIGINT, ft_sigint);
		get_next_line(0, &str);
		if (ft_isstrempty(str) < 1)
			continue ;
		if (!ft_strcmp(str, "exit"))
			return (0);
		shell->gnl = ft_spsplit(str);
		ft_print_tab(shell->gnl);
		pid = fork();
		if (ft_exec(shell, pid) == -1)
			continue ;
	}
	return (0);
}
