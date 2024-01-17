/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipecommand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:28:39 by dwilke            #+#    #+#             */
/*   Updated: 2024/01/04 22:28:20 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*get_name(char *s, int start, int end, t_pipecommand **pipe)
{
	char	*name;
	int		i;
	int		j;

	i = start;
	j = 0;
	name = malloc(sizeof(char) * (end - start + 1));
	if (name == NULL)
		(*pipe)->malloc_err = 1;
	while (i < end)
		name[j++] = s[i++];
	name[j] = 0;
	return (name);
}

void	set_start_end(char *s, int *i, int *start, int *end)
{
	char	c;

	if (s[*i] == '\'' || s[*i] == '"')
	{
		c = s[*i];
		(*i)++;
		*start = *i;
		while (s[*i] && s[*i] != c)
			(*i)++;
		*end = *i;
		(*i)++;
		return ;
	}
	*start = *i;
	while (s[*i] && s[*i] != ' ' && s[*i] != '"'
		&& s[*i] != '\'' && s[*i] != '<' && s[*i] != '>')
		(*i)++;
	*end = *i;
}

void	set_type(t_pipecommand **pipe)
{
	t_pipecommand	*tmp;

	tmp = *pipe;
	if (tmp->args[0] == NULL)
	{
		tmp->type = -1;
		return ;
	}
	if (ft_strcmp(tmp->args[0], "echo") == 0)
		tmp->type = 1;
	else if (ft_strcmp(tmp->args[0], "cd") == 0)
		tmp->type = 1;
	else if (ft_strcmp(tmp->args[0], "pwd") == 0)
		tmp->type = 1;
	else if (ft_strcmp(tmp->args[0], "export") == 0)
		tmp->type = 1;
	else if (ft_strcmp(tmp->args[0], "unset") == 0)
		tmp->type = 1;
	else if (ft_strcmp(tmp->args[0], "env") == 0)
		tmp->type = 1;
	else if (ft_strcmp(tmp->args[0], "exit") == 0)
		tmp->type = 1;
}

void	parse_pipecommand(char *s, t_pipecommand **pipe, t_minidat *dat)
{
	int		i;
	t_strs	*args;

	i = 0;
	args = NULL;
	while (s[i])
	{
		if (s[i] == ' ')
			jump_spaces(s, &i);
		else if (s[i] == '>')
			get_out(s, &i, pipe);
		else if (s[i] == '<')
			get_in(s, &i, pipe);
		else
			get_arg(s, &i, &args, pipe);
	}
	(*pipe)->args = convert(args, pipe);
	set_type(pipe);
	if ((*pipe)->type == 0)
		check_path(pipe, dat);
}
