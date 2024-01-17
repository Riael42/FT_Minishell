/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:13:51 by dwilke            #+#    #+#             */
/*   Updated: 2024/01/08 20:05:51 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	check_strs(t_strs *strs);
int	check_syntax(char *s);
int	check_pipes(t_pipecommand *pipe);

int	check_command_new(char *line, t_pipecommand **pipe, t_minidat *data)
{
	char	*expanded_line;
	t_strs	*strs;
	int		test;

	*pipe = init_p();
	if (line[0] == 0)
		return (0);
	expanded_line = expand_envs(line, data, pipe);
	if (check_syntax(expanded_line) == 1)
		return (free(expanded_line), 0);
	strs = split_by(expanded_line, '|', pipe);
	free(expanded_line);
	if (check_strs(strs) == 1)
		return (free_strs(strs), printf("Syntax error\n"), 0);
	test = create_pipes(pipe, data, strs);
	if (test == 1)
		return (free_strs(strs), data->last_exit = 131, 0);
	else if (check_pipes(*pipe) || test == 2)
		return (free_strs(strs), printf("Syntax error\n"), 0);
	data->first = *pipe;
	set_count(&data, pipe);
	free_strs(strs);
	return (1);
}

int	check_strs(t_strs *strs)
{
	int	i;

	while (strs)
	{
		i = 0;
		while (strs->s && strs->s[i] == ' ')
			i++;
		if (strs->s == NULL || strs->s[i] == 0 || strs->s[i] == '|')
			return (1);
		strs = strs->next;
	}
	return (0);
}

int	check_syntax(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
		{
			i++;
			while (s[i] && s[i] != '\'')
				i++;
			if (s[i] == 0)
				return (printf("Syntax error\n"), 1);
		}
		else if (s[i] == '"')
		{
			i++;
			while (s[i] && s[i] != '"')
				i++;
			if (s[i] == 0)
				return (printf("Syntax error\n"), 1);
		}
		i++;
	}
	return (0);
}

int	check_pipes(t_pipecommand *pipe)
{
	while (pipe)
	{
		if (pipe->in_dir == -5 || pipe->out_dir == -5)
			return (1);
		pipe = pipe->next;
	}
	return (0);
}
