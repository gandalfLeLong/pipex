/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:38:44 by cmathot           #+#    #+#             */
/*   Updated: 2023/10/21 16:30:28 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;
	char	uc;

	i = 0;
	res = (char *) s;
	uc = c;
	while (res[i])
	{
		if (res[i] == uc)
			return (res + i);
		i++;
	}
	if (uc == 0)
		return (res + i);
	return (0);
}
