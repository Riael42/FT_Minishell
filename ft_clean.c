/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:17:51 by riael             #+#    #+#             */
/*   Updated: 2023/12/21 15:19:07 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_clean(t_minidat *minidat, t_pipecommand *cmd)
{
	minidat->iter = 0;
	minidat->cmdnum = 0;
	free_pipe(cmd, minidat);
}
