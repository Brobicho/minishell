/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/11 21:07:19 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/18 19:45:53 by brobicho    ###    #+. /#+    ###.fr     */
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
		get_next_line(0, &str);
		if (ft_isstrempty(str) < 1)
			continue ;
		shell->gnl = ft_strsplit(str, ' ');
		pid = fork();
		if (ft_exec(shell, pid) == -1)
			continue ;
		signal(SIGINT, ft_sigint);
	}
	return (0);
}
