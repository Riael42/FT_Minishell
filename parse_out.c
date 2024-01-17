/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:27:53 by dwilke            #+#    #+#             */
/*   Updated: 2024/01/08 20:27:57 by dwilke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

t_strs	*parse_out(t_strs *splits, t_pipecommand *pipe)
{
	if (splits->s[1] && splits->s[1] != '>')
		parse_out_new(&(splits->s[1]), pipe);
	else if (splits->s[1] && splits->s[1] == '>' && splits->s[2])
		parse_out_append(&(splits->s[2]), pipe);
	else if (splits->next && splits->s[1] == 0)
	{
		parse_out_new(splits->next->s, pipe);
		return (splits->next);
	}
	else if (splits->next == NULL)
	{
		pipe->out_dir = -5;
		return (splits->next);
	}
	else
	{
		parse_out_append(splits->next->s, pipe);
		return (splits->next);
	}
	return (splits);
}

void	parse_out_append(char *s, t_pipecommand *pipe)
{
	char	*name;

	name = ft_strdup(s);
	if (pipe->out_dir > 0)
		close(pipe->out_dir);
	pipe->out_dir = open(name, O_CREAT | O_RDWR | O_APPEND, 0000600);
	free(name);
}

void	parse_out_new(char *s, t_pipecommand *pipe)
{
	char	*name;

	if (s == NULL)
	{
		pipe->out_dir = -5;
		return ;
	}
	name = ft_strdup(s);
	if (pipe->out_dir > 0)
		close(pipe->out_dir);
	pipe->out_dir = open(name, O_CREAT | O_RDWR, 0000600);
	free(name);
}
