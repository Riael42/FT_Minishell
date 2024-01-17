/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clonenvp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:27:20 by riael             #+#    #+#             */
/*   Updated: 2024/01/05 18:59:00 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	**ft_clonenvp(t_minidat *minidat, char **envp)
{
	int		i;
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * (minidat->envlines + 1));
	if (ret == (void *)0)
		return (ft_clonenvp_err(minidat));
	i = 0;
	while (envp[i] != (void *)0)
	{
		ret[i] = ft_strdup(envp[i]);
		if (ret[i] == (void *)0)
			return (ft_clonenvp_err(minidat));
		i += 1;
	}
	ret[i] = (void *)0;
	return (ret);
}
