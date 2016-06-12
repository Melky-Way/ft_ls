/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 15:11:53 by msoudan           #+#    #+#             */
/*   Updated: 2016/06/09 16:36:14 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 124
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dbl
{
	void			*content;
	size_t			size;
	struct s_dbl	*next;
	struct s_dbl	*prev;
}					t_dbl;

typedef struct		s_dlist
{
	size_t			lenght;
	struct s_dbl	*tail;
	struct s_dbl	*head;
}					t_dlist;

/*
** Part 1
*/
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_arrlen(char **array);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isalpha_str(char *str);
int					ft_isdigit(int c);
int					ft_isdigit_str(char *str);
int					ft_isalnum(int c);
int					ft_isalnum_str(char *str);
int					ft_isascii(int c);
int					ft_isascii_str(char *str);
int					ft_isspace(char c);
int					ft_isspace_str(char *str);
int					ft_isprint(int c);
int					ft_isprint_str(char *str);
int					ft_toupper(int c);
void				ft_toupper_str(char **str);
int					ft_tolower(int c);
void				ft_tolower_str(char **str);

/*
** Part 2
*/
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_arrdel(char ***as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** Linked list
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddback(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstclear(t_list **list);
t_list				*ft_list_insert(t_list *list, void *data, int pos, \
					size_t size);
int					ft_lstpushfront(t_list **list, void *data, size_t size);
int					ft_lstpushback(t_list **list, void *data, size_t size);
t_list				**ft_lst_popfront(t_list **list);
t_list				**ft_lst_popback(t_list **list);
t_list				*ft_lst_valdel(t_list *list, void *content);
void				ft_lstprint(t_list **list);
t_list				*ft_lst_softcopy(t_list *list);
void				ft_lst_swaptail(t_list *swap, t_list **target);
void				ft_lst_swap(t_list *lst1, t_list *lst2);
void				*ft_realloc(void *ptr, size_t size);
t_list				*ft_create_new(void *content, size_t size);
int					ft_lstsize(t_list *list);
t_list				*ft_lstmergesort(t_list *a, int n, \
					int (*f)(t_list *a, t_list *b));
t_list				*ft_lstreverse(t_list *data);

/*
** Double Linked List
*/

t_dlist				*ft_dlist_new(void);
void				ft_dlist_del(t_dlist **list);
int					ft_dlist_head(t_dlist **list, void *data, size_t size);
int					ft_dlist_tail(t_dlist **list, void *data, size_t size);
t_dlist				*ft_dlist_insert(t_dlist *list, void *data, int pos, \
					size_t size);
t_dlist				*ft_dlist_valdel(t_dlist *list, void *content);
void				ft_dlist_iter(t_dlist *lst, void (*f)(t_dbl *elem));
t_dbl				*ft_new_node(void *data, size_t size);
t_dlist				*ft_dlstmergesort(t_dlist *a, int n, \
					int (*f)(t_dbl *a, t_dbl *b));
t_dlist				*ft_dlstreverse(t_dlist *data);

/*
** Bonus
*/

int					**ft_make_array(int **array, char *argv);
int					*ft_str_array(char *line);
int					get_next_line(int const fd, char **line);
char				*ft_arrjoin(char **array, char c, int option);
int					ft_is_int(char *str);
int					ft_power(int nbr, int pwr);
int					ft_dec_to_oct(int number);
int					ft_oct_to_dec(int number);

#endif
