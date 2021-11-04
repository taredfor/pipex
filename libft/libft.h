/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:52:08 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/31 17:14:15 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include "limits.h"

# define BUFFER_SIZE 1 

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}	t_list;

/*
**		ascii
*/
int		ft_isalpha(int ch);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/*
**		mem
*/
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memchr(const void *arr, int c, size_t n);
int		ft_memcmp(const void *dst, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);

/*
**		math
*/
int		ft_atoi(const char *str);
int		ft_atoi_for_number(const char *str);
char	*ft_itoa(int n);
int		ft_find_max(int a, int b);

/*
**		str
*/
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
int		get_next_line(int fd, char **line);

/*
**		put
*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*
**		list
*/
t_list	*ft_lstnew(int data);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, int (*del)(int));
void	ft_lstclear(t_list **lst, int (*del)(int));
void	ft_lstiter(t_list *lst, void (*f)(int));
t_list	*ft_lstmap(t_list *lst, int (*f)(int), int (*del)(int));
int		ft_find_ind_of_max_value(t_list *lst);
int		ft_lstfindmax_val(t_list *lst);
int		ft_lstfindmin_val(t_list *lst);
char	*ft_strndup(const char *str, size_t n);
int		ft_strcmp(const char *str1, const char *str2);

/*
** utils
*/
void	ft_prompt(char *str);
void	ft_error(char *str);
void	ft_perror(char *str);

#endif