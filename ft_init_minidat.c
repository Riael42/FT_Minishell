/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_minidat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:22:37 by riael             #+#    #+#             */
/*   Updated: 2024/01/08 19:22:43 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_init_minidat(t_minidat *minidat, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != (void *)0)
		i += 1;
	minidat->envlines = i;
	minidat->cmdnum = 0;
	minidat->envpclone = envp;
	minidat->iter = 0;
	minidat->err = 0;
	minidat->envp = ft_clonenvp(minidat, envp);
	minidat->cwd = ft_get_cwd(minidat);
	minidat->owd = ft_strdup(minidat->cwd);
	minidat->paths = ft_get_paths(minidat);
	minidat->curhome = ft_get_home(minidat);
	minidat->exit = 0;
	minidat->last_exit = 69;
}
