/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ex_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:01:06 by riael             #+#    #+#             */
/*   Updated: 2024/01/08 20:01:22 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	init_ex_d(t_ex_data *ex_d, char *line, t_minidat *data, 
t_pipecommand **pipe)
{
	ex_d->i = 0;
	ex_d->start = 0;
	ex_d->line = line;
	ex_d->new_line = NULL;
	ex_d->data = data;
	ex_d->pipe = *pipe;
}
