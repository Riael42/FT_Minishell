/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:57:16 by riael             #+#    #+#             */
/*   Updated: 2023/12/19 15:37:36 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int		ft_skip_spaces(char *str);
static void		ft_get_sign(char *str, int *a);
static int		ft_get_result(char *str, int *a);

int	ft_atoi(char *str)
{
	int	a[3];

	if (str == ((void *)0))
		return (0);
	a[2] = ft_skip_spaces(str);
	if (a[2] < 0)
		return (0);
	ft_get_sign(str, a);
	if (a[2] < 0)
		return (0);
	a[0] = ft_get_result(str, a);
	return (a[0] * a[1]);
}

static int	ft_skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i += 1;
	if (str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
		return (i);
	return (-42);
}

static void	ft_get_sign(char *str, int *a)
{
	int	sign;

	sign = 1;
	while (str[a[2]] && (str[a[2]] == '+' || str[a[2]] == '-'))
	{
		if (str[a[2]] == '-')
			sign *= -1;
		a[2] += 1;
		if (!ft_isdigit(str[a[2]]))
		{
			a[2] = -42;
			return ;
		}
	}
	if (str[a[2]] >= '0' && str[a[2]] <= '9')
	{
		a[1] = sign;
		a[0] = 0;
		return ;
	}
	a[2] = -42;
}

static int	ft_get_result(char *str, int *a)
{
	int	result;

	result = 0;
	while (str[a[2]] != '\0' && (str[a[2]] >= '0' && str[a[2]] <= '9'))
	{
		result = result * 10 + (str[a[2]] - '0');
		a[2] += 1;
	}
	return (result);
}
