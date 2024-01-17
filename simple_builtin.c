/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:46:02 by riael             #+#    #+#             */
/*   Updated: 2024/01/08 19:16:17 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	simple_builtin(t_minidat *minidat, t_pipecommand *cmd)
{
	int	err;
	int	stdoutb;

	err = 0;
	stdoutb = dup(1);
	cmd->type = get_builtin_type(cmd);
	if (cmd->out_dir != -42 && cmd->out_dir != -1)
		err = dup2(cmd->out_dir, STDOUT_FILENO);
	if (err == -1)
		return (ft_dup_err(minidat));
	minidat->last_exit = bi_exec_builtin(minidat, cmd);
	dup2(stdoutb, 1);
	close(stdoutb);
}
