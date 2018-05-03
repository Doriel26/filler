/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchiche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:45:26 by dchiche           #+#    #+#             */
/*   Updated: 2018/05/03 19:30:35 by dchiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>
# include <limits.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

size_t				ft_strlen(const char *str);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(intmax_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				ft_putnbr(int n);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strnstr(const char *haystack,
								const char *needle, size_t len);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void(*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_swap(int *a, int *b);
void				ft_sort_int_table(int *tab, int size);
char				*ft_strrev(char *str);
char				*ft_strcapitalize(char *str);
int					ft_str_is_printable(char *str);
void				ft_putnbr_base(uintmax_t n, char *base);
int					ft_nlen(intmax_t nbr);
int					ft_nlen_base(uintmax_t nbr, uintmax_t base);
char				*ft_itoa_u(uintmax_t n);
void				ft_putnbr_max(uintmax_t n);
void				ft_putnbr_max_u(uintmax_t n);
int					get_next_line(const int fd, char **line);
void				ft_dlstappend(t_dlist **alst, t_dlist *new);
t_dlist				*ft_dlstat(t_dlist *head, size_t index);
void				ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem));
t_dlist				*ft_dlstlink(void *content, size_t content_size);
void				ft_dlstfilter(t_dlist **alst,
								int (*p)(t_dlist *),
								void (*del)(void *, size_t));
t_dlist				*ft_dlstnew(void const *content, size_t content_size);
void				ft_dlstprepend(t_dlist **alst, t_dlist *new);
void				ft_dlstreverse(t_dlist **alst);
t_dlist				*ft_dlstremove(t_dlist **head,
								void *data,
								int (*cmp)(const void *, const void *));
t_dlist				*ft_dlstpop(t_dlist **alst);
size_t				ft_dlstlen(t_dlist *list);
void				**ft_dlst_to_tab(t_dlist *list);
void				ft_dlstsort(t_dlist **head,
								int (*cmp)(t_dlist *l1, t_dlist *l2));
int					ft_printf(const char *format, ...);

#endif
