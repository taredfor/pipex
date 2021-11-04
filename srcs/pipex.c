/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:04:33 by taredfor          #+#    #+#             */
/*   Updated: 2021/11/04 01:13:50 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	ft_execve(char **argv, char *envp[], int i, int k)
{
	int		j;
	char	**str;
	char	*c;
	char	*final_str;
	char	**cmd;

	j = 0;
	str = ft_split(envp[i] + 5, ':');
	cmd = ft_split(argv[k], ' ');
	while (str[j])
	{
		c = ft_strjoin(str[j], "/");
		final_str = ft_strjoin(c, cmd[0]);
		execve(final_str, cmd, envp);
		j++;
		free(c);
		free(final_str);
	}
	free(str);
	free(cmd);
}

void	ft_execve2(char **argv, char *envp[], int i, int k)
{
	int		j;
	char	**str;
	char	*c;
	char	*final_str;
	char	**cmd;

	j = 0;
	str = ft_split(envp[i] + 5, ':');
	cmd = ft_split(argv[k], ' ');
	while (str[j])
	{
		c = ft_strjoin(str[j], "/");
		final_str = ft_strjoin(c, cmd[0]);
		execve(final_str, cmd, envp);
		j++;
		free(c);
		free(final_str);
	}
	free(str);
	free(cmd);
}

void	ft_execute_first_command(int fd[], char **argv, char **envp)
{
	int	int_fd;
	int	i;
	int	k;

	i = 0;
	k = 2;
	int_fd = open(argv[1], O_RDONLY);
	if (int_fd < 0)
		ft_perror("ERROR (infile)");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_perror("ERROR");
	if (dup2(int_fd, STDIN_FILENO) == -1)
		ft_perror("ERROR");
	close(fd[0]);
	close(int_fd);
	close(fd[1]);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	ft_execve(argv, envp, i, k);
}

void	ft_execute_second_command(int fd[], char **argv, char **envp)
{
	int	fd_read;
	int	i;
	int	k;

	i = 0;
	k = 3;
	fd_read = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd_read < 0)
		ft_perror("ERROR (out file)");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_perror("ERROR");
	if (dup2(fd_read, STDOUT_FILENO) == -1)
		ft_perror("ERROR");
	close(fd[0]);
	close(fd[1]);
	close(fd_read);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	ft_execve2(argv, envp, i, k);
}

void	pipex(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	int	pid1;

	if (argc < 5)
		ft_error("Error: Number arguments smaller than 5");
	if (argc > 5)
		ft_error("Error: Number arguments more than 5");
	if (pipe(fd) == -1)
		ft_perror("ERROR");
	pid1 = fork();
	if (pid1 == -1)
		ft_perror("ERROR");
	if (pid1 == 0)
	{
		ft_execute_first_command(fd, argv, envp);
		exit(0);
	}
	wait(0);
	ft_execute_second_command(fd, argv, envp);
}
