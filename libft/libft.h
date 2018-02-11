/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:42:17 by egaraz            #+#    #+#             */
/*   Updated: 2018/02/10 17:35:45 by egaraz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <wchar.h>

# define BUFF_SIZE 1
# define MAX_FD 1025

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_lst
{
	struct s_lst	*next;
	struct s_lst	*prec;
	char			*s;
	int				fd;
}					t_lst;

typedef enum	e_bool
{
	false, true
}				t_bool;
typedef enum	e_specifier
{
	INVALID, DECIMAL, U_DECIMAL, HEX_LOWER, HEX_UPPER, POINTER,
	OCTAL, STRING, CHAR, PERCENT
}				t_specifier;
typedef enum	e_length
{
	DEFAULT, HH, H, L, LL, J, Z
}				t_length;

typedef struct	s_flag
{
	t_bool zero;
	t_bool sign;
	t_bool left_justify;
	t_bool space;
	t_bool sharp;

}				t_flag;
typedef struct	s_format
{
	char	*str;
	int		position;
	int		written;
}				t_format;

typedef struct	s_tags
{
	unsigned int	precision;
	unsigned int	width;
	unsigned int	iter;
	t_length		length;
	t_bool			set_precision;
	t_bool			width_precision;
	t_flag			flags;
	t_specifier		specifier;
}				t_tags;

size_t				wstrlen(wchar_t *str);
void				ft_putwchar(wchar_t chr);
void				ft_strtoupper(char *string);
void				ft_strtolower(char *string);
void				atoi_add_digit(const char c, unsigned int *number);
char				*ft_itoa_large(intmax_t n);
char				*ft_itoa_ularge(uintmax_t n);
char				*ft_itoa_base(uintmax_t number, int base);
size_t				wcharlen(wchar_t chr);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_printf(char *format, ...);
char				*get_pos(t_format *format);
t_bool				is_tag(char chr);
void				validate_flags(t_tags *tags);
t_bool				check_percent(t_format *format);
void				analyse_format(t_format *format, va_list arg);
void				analyse_tags(t_format *format, va_list arg);
void				get_tags(t_tags *tags, t_format *format, va_list arg);
void				get_width(t_tags *tags, t_format *format, va_list arg);
void				get_flags(t_tags *tags, t_format *format);
void				get_precision(t_tags *tags, t_format *format, va_list arg);
void				get_length(t_tags *tags, t_format *format);
void				get_specifier(t_tags *tags, t_format *format);
void				print_format(t_tags *tags, t_format *format, va_list arg);
char				*get_string(t_tags *tags, va_list arg);
char				*set_str_precision(t_tags *tags, char *str);
char				*get_str(t_tags *tags, va_list arg);
char				*get_octal(t_tags *tags, va_list arg);
char				width_char(t_tags *tags);
char				*get_pointer(t_tags *tags, va_list arg);
char				*get_hex(t_tags *tags, va_list arg);
char				*get_decimal(t_tags *tags, va_list arg);
void				print_char(t_tags *tags, t_format *format, char chr);
uintmax_t			get_u_value(t_tags *tags, va_list arg);
intmax_t			get_s_value(t_tags *tags, va_list arg);
char				*get_percent(t_tags *tags, t_format *format);
void				print_wstr(t_tags *tags, t_format *format, va_list arg);
void				print_wchar(t_tags *tags, t_format *format, wchar_t chr);
void				print(t_tags *tags, t_format *format, va_list arg);
void				precision(t_tags *tags, char **str);
void				print_invalid(t_tags *tags, t_format *format);
void				print_sign(t_tags *tags, t_format *format, char *str);
void				print_width(t_tags *tags, t_format *format, char *str);
char				*ft_strjoinfree(char *s1, char *s2, int f);
int					get_next_line(const int fd, char **line);
void				ft_bzero(void *s, size_t len);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strlen(const char *s);
void				ft_putchar(char c);
void				ft_putnbr(int nb);
void				ft_putstr(const char *str);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char(*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int nb, int fd);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_min(int a, int b);
int					ft_max(int a, int b);

#endif
