/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_to_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:01:35 by riael             #+#    #+#             */
/*   Updated: 2024/01/08 20:08:27 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	jump_to_next(t_ex_data *ex_d, char c)
{
	ex_d->i = ex_d->i + 1;
	while (ex_d->line[ex_d->i] && ex_d->line[ex_d->i] != c)
		ex_d->i = ex_d->i + 1;
	if (ex_d->line[ex_d->i])
		ex_d->i = ex_d->i + 1;
}
