/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:05:23 by riael             #+#    #+#             */
/*   Updated: 2023/12/19 16:05:39 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	if (s1 == (void *)0 || s2 == (void *)0)
		return (-1);
	if (n == 0)
		return (0);
	if (n >= 1)
		n -= 1;
	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& i < n && (unsigned char)s1[i] != '\0')
		i += 1;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
