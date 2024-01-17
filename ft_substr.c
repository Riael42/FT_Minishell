/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:37:49 by riael             #+#    #+#             */
/*   Updated: 2023/12/21 15:03:54 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*dest;
	int		i;

	if (s == (void *)0)
		return ((void *)0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (dest == (void *)0)
		return ((void *)0);
	i = 0;
	while (s[i + start] != '\0' && i < len)
	{
		dest[i] = s[i + start];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}
