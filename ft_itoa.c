/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:47:55 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/04/27 16:25:06 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digits(int n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static size_t	ft_isminus(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static char	*ft_itoa_malloc(char *dst, size_t digits, size_t is_minus)
{
	if (is_minus == 1)
		dst = (char *)malloc((digits + 2) * sizeof(char));
	else
		dst = (char *)malloc((digits + 1) * sizeof(char));
	return (dst);
}

static void	ft_alloc_digits_to_str(char *dst, long int n, size_t digits)
{
	while (digits > 0)
	{
		digits--;
		dst[digits] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	long int	ln;
	size_t		is_minus;
	size_t		digits;
	char		*str;

	digits = ft_count_digits(n);
	is_minus = ft_isminus(n);
	ln = (long)n;
	str = NULL;
	str = ft_itoa_malloc(str, digits, is_minus);
	if (str == NULL)
		return (NULL);
	if (is_minus == 1)
	{
		digits++;
		ln *= -1;
	}
	str[digits] = '\0';
	ft_alloc_digits_to_str(str, ln, digits);
	if (is_minus == 1)
		str[0] = '-';
	return (str);
}
