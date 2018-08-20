/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/11 21:29:33 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/20 13:28:40 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

void	ft_sigint(int signal);
void	ft_sigsegv(int signal);
int		ft_iscommand(char *str);
int		ft_check_commands(char **str);
int		ft_haspath(char *str);

typedef struct	s_shell
{
	char **gnl;
	char **envn;
}				t_shell;

int		ft_exec(t_shell *shell, int pid);

#endif
