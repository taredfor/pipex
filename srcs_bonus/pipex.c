/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:46:52 by taredfor          #+#    #+#             */
/*   Updated: 2021/11/04 00:48:05 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	ft_execute_first(t_arg *fdp, char **argv, char **envp)
{
	if (fdp->num_cmd == 0)
	{
		if (fdp->flag == 1)
		{
			ft_limiter(fdp, argv);
			exit (1);
		}
		else
			ft_work_with_fd(fdp, argv, envp);
	}
	ft_typical_behavior(fdp, argv, envp);
}

void	create_fork(char **argv, t_arg *fdp, char **envp)
{
	int	pid1;

	fdp->num_cmd = 0;
	while (fdp->num_cmd < fdp->num_argc - 1)
	{
		pid1 = fork();
		if (pid1 == -1)
			ft_perror("ERROR6");
		if (pid1 == 0)
			ft_execute_first(fdp, argv, envp);
		else
		{
			wait (0);
			close((fdp[fdp->num_cmd].pp[1]));
			if (fdp->num_cmd)
				close(fdp[fdp->num_cmd - 1].pp[0]);
		}
		fdp->num_cmd++;
	}
}

void	pipex(int argc, char **argv, char **envp, t_arg *fdp)
{
	int	i;

	i = 0;
	while (i < fdp->num_argc - 1)
	{
		if (pipe(fdp[i].pp) == -1)
			ft_perror("Couldn't create pipe");
		i++;
	}
	create_fork(argv, fdp, envp);
	ft_execute_last_command(argc, argv, fdp, envp);
}
