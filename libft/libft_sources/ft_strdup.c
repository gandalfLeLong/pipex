/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot < cmathot@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:41:34 by cmathot           #+#    #+#             */
/*   Updated: 2023/10/24 13:55:55 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_strcpy(char *src, char *dst)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(const char *s1)
{
	size_t	s_size;
	char	*res;
	char	*tmp;

	s_size = (ft_strlen(s1)) + 1;
	res = NULL;
	res = (char *) malloc (s_size * sizeof(char));
	if (res == NULL)
		return (res);
	tmp = (char *) s1;
	ft_strcpy(tmp, res);
	return (res);
}
