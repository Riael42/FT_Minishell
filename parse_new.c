/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:28:09 by dwilke            #+#    #+#             */
/*   Updated: 2024/01/08 20:28:12 by dwilke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

t_strs	*parse_arg(t_strs *split, t_pipecommand *pipe, t_strs *args)
{
	if (args->s != NULL)
	{
		args->next = init_strs();
		if (args->next == NULL)
			pipe->malloc_err = 1;
		args = args->next;
	}
	args->s = ft_strdup(split->s);
	return (args);
}

void	parse_commands(t_pipecommand *pipe, t_strs *splits, t_minidat *dat)
{
	t_strs	*args;
	t_strs	*args_head;

	args = init_strs();
	args_head = args;
	while (splits)
	{
		if (splits->s[0] && splits->s[0] == '>')
			splits = parse_out(splits, pipe);
		else if (splits->s[0] && splits->s[0] == '<')
			splits = parse_in(splits, pipe, dat);
		else
			args = parse_arg(splits, pipe, args);
		if (splits)
			splits = splits->next;
	}
	pipe->args = convert(args_head, &pipe);
	set_type(&pipe);
	if (pipe->type == 0)
		check_path(&pipe, dat);
	if (pipe->args[0] == NULL && pipe->out_dir >= 0)
	{
		close(pipe->out_dir);
		pipe->out_dir = -42;
	}
}
