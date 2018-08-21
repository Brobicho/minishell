/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_signals.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/15 18:59:32 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/21 12:50:36 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sigint(pid_t signal)
{
	(void)signal;
	ft_putstr("\n\r$> ");
}

void	ft_sigsegv(pid_t signal)
{
	(void)signal;
	ft_putendl("Segmentation fault");
}
