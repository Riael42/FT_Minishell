/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:53:44 by riael             #+#    #+#             */
/*   Updated: 2023/12/21 15:05:02 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*ft_strchr(char *s, int num)
{
	int		i;
	char	c;

	if (s == ((void *)0))
		return ((void *)0);
	c = (char)num;
	i = -1;
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (s[++i] != '\0')
		if (s[i] == c)
			return ((char *)(s + i));
	return ((void *)0);
}
