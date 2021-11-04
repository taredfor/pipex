/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:39:51 by taredfor          #+#    #+#             */
/*   Updated: 2021/11/04 00:53:09 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

//void	ft_execve(int i, t_arg *fdp, char **argv, char **envp)
//{
//	int j = 0;
//	char **str;
//	char *c;
//	char *final_str;
//	char **cmd;
//
//	str = ft_split(envp[fdp->i] + 5, ':');
//	cmd = ft_split(argv[i], ' ');
//	while (str[j])
//	{
//		c = ft_strjoin(str[j], "/");
//		final_str = ft_strjoin(c, cmd[0]);
//		execve(final_str, cmd, envp);
//		j++;
//		free(c);
//		free(final_str);
//	}
//	free (str);
//	free (cmd);
//}
//
//void	ft_typical_behavior(t_arg *fdp, char **argv, char **envp)
//{
//	if (fdp->num_cmd != 0)
//	{
//		close(fdp[fdp->num_cmd - 1].pp[1]);
//		if (dup2(fdp[fdp->num_cmd - 1].pp[0], STDIN_FILENO) < 0)
//			ft_perror("ERROR7777777");
//		close(fdp[fdp->num_cmd - 1].pp[0]);
//	}
//	if (dup2(fdp[fdp->num_cmd].pp[1], STDOUT_FILENO) == -1)
//		ft_perror("ERROR8");
//	close(fdp[fdp->num_cmd].pp[1]);
//	close(fdp[fdp->num_cmd].pp[0]);
//	if (fdp->num_cmd > 0)
//		ft_execve(fdp->num_cmd + 2, fdp, argv, envp);
//}
//
//void	ft_limiter(t_arg *fdp, char **argv, char **envp)
//{
//	char *buf;
//
//	buf = NULL;
//	close(fdp[fdp->num_cmd].pp[0]);
//	while (ft_strcmp(buf, argv[2]))
//	{
//		if (get_next_line(0, &buf) && ft_strncmp(buf, argv[2], ft_strlen(argv[2])))
//		{
//			write(fdp[fdp->num_cmd].pp[1], buf, ft_strlen(buf));
//			write(fdp[fdp->num_cmd].pp[1],"\n" , 1);
//		}
//		free(buf);
//	}
//}
//
//void	ft_work_with_fd(t_arg *fdp, char **argv, char **envp)
//{
//	int int_fd;
//
//	int_fd = open(argv[1], O_RDONLY);
//	if (int_fd < 0)
//		ft_perror("ERROR1");
//	if (dup2(int_fd, STDIN_FILENO) < 0)
//		ft_perror("ERROR2");
//	if (dup2(fdp[fdp->num_cmd].pp[1], STDOUT_FILENO) < 0)
//		ft_perror("ERROR3");
//	close(fdp[fdp->num_cmd].pp[0]);
//	close(fdp[fdp->num_cmd].pp[1]);
//	close(int_fd);
//	ft_execve(fdp->num_cmd + 2, fdp, argv, envp);
//}
//
//void	ft_execute_first(t_arg *fdp, char **argv, char **envp)
//{
//	if (fdp->num_cmd == 0)
//	{
//		if (fdp->flag == 1)
//		{
//			ft_limiter(fdp, argv, envp);
//			exit (1);
//		}
//		else
//			ft_work_with_fd(fdp, argv, envp);
//	}
//	ft_typical_behavior(fdp, argv,envp);
//}
//
//void	ft_execute_last_command(int argc, char **argv, t_arg *fdp, char **envp)
//{
//	int out_fd;
//
//	out_fd = open(argv[argc - 1],  O_CREAT |  O_RDWR   | O_TRUNC, 0777);
//	if (out_fd < 0)
//		ft_perror("ERROR (out file)");
//	if (dup2(fdp[fdp->num_argc - 2].pp[0], STDIN_FILENO) == -1)
//		ft_perror("ERROR4");
////	if (dup2(out_fd, STDOUT_FILENO) == -1)
////		ft_perror("ERROR5");
//	close(out_fd);
//	close(fdp[fdp->num_argc - 2].pp[1]);
//	close(fdp[fdp->num_argc - 2].pp[0]);
//	printf("%d", fdp->num_argc);
//	ft_execve(argc - 2, fdp, argv, envp);
//}
//
//void create_fork(int argc, char **argv, t_arg *fdp, char **envp)
//{
//	int pid1;
//
//	fdp->num_cmd = 0;
//	while (fdp->num_cmd < fdp->num_argc - 1)
//	{
//		pid1 = fork();
//		if (pid1 == -1)
//			ft_perror("ERROR6");
//		if (pid1 == 0)
//			ft_execute_first(fdp, argc, argv, envp);
//		else
//		{
//			wait (0);
//			close((fdp[fdp->num_cmd].pp[1]));
//			if (fdp->num_cmd)
//				close(fdp[fdp->num_cmd - 1].pp[0]);
//		}
//		fdp->num_cmd++;
//	}
//}
//
//void pipex(int argc, char **argv, char **envp, t_arg *fdp)
//{
//	int i;
//
//	i = 0;
//	while (i < fdp->num_argc - 1)
//	{
//		if (pipe(fdp[i].pp) == -1)
//			ft_perror("Couldn't create pipe");
//		i++;
//	}
//	create_fork(argc,argv, fdp, envp);
//	ft_execute_last_command( argc , argv, fdp, envp);
//}

int	main(int argc, char **argv, char **envp)
{
	t_arg *fdp;

	fdp = (t_arg *) malloc(sizeof(t_arg) * (argc - 3));
	if (!fdp)
		ft_perror("Couldn't to allocate memory");
	fdp->flag = -1;
	fdp->num_argc = argc - 3;
	if (ft_strcmp(argv[1], "here_doc") == 0)
		fdp->flag = 1;
	if (argc < 5 && fdp->flag == -1)
		ft_perror("Not arguments &&&&&&");
	else if (argc < 6 && fdp->flag == 1)
		ft_perror("Not enough arguments");
	fdp->i = 0;
	while (envp[fdp->i])
	{
		if (ft_strncmp(envp[fdp->i], "PATH=", 5) == 0)
			break;
		fdp->i++;
	}
	pipex(argc, argv, envp, fdp);
	free(fdp);
	return 0;
}