/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:35:02 by riael             #+#    #+#             */
/*   Updated: 2023/12/22 16:06:25 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*dest;

	if (!s)
		return ((void *)0);
	i = ft_strlen(s);
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == ((void *)0))
		return ((void *)0);
	dest[i] = '\0';
	while (i > 0)
	{
		dest[i] = s[i];
		i -= 1;
	}
	dest[0] = s[0];
	return (dest);
}
