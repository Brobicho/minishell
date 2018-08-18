/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 03:19:54 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/18 19:12:45 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pos(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char		*ft_itoa(int n)
{
	int		i;
	int		pos;
	char	*res;

	if (n < 0)
		pos = -1;
	else
		pos = 1;
	i = ft_nblen(n);
	if (!(res = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	res[i] = '\0';
	while (--i >= 0)
	{
		res[i] = ft_pos(n % 10) + 48;
		n = ft_pos(n / 10);
	}
	if (pos == -1)
		res[0] = '-';
	return (res);
}
