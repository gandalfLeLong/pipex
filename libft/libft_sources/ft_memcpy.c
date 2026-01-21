/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:10:56 by cmathot           #+#    #+#             */
/*   Updated: 2023/10/17 16:35:55 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	if (!dst && !src)
		return (NULL);
	i = 0;
	s1 = dst;
	s2 = (char *) src;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}
