/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:40:10 by riael             #+#    #+#             */
/*   Updated: 2023/12/19 17:40:57 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while ((unsigned char)s1[i] == (unsigned char)s2[i] \
			&& (unsigned char)s1[i] != '\0')
		i += 1;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
