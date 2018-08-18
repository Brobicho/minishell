/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/15 18:54:30 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/18 18:43:11 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_commands(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_iscommand(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_iscommand(char *str)
{
	if (!str)
		return (0);
	if (!ft_strcmp(str, "cd") || !ft_strcmp(str, "/bin/ls")
		||!ft_strcmp(str, "echo") || !ft_strcmp(str, "setenv")
		|| !ft_strcmp(str, "unsetenv") || !ft_strcmp(str, "env"))
		return (1);
	return (1);
}

int		ft_haspath(char *str)
{
	int i;

	i = 0;
	if (str && ft_strlen(str) > 5 && !ft_strncmp(str, "PATH=", 5))
		return (1);
	return (0);
}