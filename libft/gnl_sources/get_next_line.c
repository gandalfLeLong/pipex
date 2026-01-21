/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:24:22 by cmathot           #+#    #+#             */
/*   Updated: 2024/02/22 19:24:16 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*get_next_line(int fd)
{
	char		*res;
	static char	*stock = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	stock = ft_get_content(fd, stock);
	if (!stock)
		return (NULL);
	res = ft_get_line(stock);
	if (!res)
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	stock = ft_get_rest_n_free(stock);
	return (res);
}

char	*ft_get_content(int fd, char *stock)
{
	char	buf[BUFFER_SIZE + 1];
	int		c_read;

	buf[0] = '\0';
	c_read = 1;
	while (c_read > 0 && !new_line(buf))
	{
		c_read = read(fd, buf, BUFFER_SIZE);
		if (c_read == -1)
			return (ft_return_n_free(stock));
		buf[c_read] = '\0';
		stock = ft_strjoin_n_free(stock, buf);
		if (!stock)
			return (NULL);
	}
	return (stock);
}

char	*ft_strjoin_n_free(char *stock, char *buf)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = (char *) malloc((ft_strlen(stock) + ft_strlen(buf) + 1));
	if (!res)
		return (ft_return_n_free(stock));
	while (stock && stock[i])
	{
		res[i] = stock[i];
		i++;
	}
	while (buf[j])
		res[i++] = buf[j++];
	res[i] = '\0';
	free(stock);
	if (res[0] == '\0')
		return (ft_return_n_free(res));
	return (res);
}

char	*ft_get_line(char *stock)
{
	int		i;
	int		len;
	char	*res;

	if (!stock)
		return (NULL);
	i = 0;
	len = 0;
	while (stock[len] != '\n' && stock[len])
		len++;
	if (!stock[len])
		len--;
	res = (char *) malloc(len + 2);
	if (!res)
		return (NULL);
	while (stock[i] != '\n' && stock[i])
	{
		res[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*ft_get_rest_n_free(char *stock)
{
	int		i;
	int		pos;
	int		len;
	char	*res;

	if (!stock)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
		return (ft_return_n_free(stock));
	pos = i + 1;
	len = 0;
	while (stock[i++])
		len++;
	res = (char *) malloc(len + 1);
	if (!res)
		return (ft_return_n_free(stock));
	i = 0;
	while (stock[pos])
		res[i++] = stock[pos++];
	res[i] = '\0';
	free(stock);
	return (res);
}
