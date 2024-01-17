/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_envs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:59:07 by riael             #+#    #+#             */
/*   Updated: 2024/01/08 20:07:25 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_is_pos_varname(char c);

void	expand_if(t_ex_data *ex_d)
{
	if (ex_d->start != ex_d->i)
		ex_d->new_line = strjoin_se(ex_d->new_line, 
				ex_d->line, ex_d->start, ex_d->i);
}

char	*expand_envs(char *line, t_minidat *data, t_pipecommand **pipe)
{
	t_ex_data	ex_d;

	init_ex_d(&ex_d, line, data, pipe);
	while (line[ex_d.i])
	{
		if (line[ex_d.i] == '"' && ex_d.i++)
		{
			while (line[ex_d.i] && line[ex_d.i] != '"')
			{
				if (line[ex_d.i] == '$' && ft_is_pos_varname(line[ex_d.i + 1]))
					replace_env_new(&ex_d);
				else
					ex_d.i += 1;
			}
			ex_d.i += 1;
		}
		else if (line[ex_d.i] == '$' && ft_is_pos_varname(line[ex_d.i + 1]))
			replace_env_new(&ex_d);
		else if (line[ex_d.i] == '\'')
			jump_to_next(&ex_d, '\'');
		else
			ex_d.i = ex_d.i + 1;
	}
	expand_if(&ex_d);
	return (ex_d.new_line);
}

int	ft_is_pos_varname(char c)
{
	if (c == 0)
		return (1);
	if (ft_is_onechar(c))
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
