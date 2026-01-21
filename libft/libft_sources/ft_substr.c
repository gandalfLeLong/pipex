/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:50:25 by cmathot           #+#    #+#             */
/*   Updated: 2023/10/24 13:56:28 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = (ft_strlen(s) - start);
	if (s[0] == '\0' || start >= ft_strlen(s))
		return (ft_strdup(""));
	res = (char *) malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (res);
	i = start;
	j = 0;
	while (s[i] && (j < len))
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}
