/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:33:59 by riael             #+#    #+#             */
/*   Updated: 2024/01/16 16:30:49 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	utor_child(t_minidat *minidat, int *oldpipe, \
					t_pipecommand *utor, int *pipes)
{
	int	err;

	err = 0;
	if (minidat->iter != minidat->cmdnum - 1)
		close(pipes[0]);
	err = dup_stdin(oldpipe, utor);
	if (err == -1)
		return (ft_dup_err(minidat));
	close(*oldpipe);
	err = dup_stdout(minidat, pipes, utor);
	if (err == -1)
		return (ft_dup_err(minidat));
	if (minidat->iter != minidat->cmdnum - 1)
		close(pipes[1]);
	err = execve(utor->command, utor->args, minidat->envp);
	if (err == -1)
		return (ft_execve_err(minidat));
}

void	exec_utor(t_minidat *minidat, int *oldpipe, \
					t_pipecommand *utor)
{
	int	pipes[2];

	if (minidat->iter != minidat->cmdnum - 1)
	{
		if (pipe(pipes) == -1)
			return (ft_pipe_err(minidat));
	}
	minidat->forklosophers[minidat->iter] = fork();
	if (minidat->forklosophers[minidat->iter] == -1)
		return (ft_fork_err(minidat));
	if (minidat->forklosophers[minidat->iter] == 0)
		utor_child(minidat, oldpipe, utor, pipes);
	else
	{
		close(*oldpipe);
		if (minidat->iter != minidat->cmdnum - 1)
		{
			close(pipes[1]);
			*oldpipe = pipes[0];
		}
	}
}

void	start_exec(t_minidat *minidat, t_pipecommand *utor)
{
	int	oldpipe;
	int	status;

	minidat->iter = 0;
	oldpipe = dup(0);
	if (oldpipe == -1)
		return (ft_pipe_err(minidat));
	while (minidat->iter < minidat->cmdnum)
	{
		if (utor->type == 0)
			exec_utor(minidat, &oldpipe, utor);
		if (utor->type != 0)
			exec_builtins(minidat, &oldpipe, utor);
		if (utor->next != (void *)0)
			utor = utor->next;
		minidat->iter += 1;
	}
	minidat->iter -= 1;
	while (minidat->iter >= 0)
	{
		waitpid(minidat->forklosophers[minidat->iter], &status, 0);
		if (utor->next == (void *)0 && utor->type == 0)
			ft_set_exit(minidat, status, utor);
		minidat->iter -= 1;
	}
}
