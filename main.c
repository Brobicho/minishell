/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/11 21:07:19 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/21 16:13:38 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			main(int ac, char **av, char **env)
{
	char	*str;
	t_shell	*shell;
	pid_t	pid;

	(void)ac;
	(void)av;
	shell = NULL;

	if (!(shell = malloc(sizeof(shell))))
		return (0);
	shell->envn = env;
	ft_print_tab(shell->envn);
	pid = 0;
	/*while (1)
	{*/
		ft_getentry(&str);
		str = "exit";
		if (ft_isstrempty(str) < 1)
		{
			free(str);
			return (0);
			//continue ;
		}
		else if (!ft_strcmp(str, "exit"))
		{
			free(str);
			ft_free_everything(shell);
			return (0);
		}
		shell->gnl = ft_spsplit(str);
		free(str);
		pid = fork();
		if (ft_exec(shell, pid, shell->envn) == -1)
		{
			ft_putendl("commande invalide");
			//ft_free_everything(shell);
			//continue ;
		}
		//else
			//ft_free_everything(shell);
	//}
	return (0);
}
