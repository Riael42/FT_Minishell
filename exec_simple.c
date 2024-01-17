/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:19:45 by riael             #+#    #+#             */
/*   Updated: 2024/01/08 19:18:15 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	exec_simple(t_minidat *minidat, t_pipecommand *cmd)
{
	int	status;

	minidat->forklosophers[0] = fork();
	if (minidat->forklosophers[0] == -1)
		return (ft_fork_err(minidat));
	if (minidat->forklosophers[0] == 0)
		simple_child(minidat, cmd);
	else
	{
		waitpid(minidat->forklosophers[0], &status, 0);
		if (WIFEXITED(status) && minidat->last_exit != 131)
			minidat->last_exit = WEXITSTATUS(status);
		else
			if (minidat->last_exit != 131)
				minidat->last_exit = 1;
	}
}

void	simple_child(t_minidat *minidat, t_pipecommand *utor)
{
	int	err;

	err = 0;
	if (utor->in_dir != -42 && utor->in_dir != -1)
		err = dup2(utor->in_dir, STDIN_FILENO);
	if (err == -1)
		return (ft_dup_err(minidat)); 
	if (utor->out_dir != -42 && utor->out_dir != -1)
		err = dup2(utor->out_dir, STDOUT_FILENO);
	if (err == -1)
		return (ft_dup_err(minidat));
	if (utor->type == 0)
		err = execve(utor->command, utor->args, minidat->envp);
}
