/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_signals.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/15 18:59:32 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/15 18:59:57 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sigint(pid_t signal)
{
	(void)signal;
	ft_putchar('\n');
}

void	ft_sigsegv(pid_t signal)
{
	(void)signal;
	ft_putendl("Segmentation fault");
}
