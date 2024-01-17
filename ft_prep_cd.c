/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:19:48 by riael             #+#    #+#             */
/*   Updated: 2024/01/05 17:19:55 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	**ft_prep_cd(t_minidat *minidat, t_pipecommand *incmd)
{
	char	**list;

	if (ft_strcmp(incmd->args[1], "/") == 0)
	{
		list = ft_get_slash(minidat);
		return (list);
	}
	list = ft_split(incmd->args[1], '/');
	if (list != (void *)0)
	{
		if (ft_strcmp(list[0], "home") == 0)
		{
			chdir("/");
			free(minidat->owd);
			minidat->owd = ft_strdup(minidat->cwd);
			free(minidat->cwd);
			minidat->cwd = ft_strdup("/");
			return (list);
		}
	}
	return (list);
}
