/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:03:16 by cmathot           #+#    #+#             */
/*   Updated: 2024/03/30 16:09:35 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_strcpy(char *dst, char const *src, size_t pos)
{
	int	i;

	i = 0;
	if (!src)
		return ;
	while (src[i])
		dst[pos++] = src[i++];
	dst[pos] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*res;

	if (!s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	res = NULL;
	res = (char *) malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (res == NULL)
		return (res);
	ft_strcpy(res, s1, 0);
	ft_strcpy(res, s2, size_s1);
	return (res);
}
