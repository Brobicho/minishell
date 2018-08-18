/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isstrempty.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/12 11:33:20 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/12 16:12:10 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_isstrempty(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (!IS_SP(str[i]))
			return (1);
		i++;
	}
	return (0);
}
