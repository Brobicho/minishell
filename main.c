/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/11 21:07:19 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/15 20:37:48 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>


int			main(void)
{
	char 	*str;
	char	**split;
	pid_t	pid;
	int		ret;

	pid = 0;
	while (1)
	{
		ft_putstr("\r$> ");
		//signal(SIGINT, ft_sigint);
		get_next_line(0, &str);
		if (str && !ft_strcmp(str, "exit"))
		{
			signal(SIGINT, ft_sigint);
			exit(0);
			return (0);
		}

			if (ft_isstrempty(str) < 1)
				continue ;
			split = ft_strsplit(str, ' ');
		
			signal(SIGINT, ft_sigint);
			pid = fork();
			//ft_putnbrn(ft_check_commands(split));
			if (pid == 0)
			{
			if (ft_check_commands(split))
			{
				if ((ret = execve(split[0], &split[0], NULL) == -1))
				{
					exit(0);
					continue ;
				}
			}
	}
			if (pid > 0)
			{
				wait(&ret);
				//ft_putstr("command not found");
			}
		//else
		//	wait(0);
		signal(SIGINT, ft_sigint);
	}
	return (0);
}
