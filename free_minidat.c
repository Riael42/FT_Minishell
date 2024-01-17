/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_minidat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:33:41 by dwilke            #+#    #+#             */
/*   Updated: 2024/01/05 16:47:15 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	free_minidat(t_minidat *minidat)
{
	int	i;

	if (minidat != NULL)
	{
		if (minidat->paths != NULL)
		{
			i = 0;
			while (minidat->paths[i] != NULL)
				free(minidat->paths[i++]);
			free(minidat->paths);
		}
		if (minidat->owd != NULL)
			free(minidat->owd);
		if (minidat->envp != NULL)
		{
			i = 0;
			while (minidat->envp[i] != NULL)
				free(minidat->envp[i++]);
			free(minidat->envp);
		}
		if (minidat->cwd != NULL)
			free(minidat->cwd);
		if (minidat->curhome != NULL)
			free(minidat->curhome);
	}
}
