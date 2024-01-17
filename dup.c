/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:33:26 by riael             #+#    #+#             */
/*   Updated: 2024/01/08 19:21:32 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	dup_stdin(int *oldpipe, t_pipecommand *utor)
{
	int	err;

	err = 0;
	if (utor->in_dir == -42)
		err = dup2(*oldpipe, STDIN_FILENO);
	if (utor->in_dir != -1 && utor->in_dir != -42)
		err = dup2(utor->in_dir, STDIN_FILENO);
	return (err);
}

int	dup_stdout(t_minidat *minidat, int *pipes, t_pipecommand *utor)
{
	int	err;

	err = 0;
	if (utor->out_dir == -42 && utor->out_dir != -1 && \
		minidat->iter != minidat->cmdnum - 1)
		err = dup2(pipes[1], STDOUT_FILENO);
	else if (utor->out_dir != -42 && utor->out_dir != -1)
		err = dup2(utor->out_dir, STDOUT_FILENO);
	return (err);
}
