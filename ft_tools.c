/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tools.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/18 19:27:45 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/21 16:09:48 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tabfree(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i])
		{
			free(str[i]);
			str[i] = NULL;
		}
		i++;
	}
	free(str);
}

void	ft_free_everything(t_shell *shell)
{
	int	i;

	i = 0;
	if (shell->envn)
		ft_tabfree(shell->envn);
	if (shell->gnl)
		ft_tabfree(shell->gnl);
	if (shell->path)
	{
		free(shell->path);
		shell->path = NULL;
	}
}

void	*ft_realloc(void *ptr, size_t size)
{
	char	*newptr;

	if (!size && ptr)
	{
		if (!(newptr = (char *)malloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (newptr);
	}
	if (!(newptr = (char *)malloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(newptr, ptr, size);
		ft_memdel(&ptr);
	}
	return (newptr);
}

void	ft_getentry(char **str)
{
	char *tmp;

	tmp = *str;
	ft_putstr("\r$> ");
	signal(SIGINT, ft_sigint);
	get_next_line(0, str);
}

int		ft_exec(t_shell *shell, int pid, char **envn)
{
	int		ret;

	if (!pid)
	{
		/*if (ft_check_commands(shell->gnl))
		{*/
			if ((ret = execve(shell->gnl[0], &shell->gnl[0], envn) == -1))
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
