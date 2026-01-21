/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:04:22 by cmathot           #+#    #+#             */
/*   Updated: 2023/10/20 12:46:59 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*res;
	unsigned char	uc;

	res = (char *)s + ft_strlen(s);
	uc = (unsigned char) c;
	if (s)
	{
		while (res >= s)
			if (*res-- == uc)
				return (res + 1);
	}
	return (NULL);
}
