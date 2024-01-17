/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exec_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:47:51 by riael             #+#    #+#             */
/*   Updated: 2024/01/04 21:48:16 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	bi_exec_builtin(t_minidat *minidat, t_pipecommand *cmd)
{
	if (cmd->type == 1)
		return (ft_green_cd(minidat, cmd));
	if (cmd->type == 2)
		return (ft_green_pwd(minidat));
	if (cmd->type == 3)
		return (ft_green_export(minidat, cmd));
	if (cmd->type == 4)
		return (ft_green_unset(minidat, cmd));
	if (cmd->type == 5)
		return (ft_green_env(minidat));
	if (cmd->type == 6)
		return (ft_green_exit(minidat, cmd));
	if (cmd->type == 7 || cmd->type == -1 || cmd->type == -2)
		return (ft_green_echo(0, minidat, cmd));
	if (cmd->type == 8)
		return (ft_green_echo(1, minidat, cmd));
	ft_alpha_part(minidat);
	return (420);
}
