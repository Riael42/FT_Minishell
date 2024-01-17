/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_green_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:14:41 by riael             #+#    #+#             */
/*   Updated: 2024/01/16 16:55:00 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_green_echo(int nl, t_minidat *minidat, \
					t_pipecommand *cmd)
{
	int	i;

	i = 1;
	while (ft_is_nn(cmd->args[i]) == 0)
		i += 1;
	while (cmd->args[i] != (void *)0)
	{
		ft_putstr(cmd->args[i]);
		if (cmd->type != -1 && cmd->args[i + 1] != (void *)0)
			ft_putstr(" ");
		i += 1;
	}
	if (nl == 1)
		ft_putstr("\n");
	if (cmd->type == -1)
		minidat->last_exit = -127;
	if (cmd->type == -2)
		minidat->last_exit = -126;
	if (cmd->type == -4)
		minidat->last_exit = 1;
	if (cmd->type > 0)
		minidat->last_exit = 0;
	return (minidat->last_exit);
}
