/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:57:58 by riael             #+#    #+#             */
/*   Updated: 2024/01/08 19:58:56 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	split_command_if(char *s, int *i, char c, t_strs *tmp);
void	split_command_else(char *s, int *i, t_strs *tmp);
t_strs	*split_set_next_strs(t_strs *tmp);

t_strs	*split_command(t_pipecommand **pipe, char *s, t_strs *ret)
{
	t_strs	*tmp;
	int		i;

	if (ret == NULL)
		(*pipe)->malloc_err = 1;
	tmp = ret;
	i = 0;
	while (s[i])
	{
		jump_spaces(s, &i);
		while (s[i] && s[i] != ' ')
		{
			if (s[i] && s[i] == '\'')
				split_command_if(s, &i, '\'', tmp);
			else if (s[i] && s[i] == '"')
				split_command_if(s, &i, '"', tmp);
			else
				split_command_else(s, &i, tmp);
		}
		jump_spaces(s, &i);
		if (s[i])
			tmp = split_set_next_strs(tmp);
	}
	return (ret);
}

void	split_command_if(char *s, int *i, char c, t_strs *tmp)
{
	int	start;

	*i += 1;
	start = *i;
	while (s[*i] && s[*i] != c)
		*i += 1;
	tmp->s = strjoin_se(tmp->s, s, start, *i);
	if (s[*i])
		*i += 1;
}

void	split_command_else(char *s, int *i, t_strs *tmp)
{
	int	start;

	start = *i;
	while (s[*i] && s[*i] != '\'' && s[*i] != '"' && s[*i] != ' ')
		*i += 1;
	tmp->s = strjoin_se(tmp->s, s, start, *i);
}

t_strs	*split_set_next_strs(t_strs *tmp)
{
	t_strs	*new;

	new = malloc(sizeof(t_strs));
	new->s = NULL;
	new->next = NULL;
	tmp->next = new;
	return (new);
}
