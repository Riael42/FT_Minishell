/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:33:29 by riael             #+#    #+#             */
/*   Updated: 2024/01/16 17:45:03 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	**ft_get_paths(t_minidat *minidat)
{
	int		i;
	char	**ret;
	char	*str;

	i = 0;
	while (minidat->envp[i] != (void *)0)
	{
		if (ft_strncmp(minidat->envp[i], "PATH=", 5) == 0)
		{
			str = ft_substr(minidat->envp[i], 5, \
							ft_strlen(minidat->envp[i]) - 5);
			ret = ft_split(str, ':');
			free(str);
			return (ret);
		}
		i += 1;
	}
	return ((void *)0);
}
