/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unplug_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:08:07 by riael             #+#    #+#             */
/*   Updated: 2024/01/16 16:54:49 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_inex_cmd(t_minidat *minidat, t_pipecommand *pipe);
void	ft_inac_cmd(t_minidat *minidat, t_pipecommand *pipe);
void	ft_inex_file(t_minidat *minidat, t_pipecommand *pipe);

void	ft_unplug_pipes(t_minidat *minidat, t_pipecommand **incmd)
{
	t_pipecommand	*pipe;

	pipe = *incmd;
	while (pipe != (void *)0)
	{
		if (pipe->type == -1)
			ft_inex_cmd(minidat, pipe);
		if (pipe->type == -2)
			ft_inac_cmd(minidat, pipe);
		if (pipe->in_dir == -1)
		{
			pipe->type = -4;
			ft_inex_file(minidat, pipe);
		}
		pipe = pipe->next;
	}
}

void	ft_inex_file(t_minidat *minidat, t_pipecommand *pipe)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strdup(pipe->args[0]);
	if (s == (void *)0)
		return ;
	while (pipe->args[i])
		free(pipe->args[i++]);
	free(pipe->args);
	pipe->args = (char **)malloc(sizeof(char *) * 3);
	if (pipe->args == (void *)0)
		return (ft_malloc_err(minidat));
	pipe->args[0] = ft_strdup("echo");
	pipe->args[1] = ft_strjoin(s, ": file not found\n");
	pipe->args[2] = (void *)0;
	if (pipe->args[0] == (void *)0 || pipe->args[1] == (void *)0)
		return (ft_malloc_err(minidat));
	if (pipe->next == (void *)0)
		minidat->last_exit = 127;
	free(s);
}

void	ft_inex_cmd(t_minidat *minidat, t_pipecommand *pipe)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strdup(pipe->args[0]);
	if (s == (void *)0)
		return ;
	while (pipe->args[i])
		free(pipe->args[i++]);
	free(pipe->args);
	pipe->args = (char **)malloc(sizeof(char *) * 3);
	if (pipe->args == (void *)0)
		return (ft_malloc_err(minidat));
	pipe->args[0] = ft_strdup("echo");
	pipe->args[1] = ft_strjoin(s, ": command not found\n");
	pipe->args[2] = (void *)0;
	if (pipe->args[0] == (void *)0 || pipe->args[1] == (void *)0)
		return (ft_malloc_err(minidat));
	if (pipe->next == (void *)0)
		minidat->last_exit = 127;
	free(s);
}

void	ft_inac_cmd(t_minidat *minidat, t_pipecommand *pipe)
{
	char	*s;
	int		i;

	s = ft_strdup(pipe->args[0]);
	if (s == (void *)0)
		return ;
	i = 0;
	while (pipe->args[i])
		free(pipe->args[i++]);
	free(pipe->args);
	pipe->args = (char **)malloc(sizeof(char *) * 3);
	if (pipe->args == (void *)0)
		return (ft_malloc_err(minidat));
	pipe->args[0] = ft_strdup("echo");
	pipe->args[1] = ft_strjoin(s, ": permission denied\n");
	pipe->args[2] = (void *)0;
	if (pipe->args[0] == (void *)0 || pipe->args[1] == (void *)0)
		return (ft_malloc_err(minidat));
	if (pipe->next == (void *)0)
		minidat->last_exit = 127;
	free(s);
}
