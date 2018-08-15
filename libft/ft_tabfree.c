/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tabfree.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/12 12:12:49 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/12 12:21:18 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabfree(char **str)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str && str[i])
			free(str[i]);
		i++;
	}
	free(str);
}
