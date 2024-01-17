/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:00:32 by riael             #+#    #+#             */
/*   Updated: 2024/01/16 16:54:14 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_wait_bi(t_minidat *minidat, int *oldpipe, int *pipes, int status);

void	bi_child(t_minidat *minidat, int *oldpipe, \
					t_pipecommand *utor, int *pipes)
{
	int	err;

	err = 0;
	if (utor->out_dir == -42 && \
		minidat->iter != minidat->cmdnum - 1 && utor->type != -1)
		err = dup2(pipes[1], STDOUT_FILENO);
	else if (utor->out_dir != -42 && utor->out_dir != -1 && utor->type != -1)
		err = dup2(utor->out_dir, STDOUT_FILENO);
	if (minidat->iter != minidat->cmdnum - 1)
	{
		close(pipes[0]);
		close(pipes[1]);
	}
	close(*oldpipe);
	if (err == -1)
		return (ft_dup_err(minidat));
	err = bi_exec_builtin(minidat, utor);
	free_pipe(minidat->first, minidat);
	exit(err);
}

void	exec_builtins(t_minidat *minidat, int *oldpipe, t_pipecommand *utor)
{
	int	pipes[2];
	int	status;

	status = 0;
	utor->type = get_builtin_type(utor);
	if (utor->type == -42)
		return (ft_alpha_part(minidat));
	if (minidat->iter != minidat->cmdnum - 1)
	{
		if (pipe(pipes) == -1)
			return (ft_pipe_err(minidat)); 
	}
	minidat->forklosophers[minidat->iter] = fork();
	if (minidat->forklosophers[minidat->iter] == -1)
		return (ft_fork_err(minidat));
	if (minidat->forklosophers[minidat->iter] == 0)
		bi_child(minidat, oldpipe, utor, pipes);
	else
		ft_wait_bi(minidat, oldpipe, pipes, status);
}

void	ft_wait_bi(t_minidat *minidat, int *oldpipe, int *pipes, int status)
{
	waitpid(minidat->forklosophers[minidat->iter], &status, 0);
	if (WIFEXITED(status))
		minidat->last_exit = WEXITSTATUS(status);
	else
		minidat->last_exit = 1;
	close(*oldpipe);
	if (minidat->iter != minidat->cmdnum - 1)
		close(pipes[1]);
	if (minidat->iter != minidat->cmdnum - 1)
		*oldpipe = pipes[0];
}
