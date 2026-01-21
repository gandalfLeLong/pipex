/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:33:48 by cmathot           #+#    #+#             */
/*   Updated: 2023/10/21 15:54:27 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *) haystack;
	i = 0;
	if (ft_strlen(needle) == 0)
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while ((str[i + j] == needle[j]) && j + i < len)
		{
			if (needle[j] == '\0')
				return (str + i);
			j++;
		}
		if (needle[j] == '\0')
			return (str + i);
		i++;
	}
	return (NULL);
}
