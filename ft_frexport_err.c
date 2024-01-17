/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frexport_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:39:22 by riael             #+#    #+#             */
/*   Updated: 2024/01/05 19:39:35 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_frexport_err(t_minidat *minidat)
{
	int	i;

	i = 0;
	while (minidat->newvp[i] != (void *)0)
	{
		free(minidat->newvp[i]);
		i += 1;
	}
	free(minidat->newvp);
	return (ft_export_err(minidat));
}
