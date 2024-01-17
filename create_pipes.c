/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:02:08 by riael             #+#    #+#             */
/*   Updated: 2024/01/08 20:02:20 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	create_pipes(t_pipecommand **pipe, t_minidat *data, t_strs *strs)
{
	t_strs			*splits;
	int				i;
	t_pipecommand	*tmp;

	i = 1;
	tmp = *pipe;
	while (strs != NULL)
	{
		splits = split_command(pipe, strs->s, init_strs());
		if (splits->s[0] == 0)
			return (free_strs(splits), 2);
		tmp->pipe_id = i++;
		parse_commands(tmp, splits, data);
		if (data->last_exit == 130)
			return (free_strs(splits), 1);
		strs = strs->next;
		if (strs != NULL)
		{
			tmp->next = init_p();
			tmp = tmp->next;
		}
		free_strs(splits);
	}
	return (0);
}
