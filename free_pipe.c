/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:18:46 by dwilke            #+#    #+#             */
/*   Updated: 2024/01/05 19:01:18 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_clean_file(t_pipecommand *pipe, t_minidat *minidat);

void	free_pipe(t_pipecommand *pipe, t_minidat *minidat)
{
	t_pipecommand	*tmp;
	int				i;

	while (pipe != NULL)
	{
		tmp = pipe->next;
		if (pipe->command != NULL)
			free(pipe->command);
		if (pipe->args != NULL)
		{
			i = 0;
			while (pipe->args[i] != NULL)
				free(pipe->args[i++]);
			free(pipe->args);
		}
		if (pipe->in_dir_name != NULL)
			free(pipe->in_dir_name);
		if (pipe->in_op != NULL)
			ft_clean_file(pipe, minidat);
		if (pipe != NULL)
			free(pipe);
		pipe = tmp;
	}
}

void	ft_clean_file(t_pipecommand *pipe, t_minidat *minidat)
{
	char	*fp1;
	char	*fp2;

	fp1 = ft_strjoin(minidat->cwd, "/");
	fp2 = ft_strjoin(fp1, pipe->in_op);
	free(fp1);
	unlink(fp2);
	free(fp2);
	free(pipe->in_op);
}
