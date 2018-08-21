/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tools.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/18 19:27:45 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/21 11:28:23 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		ft_exec(t_shell *shell, int pid)
{
	int		ret;

	if (!pid)
	{
		/*if (ft_check_commands(shell->gnl))
		{*/
			if ((ret = execve(shell->gnl[0], &shell->gnl[0], NULL) == -1))
			{
				exit(0);
				return (ret);
			}
		//}
		else
		{
			ft_putendl("\rCommande inconnue.");
			return (-1);
		}
	}
	else
		wait(&ret);
	return (0);
}
