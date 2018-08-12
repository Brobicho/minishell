/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/11 21:07:19 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/12 17:45:06 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int			main(void)
{
	char 	*str;
	char	**split;
	int		ret;
	//pid_t	father;

	while (1)
	{
		ft_putstr("$> ");
	//	signal(SIGINT, sigint);
		get_next_line(0, &str);
		if (ft_isstrempty(str) < 1)
			continue ;
		split = ft_strsplit(str, ' ');
		if ((ret = execve(split[0], &split[0], NULL)) == -1)
			perror("error");
	}
	return (0);
}
