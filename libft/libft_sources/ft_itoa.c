/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:10:17 by cmathot           #+#    #+#             */
/*   Updated: 2023/10/24 14:14:31 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_size(long n)
{
	size_t	i;
	size_t	sign;

	i = 0;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i + sign);
}

static char	*ft_zero(void)
{
	char	*res;

	res = (char *) malloc (sizeof(char) * 2);
	if (!res)
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	long	n_long;
	char	*res;
	size_t	n_size;

	n_long = n;
	if (n_long == 0)
		return (ft_zero());
	n_size = ft_size(n_long);
	res = (char *) malloc ((n_size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (n_long < 0)
	{
		res[0] = '-';
		n_long *= -1;
	}
	res[n_size--] = '\0';
	while (n_long != 0)
	{
		res[n_size] = (n_long % 10) + '0';
		n_long /= 10;
		n_size--;
	}
	return (res);
}
