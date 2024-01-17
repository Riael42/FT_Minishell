/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_slash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:36:05 by riael             #+#    #+#             */
/*   Updated: 2024/01/08 19:21:11 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	**ft_get_slash(t_minidat *minidat)
{
	char	**list;

	list = (char **)malloc(sizeof (char *) * 2);
	if (list == (void *)0)
		ft_malloc_err(minidat);
	if (list == (void *)0)
		return ((void *)0);
	list[0] = ft_strdup("/");
	if (list[0] == (void *)0)
		ft_malloc_err(minidat);
	if (list[0] == (void *)0)
		return ((void *)0);
	list[1] = (void *)0;
	return (list);
}
