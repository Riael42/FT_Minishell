/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:01:12 by dwilke            #+#    #+#             */
/*   Updated: 2023/05/03 10:53:50 by dwilke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	count_digits(int nbr)
{
	int	i;

	i = 0;
	while (nbr / 10)
	{
		nbr /= 10;
		i++;
	}
	return (i + 1);
}

void	get_str_int(long int num, char *str, int *i)
{
	long int	nb;

	nb = (long int) num;
	if (nb < 0)
	{
		str[*i] = '-';
		nb *= -1;
		*i = *i + 1;
	}
	if (nb > 9)
		get_str_int(nb / (long int) 10, str, i);
	str[*i] = (nb % (long int) 10) + '0';
	*i = *i + 1;
}

char	*ft_itoa(int n)
{
	char	*str_int;
	int		i;
	int		nums;

	i = 0;
	nums = 0;
	nums = count_digits(n);
	if (n < 0)
		nums++;
	str_int = malloc(sizeof(char) * nums + 1);
	if (str_int == NULL)
		return (NULL);
	get_str_int((long int) n, str_int, &i);
	str_int[i] = 0;
	return (str_int);
}
