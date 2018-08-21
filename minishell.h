/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/11 21:29:33 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/21 14:17:53 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

typedef struct	s_shell
{
	char **gnl;
	char **envn;
	char *path;
}				t_shell;

void	ft_sigint(int signal);
void	ft_sigsegv(int signal);
int		ft_iscommand(char *str);
int		ft_check_commands(char **str);
int		ft_haspath(char *str);
int		ft_exec(t_shell *shell, int pid, char **envn);
char	*ft_getentry(char **str);
void	ft_free_everything(t_shell *shell);

#endif
