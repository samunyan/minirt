/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:28:18 by samunyan          #+#    #+#             */
/*   Updated: 2023/05/31 15:39:37 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include "ft_printf.h"

# define BASE_16_LOW			"0123456789abcdef"
# define BASE_16_UP				"0123456789ABCDEF"
# define BASE_10				"0123456789"
# define BASE_2					"01"

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_isupper(int c);
int			ft_islower(int c);

int			ft_toupper(int c);
int			ft_tolower(int c);

size_t		ft_strlen(const char *s);
size_t		ft_strnlen(const char *s, size_t maxlen);

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);

char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strstr(const char *haystack, const char *needle);
int			ft_atoi(const char *str);
int			ft_atoi_is_valid(int i, const char *str);
int			ft_atoi_base(const char *str, const char *base);
int			ft_atoi_base_is_valid(int i, const char *str, const char *base);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_strndup(char const *s, size_t len);
char		*ft_append(char **dst, const char *src);
char		*ft_append_until(char **dst, const char *src, size_t n);
char		*ft_prepend(char **dst, const char *src);

char		*ft_skip_space(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strnjoin(char const *s1, char const *s2, size_t n);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		**ft_split_set(char const *s, char const *set);
char		*ft_itoa(int n);
char		*ft_utoa(unsigned int n);
char		*ft_ltoa(long n);
char		*ft_utoa_base(unsigned int n, char *base);
char		*ft_ultoa_base(unsigned long n, char *base);
char		*ft_ulltoa_base(unsigned long long n, char *base);
size_t		ft_get_num_len(unsigned long long n, unsigned int radix);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		*ft_free_arr_until(void **arr, size_t i);
void		*ft_free_arr(void **arr);
char		*ft_strupcase(char *str);

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memappend(void **dst, const void *src, size_t dstsize,
				size_t srcsize);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);

char		*get_next_line(int fd);

int			ft_abs(int n);
int			ft_max(int a, int b);
int			ft_min(int a, int b);
float		ft_fmin(float a, float b);
double		ft_lerp(double a, double b, double t);

int			*ft_get_lis(int a[], int n);
int			ft_lis(int a[], int n);
int			*ft_get_len_of_increasing_sequences(int a[], int n);
int			ft_get_len_of_lis(int len_arr[], int n);
int			ft_get_end_index_of_lis(int n, int len_arr[]);

void		ft_swap(int *a, int *b);
int			ft_binary_search(int *arr, int size, int n);
void		ft_selection_sort(int a[], int n);
void		ft_insertion_sort(int a[], int n);
void		ft_quicksort(int a[], int lo, int hi);

typedef struct s_s_list
{
	void			*content;
	struct s_s_list	*next;
}	t_s_list;

t_s_list	*ft_s_lstnew(void *content);
int			ft_s_lstsize(t_s_list *lst);
t_s_list	*ft_s_lstlast(t_s_list *lst);
void		ft_s_lstadd_front(t_s_list **lst, t_s_list *new);
void		ft_s_lstadd_back(t_s_list **lst, t_s_list *new);
void		ft_s_lstdelone(t_s_list *lst, void (*del)(void*));
void		ft_s_lstclear(t_s_list **lst, void (*del)(void*));
void		ft_s_lstiter(t_s_list *lst, void (*f)(void *));
t_s_list	*ft_s_lstmap(t_s_list *lst, void *(*f)(void *),
				void (*del)(void *));
t_s_list	*ft_s_lstfind_content(t_s_list *lst, void *content);
int			ft_s_lstfind_position(t_s_list *lst, t_s_list *node);
t_s_list	*ft_s_lstnode_at(t_s_list *list, int index);

void		ft_err_msg(char *(*f)(int), int errnum, const char *msg);
void		*ft_malloc(size_t size);
float		ft_atof(const char *str);
const char	*ft_strspace(const char *str);

#endif
