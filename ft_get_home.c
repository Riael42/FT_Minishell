/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_home.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:22:11 by riael             #+#    #+#             */
/*   Updated: 2024/01/08 19:22:18 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*ft_get_home(t_minidat *minidat)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	ret = NULL;
	while (minidat->envp[i] != (void *)0)
	{
		if (ft_strncmp(minidat->envp[i], "HOME=", 5) == 0)
		{
			j = ft_strlen(minidat->envp[i]);
			ret = malloc(sizeof(char) * (j + 1));
			j = 5;
			while (minidat->envp[i][j] != '\0')
			{
				ret[j - 5] = minidat->envp[i][j];
				j += 1;
			}
			ret[j - 5] = '\0';
			break ;
		}
		i += 1;
	}
	return (ret);
}
