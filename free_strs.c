/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwilke <dwilke@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:19:22 by dwilke            #+#    #+#             */
/*   Updated: 2023/12/19 17:21:00 by dwilke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	free_strs(t_strs *strs)
{
	t_strs	*tmp;

	while (strs != NULL)
	{
		tmp = strs->next;
		if (strs->s != NULL)
			free(strs->s);
		free(strs);
		strs = tmp;
	}
}

void	free_strs_conv(t_strs *strs)
{
	t_strs	*tmp;

	while (strs != NULL)
	{
		tmp = strs->next;
		free(strs);
		strs = tmp;
	}
}
