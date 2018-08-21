/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/15 18:54:30 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/21 13:57:10 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

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
	if (!ft_strcmp(str, "cd") || !ft_strcmp(str, "ls")
		|| !ft_strcmp(str, "echo") || !ft_strcmp(str, "setenv")
		|| !ft_strcmp(str, "unsetenv") || !ft_strcmp(str, "env"))
		return (1);
	return (0);
}

int		ft_haspath(char *str)
{
	int i;
	char *s1;

	i = 0;
	if (str && ft_strlen(str) > 5 && !ft_strncmp(str, "PATH=", 5))
	{
		s1 = ft_strsub(str, 5, ft_strlen(str) - 5);
		free(str);
		return (1);
	}
	return (0);
}
