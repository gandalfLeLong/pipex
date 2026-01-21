/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot < cmathot@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:36:39 by cmathot           #+#    #+#             */
/*   Updated: 2024/04/02 13:49:49 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_strcpy(char *dst, char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != c && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	res;
	int	flag;

	i = 0;
	res = 0;
	flag = 1;
	while (s[i])
	{
		if (s[i] == c)
			flag = 1;
		else if (flag)
		{
			flag = 0;
			res ++;
		}
		i++;
	}
	return (res);
}

static int	ft_cpy_word(char **res, char *s, char c)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		if (j)
		{
			res[x] = (char *) malloc ((j + 1) * sizeof(char));
			if (res[x] == NULL)
				return (1);
			ft_strcpy(res[x], s + i, c);
		}
		i = i + j;
		j = 0;
		x++;
	}
	return (0);
}

static void	*ft_free(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		nb_word;

	if (!s)
		return (NULL);
	nb_word = ft_count_word(s, c);
	res = NULL;
	res = (char **) malloc((nb_word + 1) * sizeof(char *));
	if (res == NULL)
		return (res);
	if (ft_cpy_word(res, (char *)s, c) == 1)
		return (ft_free(res));
	res[nb_word] = NULL;
	return (res);
}
