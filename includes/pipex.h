/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:25:50 by taredfor          #+#    #+#             */
/*   Updated: 2021/11/04 00:54:09 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define MODE O_RDONLY;

# include 	<libft.h>
# include 	<string.h>
# include 	<errno.h>
# include 	<sys/wait.h>

void	pipex(int argc, char **argv, char **envp);
void	ft_execute_second_command(int fd[], char **argv, char **envp);
void	ft_execute_first_command(int fd[], char **argv, char **envp);
void	ft_execve(char **argv, char *envp[], int i, int k);
void	ft_execve2(char **argv, char *envp[], int i, int k);

#endif