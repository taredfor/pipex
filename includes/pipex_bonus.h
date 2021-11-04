/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:38:40 by taredfor          #+#    #+#             */
/*   Updated: 2021/11/04 00:38:43 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <string.h>
# include <sys/wait.h>
# include <errno.h>
# include <unistd.h>

typedef struct s_arg
{
	int	pp[2];
	int	flag;
	int	num_argc;
	int	num_cmd;
	int	i;
}	t_arg;

void	pipex(int argc, char **argv, char **envp, t_arg *fdp);
void	create_fork(char **argv, t_arg *fdp, char **envp);
void	ft_execute_last_command(int argc, char **argv, t_arg *fdp, char **envp);
void	ft_execute_first(t_arg *fdp, char **argv, char **envp);
void	ft_work_with_fd(t_arg *fdp, char **argv, char **envp);
void	ft_limiter(t_arg *fdp, char **argv);
void	ft_typical_behavior(t_arg *fdp, char **argv, char **envp);
void	ft_execve(int i, t_arg *fdp, char **argv, char **envp);

#endif
