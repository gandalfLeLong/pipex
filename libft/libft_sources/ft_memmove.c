/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:24:28 by cmathot           #+#    #+#             */
/*   Updated: 2024/03/25 10:10:22 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	if (!dst && !src)
		return (NULL);
	i = -1;
	s1 = dst;
	s2 = (unsigned char *) src;
	if (s2 > s1)
	{
		while (++i < len)
			s1[i] = s2[i];
	}
	else
	{
		while (len-- > 0)
			s1[len] = s2[len];
	}
	return (s1);
}
