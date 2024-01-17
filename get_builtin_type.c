/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:48:20 by riael             #+#    #+#             */
/*   Updated: 2024/01/05 21:46:25 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_is_nn(char *str);

int	get_builtin_type(t_pipecommand *cmd)
{
	if (ft_strcmp(cmd->args[0], "cd") == 0)
		return (1);
	if (ft_strcmp(cmd->args[0], "pwd") == 0)
		return (2);
	if (ft_strcmp(cmd->args[0], "export") == 0)
		return (3);
	if (ft_strcmp(cmd->args[0], "unset") == 0)
		return (4);
	if (ft_strcmp(cmd->args[0], "env") == 0)
		return (5);
	if (ft_strcmp(cmd->args[0], "exit") == 0)
		return (6);
	if (ft_strcmp(cmd->args[0], "echo") == 0)
	{
		if (cmd->type == -1 || cmd->type == -2)
			return (cmd->type);
		if (ft_is_nn(cmd->args[1]) == 0)
			return (7);
		else
			return (8);
	}
	return (-42);
}
