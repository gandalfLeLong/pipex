/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:32:02 by cmathot           #+#    #+#             */
/*   Updated: 2023/10/25 19:08:26 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	checker;
	void	*res;
	char	*tmp;

	checker = count * size;
	if (count != 0 && checker / count != size)
		return (NULL);
	res = malloc(count * size);
	if (res == NULL)
		return (res);
	tmp = res;
	i = 0;
	while (i < count * size)
		tmp[i++] = 0;
	return (res);
}
