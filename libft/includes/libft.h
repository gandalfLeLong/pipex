/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:22:32 by cmathot           #+#    #+#             */
/*   Updated: 2024/04/06 13:59:49 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*----------INCLUDES----------*/
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/*----------LIBFT_DECLARATION----------*/
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
long	ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystac, const char *needle, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_free_tab(char **tab);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/*----------GNL_DECLARATION---------*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t	ft_strlen(const char *s);
int		new_line(char *str);
char	*get_next_line(int fd);
char	*ft_get_content(int fd, char *stock);
char	*ft_get_line(char *stock);
char	*ft_get_rest_n_free(char *stock);
char	*ft_new_array(void);
char	*ft_strjoin_n_free(char	*stock, char *buf);
char	*ft_return_n_free(char *str);

/*----------PRINTF_DECLARATION----------*/
int		ft_printf(int fd, const char *format, ...);
int		ft_table_of_functions(char c, va_list ap, int fd);
int		ft_is_in(char c);
int		ft_putchar(char c, int fd);
int		ft_putstr(char *str, int fd);
int		ft_putnbr(int n, int fd);
int		ft_putnbr_unsigned(unsigned int n, int fd);
int		ft_putnbr_hexa(int base, unsigned int n, int fd);
int		ft_putnbr_adress(int base, unsigned long n, int fd);

#endif
