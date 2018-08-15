/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/11 21:29:33 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/15 19:27:50 by brobicho    ###    #+. /#+    ###.fr     */
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

#endif
