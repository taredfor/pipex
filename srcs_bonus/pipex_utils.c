/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:40:02 by taredfor          #+#    #+#             */
/*   Updated: 2021/11/04 01:45:42 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	ft_execve(int i, t_arg *fdp, char **argv, char **envp)
{
	int		j;
	char	**str;
	char	*c;
	char	*final_str;
	char	**cmd;

	j = 0;
	str = ft_split(envp[fdp->i] + 5, ':');
	cmd = ft_split(argv[i], ' ');
	while (str[j])
	{
		c = ft_strjoin(str[j], "/");
		final_str = ft_strjoin(c, cmd[0]);
		execve(final_str, cmd, envp);
		j++;
		free(c);
		free(final_str);
	}
	free (str);
	free (cmd);
}

void	ft_typical_behavior(t_arg *fdp, char **argv, char **envp)
{
	if (fdp->num_cmd != 0)
	{
		close(fdp[fdp->num_cmd - 1].pp[1]);
		if (dup2(fdp[fdp->num_cmd - 1].pp[0], STDIN_FILENO) < 0)
			ft_perror("ERROR7777777");
		close(fdp[fdp->num_cmd - 1].pp[0]);
	}
	if (dup2(fdp[fdp->num_cmd].pp[1], STDOUT_FILENO) == -1)
		ft_perror("ERROR8");
	close(fdp[fdp->num_cmd].pp[1]);
	close(fdp[fdp->num_cmd].pp[0]);
	if (fdp->num_cmd > 0)
		ft_execve(fdp->num_cmd + 2, fdp, argv, envp);
}

void	ft_limiter(t_arg *fdp, char **argv)
{
	char	*buf;

	buf = NULL;
	close(fdp[fdp->num_cmd].pp[0]);
	while (ft_strcmp(buf, argv[2]))
	{
		if (get_next_line(0, &buf))
		{
			write(fdp[fdp->num_cmd].pp[1], buf, ft_strlen(buf));
			write(fdp[fdp->num_cmd].pp[1], "\n", 1);
		}
		free(buf);
	}
}

void	ft_work_with_fd(t_arg *fdp, char **argv, char **envp)
{
	int	int_fd;

	int_fd = open(argv[1], O_RDONLY);
	if (int_fd < 0)
		ft_perror("ERROR1");
	if (dup2(int_fd, STDIN_FILENO) < 0)
		ft_perror("ERROR2");
	if (dup2(fdp[fdp->num_cmd].pp[1], STDOUT_FILENO) < 0)
		ft_perror("ERROR3");
	close(fdp[fdp->num_cmd].pp[0]);
	close(fdp[fdp->num_cmd].pp[1]);
	close(int_fd);
	ft_execve(fdp->num_cmd + 2, fdp, argv, envp);
}

void	ft_execute_last_command(int argc, char **argv, t_arg *fdp, char **envp)
{
	int	out_fd;

	if (fdp->flag == 1)
		out_fd = open(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0777);
	else
		out_fd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (out_fd < 0)
		ft_perror("ERROR (out file)");
	if (dup2(fdp[fdp->num_argc - 2].pp[0], STDIN_FILENO) == -1)
		ft_perror("ERROR4");
	if (dup2(out_fd, STDOUT_FILENO) == -1)
		ft_perror("ERROR5");
	close(out_fd);
	close(fdp[fdp->num_argc - 2].pp[1]);
	close(fdp[fdp->num_argc - 2].pp[0]);
	ft_execve(argc - 2, fdp, argv, envp);
}
