/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:14:13 by riael             #+#    #+#             */
/*   Updated: 2024/01/04 21:12:50 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_cd_err(t_minidat *minidat, t_pipecommand *cmd)
{
	ft_putstr_fd("cd: no such file or directory: ", 2);
	ft_putstr_fd(cmd->args[1], 2);
	ft_putstr_fd("\n", 2);
	minidat->last_exit = -42;
	minidat->err = 1;
	return (1);
}
