/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:57:38 by riael             #+#    #+#             */
/*   Updated: 2024/01/08 19:57:45 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

t_pipecommand	*init_p(void)
{
	t_pipecommand	*pipe;

	pipe = malloc(sizeof(t_pipecommand));
	pipe->pipe_id = -1;
	pipe->command = NULL;
	pipe->args = NULL;
	pipe->in_dir = -42;
	pipe->in_dir_name = NULL;
	pipe->out_dir = -42;
	pipe->in_op = NULL;
	pipe->type = 0;
	pipe->malloc_err = 0;
	pipe->next = NULL;
	return (pipe);
}
